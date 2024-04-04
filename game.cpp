#include "game.h"

#include <QDebug>

Game::Game() {
    std::vector<Player*> players;
    Player* blackPlayer = new Player(PieceColor::BLACK);
    Player* whitePlayer = new Player(PieceColor::WHITE);

    players.push_back(blackPlayer);
    players.push_back(whitePlayer);

    ChessBoard* chessBoard = new ChessBoard();

    this->chessBoard = chessBoard;
    this->currentPlayer = whitePlayer;
    this->players = players;
}

void Game::initGame() {
    this->getChessBoard()->initializeChessBoard();
}

void Game::restartGame() {

}

void Game::endGame() {

}

void Game::playTurn(Player* player) {
    this->setCurrentPlayer(player);
}

void Game::promotePawn() {

}

void Game::switchPlayer() {
    if(this->currentPlayer->getColor() == PieceColor::WHITE) {
        this->setCurrentPlayer(this->getPlayers()[0]);
    } else {
        this->setCurrentPlayer(this->getPlayers()[1]);
    }
}

void Game::makeMove(int row, int col) {
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
            newChessBoardState[row][col] = selectedPiece;

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

void Game::setCurrentPlayer(Player* currentPlayer) {
    this->currentPlayer = currentPlayer;
}

void Game::setChessBoard(ChessBoard* chessBoard) {
    this->chessBoard = chessBoard;
}

void Game::setPlayers(std::vector<Player*> players) {
    this->players = players;
}

