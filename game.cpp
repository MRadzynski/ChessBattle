#include "game.h"
#include "promotion_dialog.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "queen.h"

#include <QDebug>

Game::Game() {
    std::vector<Player*> players;
    ChessBoard* chessBoard = new ChessBoard();
    Player* blackPlayer = new Player(PieceColor::BLACK);
    Player* whitePlayer = new Player(PieceColor::WHITE);
    Player* winner = nullptr;

    players.push_back(blackPlayer);
    players.push_back(whitePlayer);

    this->chessBoard = chessBoard;
    this->currentPlayer = whitePlayer;
    this->players = players;
    this->winner = winner;
}

void Game::initGame() {
    this->getChessBoard()->initializeChessBoard();
}

void Game::restartGame() {
    std::vector<std::vector<ChessPiece*>> chessBoard = this->getChessBoard()->getChessBoardState();

    for(int row = 0; row < 8; row++) {
        for(int col = 0; col < 8; col++) {
            if(chessBoard[row][col] != nullptr) {
                delete chessBoard[row][col];
                chessBoard[row][col] = nullptr;
            }
        }
    }

    this->getChessBoard()->setSelectedPiece(nullptr);
    this->getChessBoard()->setChessBoardState(chessBoard);
    this->getChessBoard()->initializeChessBoard();

    this->setWinner(nullptr);
    this->setCurrentPlayer(this->players[1]);
    this->getPlayers()[0]->getTimer()->resetTimer();
    this->getPlayers()[1]->getTimer()->resetTimer();
}

void Game::surrender() {
    Player* winner;

    if(this->currentPlayer->getColor() == PieceColor::BLACK) {
        winner = this->players[1];
    } else {
        winner = this->players[0];
    }

    this->getChessBoard()->setSelectedPiece(nullptr);
    this->setWinner(winner);
}

void Game::endGame() {

}

void Game::playTurn(Player* player) {
    this->setCurrentPlayer(player);
}

ChessPiece* Game::promotePawn(ChessPiece* selectedPiece) {
    QString color = "black";
    std::string colorLetter = "B";

    if(selectedPiece->getColor() == PieceColor::WHITE){
        color = "white";
        colorLetter = "W";
    }

    PromotionDialog promotionDialog(color, nullptr);
    if (promotionDialog.exec() == QDialog::Accepted) {
        QString pieceType = promotionDialog.getSelectedOption();

        ChessPiece* promotedPiece;

        if(pieceType == "rook") {
            promotedPiece = new Rook(selectedPiece->getColor(), selectedPiece->getPosX(), selectedPiece->getPosY(), ":/images/assets/rook_"+color+".png", colorLetter+"RK");
        } else if(pieceType == "bishop") {
            promotedPiece = new Bishop(selectedPiece->getColor(), selectedPiece->getPosX(), selectedPiece->getPosY(), ":/images/assets/bishop_"+color+".png", colorLetter+"BP");
        } else if(pieceType == "knight") {
            promotedPiece = new Knight(selectedPiece->getColor(), selectedPiece->getPosX(), selectedPiece->getPosY(), ":/images/assets/knight_"+color+".png", colorLetter+"KT");
        } else {
            promotedPiece = new Queen(selectedPiece->getColor(), selectedPiece->getPosX(), selectedPiece->getPosY(), ":/images/assets/queen_"+color+".png", colorLetter+"QN");
        }

        delete selectedPiece;

        return promotedPiece;
    }

    return selectedPiece;
}

void Game::switchPlayer() {
    if(this->currentPlayer->getColor() == PieceColor::WHITE) {
        this->setCurrentPlayer(this->getPlayers()[0]);
        this->getPlayers()[1]->getTimer()->pauseTimer();
        this->getPlayers()[0]->getTimer()->startTimer();
    } else {
        this->setCurrentPlayer(this->getPlayers()[1]);
        this->getPlayers()[0]->getTimer()->pauseTimer();
        this->getPlayers()[1]->getTimer()->startTimer();
    }
}

void Game::makeMove(int row, int col) {
    if(this->getWinner() != nullptr) return;

    if(this->getChessBoard()->getSelectedPiece() == nullptr) {
        if(this->getChessBoard()->getChessBoardState()[row][col] != nullptr && this->getChessBoard()->getChessBoardState()[row][col]->getColor() == this->currentPlayer->getColor()) {
            ChessPiece* selectedPiece = this->getChessBoard()->getChessBoardState()[row][col];
            this->getChessBoard()->setSelectedPiece(selectedPiece);
        }
    } else {
        ChessPiece* selectedPiece = this->getChessBoard()->getSelectedPiece();

        bool isValidMove = selectedPiece->isValidMove(row, col, this->getChessBoard()->getChessBoardState(), this->currentPlayer->getColor());

        if(isValidMove) {
            int selectedPiecePosX = selectedPiece->getPosX();
            int selectedPiecePosY = selectedPiece->getPosY();
            std::vector<std::vector<ChessPiece*>> newChessBoardState = this->getChessBoard()->getChessBoardState();

            selectedPiece->setPosX(row);
            selectedPiece->setPosY(col);
            newChessBoardState[selectedPiecePosX][selectedPiecePosY] = nullptr;

            if(row == 0 && selectedPiece->getName() == "WPN" || row == 7 && selectedPiece->getName() == "BPN") {
                ChessPiece* promotedPiece = this->promotePawn(selectedPiece);
                newChessBoardState[row][col] = promotedPiece;
            } else {
                newChessBoardState[row][col] = selectedPiece;
            }

            this->getChessBoard()->setChessBoardState(newChessBoardState);
            this->getChessBoard()->setSelectedPiece(nullptr);
            this->switchPlayer();
        } else {
            this->getChessBoard()->setSelectedPiece(nullptr);
        }
    }

    this->getChessBoard()->displayChessBoardState();
}

Player* Game::getCurrentPlayer() {
    return this->currentPlayer;
}

ChessBoard* Game::getChessBoard() {
    return this->chessBoard;
}

std::vector<Player*> Game::getPlayers() {
    return this->players;
}

Player* Game::getWinner() {
    return this->winner;
}

void Game::setCurrentPlayer(Player* currentPlayer) {
    this->currentPlayer = currentPlayer;
}

void Game::setChessBoard(ChessBoard* chessBoard) {
    this->chessBoard = chessBoard;
}

void Game::setWinner(Player* winner) {
    this->winner = winner;
}

void Game::setPlayers(std::vector<Player*> players) {
    this->players = players;
}

