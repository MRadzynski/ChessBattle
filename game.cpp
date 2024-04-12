#include "game.h"
#include "promotion_dialog.h"
#include "bishop.h"
#include "knight.h"
#include "queen.h"
#include "rook.h"

#include <string>
#include <QDebug>

Game::Game() {
    std::vector<Player*> players;
    ChessBoard* chessBoard = new ChessBoard();
    Player* blackPlayer = new Player(PieceColor::BLACK, QString("Player 1"));
    Player* whitePlayer = new Player(PieceColor::WHITE, QString("Player 2"));
    Player* winner = nullptr;
    MovesHistory* movesHistory = new MovesHistory();

    players.push_back(blackPlayer);
    players.push_back(whitePlayer);

    this->chessBoard = chessBoard;
    this->currentPlayer = whitePlayer;
    this->players = players;
    this->winner = winner;
    this->movesHistory = movesHistory;
}

void Game::endGame() {
    this->setWinner(this->getCurrentPlayer());
    this->getPlayers()[0]->getTimer()->pauseTimer();
    this->getPlayers()[1]->getTimer()->pauseTimer();

    this->getChessBoard()->setSelectedPiece(nullptr);

    emit gameEnded();
}

QString Game::getChessBoardCoords(int posX, int posY) {
    int finalXCoord = 8 - posX;
    QString finalCoords;

    switch(posY) {
        case 0:
            finalCoords += "A";
            break;
        case 1:
            finalCoords += "B";
            break;
        case 2:
            finalCoords += "C";
            break;
        case 3:
            finalCoords += "D";
            break;
        case 4:
            finalCoords += "E";
            break;
        case 5:
            finalCoords += "F";
            break;
        case 6:
            finalCoords += "G";
            break;
        case 7:
            finalCoords += "H";
            break;
    }

    finalCoords += QString::number(finalXCoord);

    return finalCoords;
}

void Game::initGame() {
    this->getChessBoard()->initializeChessBoard();
}

ChessPiece* Game::isCheck(ChessPiece* king) {
    std::vector<std::vector<ChessPiece*>> board = this->getChessBoard()->getChessBoardState();
    std::string oppositeColor = "B";
    PieceColor oppositePieceColor = PieceColor::BLACK;

    if(king->getColor() == PieceColor::BLACK) {
        oppositeColor = "W";
        oppositePieceColor = PieceColor::WHITE;
    }

    for (auto& row : board) {
        for (auto& piece : row) {
            if(piece == nullptr || piece->getColor() == king->getColor() || piece == king || piece->getName() == oppositeColor+"KG") {
                continue;
            } else {
                if(piece->getName() == oppositeColor+"PN") {
                    if(oppositeColor == "W") {
                        if(piece->getPosX()-1 > -1 && piece->getPosX()-1 == king->getPosX() && (piece->getPosY()-1 > -1 && piece->getPosY()-1 == king->getPosY() || piece->getPosY()+1 < 8 && piece->getPosY()+1 == king->getPosY())) {
                            return piece;
                        }
                    } else {
                        if(piece->getPosX()+1 < 8 && piece->getPosX()+1 == king->getPosX() && (piece->getPosY()-1 > -1 && piece->getPosY()-1 == king->getPosY() || piece->getPosY()+1 < 8 && piece->getPosY()+1 == king->getPosY())) {
                            return piece;
                        }
                    }
                } else {
                    bool isValidMove = piece->isValidMove(king->getPosX(), king->getPosY(), board, oppositePieceColor);

                    if(isValidMove) {
                        return piece;
                    }
                }
            }
        }
    }

    return nullptr;
}

std::vector<Game::Movement> Game::isCheckmate(ChessPiece* king) {
    std::vector<std::vector<ChessPiece*>> board = this->getChessBoard()->getChessBoardState();
    PieceColor kingColor = king->getColor();
    ChessPiece* checkingPiece = isCheck(king);

    std::vector<Game::Movement> possibleMoves;

    if(checkingPiece == nullptr) {
        return possibleMoves;
    }

    qDebug()<<"xd" << checkingPiece->getName();

    // Check all possible moves of all pieces of the king's color
    int originalPosX = king->getPosX();
    int originalPosY = king->getPosY();

    // Check for king possbile moves to avoid checkmate
    for (int row = -1; row <= 1; ++row) {
        for (int col = -1; col <= 1; ++col) {
            if (row == 0 && col == 0)
                continue;

            int posX = king->getPosX() + row;
            int posY = king->getPosY() + col;

            if (posX >= 0 && posX < 8 && posY >= 0 && posY < 8) {
                bool isValidMove = king->isValidMove(posX,posY, board, king->getColor());

                if(isValidMove) {
                    king->setPosX(posX);
                    king->setPosY(posY);

                    ChessPiece* pieceOnBoardPlace = board[posX][posY];

                    board[originalPosX][originalPosY] = nullptr;
                    board[posX][posY] = king;
                    this->getChessBoard()->setChessBoardState(board);

                    ChessPiece* newCheckingPiece = isCheck(king);

                    king->setPosX(originalPosX);
                    king->setPosY(originalPosY);
                    board[originalPosX][originalPosY] = king;
                    board[posX][posY] = pieceOnBoardPlace;
                    this->getChessBoard()->setChessBoardState(board);

                    if(newCheckingPiece == nullptr) {
                        possibleMoves.push_back({posX, posY});
                    }
                }
            }
        }
    }

    qDebug() << "Kings possible moves: ";
    for(auto& move : possibleMoves) {
        qDebug()<< "Move X: " << move.x << " Move Y: "<< move.y;
    }

    // Check for other pieces moves to prevent checkmate

    for (auto row : board) {
        for (auto piece : row) {
            if(piece == nullptr || piece->getColor() != kingColor || piece == king) {
                continue;
            }
            qDebug() << piece->getName();

            // Save the current position of the piece
            int oriPosX = piece->getPosX();
            int oriPosY = piece->getPosY();

            // Check all possible moves of the piece
            for(int potentialPosX = 0; potentialPosX < 8; potentialPosX++) {
                for(int potentialPosY = 0; potentialPosY < 8; potentialPosY++) {
                    if(potentialPosX == oriPosX && potentialPosY == oriPosY) {
                        continue;
                    }

                    if(piece->isValidMove(potentialPosX, potentialPosY, board, kingColor)) {
                        // Move the piece
                        piece->setPosX(potentialPosX);
                        piece->setPosY(potentialPosY);

                        ChessPiece* pieceOnBoardPlace = board[potentialPosX][potentialPosY];

                        board[oriPosX][oriPosY] = nullptr;
                        board[potentialPosX][potentialPosY] = piece;
                        this->getChessBoard()->setChessBoardState(board);

                        ChessPiece* newCheckingPiece = isCheck(king);

                        piece->setPosX(oriPosX);
                        piece->setPosY(oriPosY);
                        board[oriPosX][oriPosY] = piece;
                        board[potentialPosX][potentialPosY] = pieceOnBoardPlace;
                        this->getChessBoard()->setChessBoardState(board);

                        if(newCheckingPiece == nullptr) {
                            bool isNewMove = true;

                            for(auto move : possibleMoves) {
                                if(move.x == potentialPosX && move.y == potentialPosY) {
                                    isNewMove = false;
                                    break;
                                }
                            }

                            if(isNewMove) {
                                possibleMoves.push_back({potentialPosX, potentialPosY});
                            }
                        }
                    }
                }
            }
        }
    }

    qDebug() << "All possible moves: ";
    for(auto& move : possibleMoves) {
        qDebug()<< "Move X: " << move.x << " Move Y: "<< move.y;
    }

    // If no move can get the king out of check, it is checkmate
    return possibleMoves;
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

        if(selectedPiece->getPosX() == row && selectedPiece->getPosY() == col) {
            this->getChessBoard()->setSelectedPiece(nullptr);
            return;
        }

        ChessPiece* playerKingPiece = nullptr;

        for(auto& row : this->getChessBoard()->getChessBoardState()) {
            for(auto& piece : row) {
                if(piece != nullptr && piece->getColor() == this->getCurrentPlayer()->getColor() && piece->getName().find("KG") != std::string::npos) {
                    playerKingPiece = piece;
                    break;
                }
            }
        }

        if(isCheck(playerKingPiece)) {
            qDebug() << playerKingPiece->getName() << " is checked";
            std::vector<Game::Movement> possibleMoves = isCheckmate(playerKingPiece);
            std::vector<Game::Movement> piecePossibleMoves;

            if(possibleMoves.empty()) {
                this->endGame();
                return;
            }

            for(auto possibleMove : possibleMoves) {
                if(selectedPiece->isValidMove(possibleMove.x, possibleMove.y, this->getChessBoard()->getChessBoardState(), this->getCurrentPlayer()->getColor())) {
                    piecePossibleMoves.push_back(possibleMove);
                }
            }

            qDebug() << "Piece moves:";
            for(auto pieceMove : piecePossibleMoves) {
                qDebug() << "X: " <<pieceMove.x << " Y: "<<pieceMove.y;
            }

            bool pieceCanMove = false;

            for(auto pieceMove : piecePossibleMoves) {
                if(pieceMove.x == row && pieceMove.y == col) {
                    pieceCanMove = true;
                }
            }

            if(pieceCanMove) {
                int selectedPiecePosX = selectedPiece->getPosX();
                int selectedPiecePosY = selectedPiece->getPosY();

                std::vector<std::vector<ChessPiece*>> newChessBoardState = this->getChessBoard()->getChessBoardState();

                selectedPiece->setPosX(row);
                selectedPiece->setPosY(col);
                newChessBoardState[selectedPiecePosX][selectedPiecePosY] = nullptr;

                if(newChessBoardState[row][col] != nullptr) {
                    delete newChessBoardState[row][col];
                }

                HistoryLog* historyMove = new HistoryLog();
                historyMove->pieceIcon = selectedPiece->getIconPath();
                historyMove->posBefore = this->getChessBoardCoords(selectedPiecePosX, selectedPiecePosY);
                historyMove->posAfter = this->getChessBoardCoords(row, col);

                if(row == 0 && selectedPiece->getName() == "WPN" || row == 7 && selectedPiece->getName() == "BPN") {
                    ChessPiece* promotedPiece = this->promotePawn(selectedPiece);
                    newChessBoardState[row][col] = promotedPiece;
                } else {
                    newChessBoardState[row][col] = selectedPiece;
                }

                this->getMovesHistory()->addNewLog(historyMove);
                this->getChessBoard()->setChessBoardState(newChessBoardState);
                this->getChessBoard()->setSelectedPiece(nullptr);
                this->switchPlayer();

            }

            return;
        } else {
            bool isValidMove = selectedPiece->isValidMove(row, col, this->getChessBoard()->getChessBoardState(), this->getCurrentPlayer()->getColor());

            if(isValidMove) {
                int selectedPiecePosX = selectedPiece->getPosX();
                int selectedPiecePosY = selectedPiece->getPosY();
                std::vector<std::vector<ChessPiece*>> newChessBoardState = this->getChessBoard()->getChessBoardState();

                selectedPiece->setPosX(row);
                selectedPiece->setPosY(col);
                newChessBoardState[selectedPiecePosX][selectedPiecePosY] = nullptr;

                if(newChessBoardState[row][col] != nullptr) {
                    if(newChessBoardState[row][col]->getName() == "BKG" || newChessBoardState[row][col]->getName() == "WKG") {
                        this->endGame();
                        return;
                    }
                    delete newChessBoardState[row][col];
                }

                HistoryLog* historyMove = new HistoryLog();
                historyMove->pieceIcon = selectedPiece->getIconPath();
                historyMove->posBefore = this->getChessBoardCoords(selectedPiecePosX, selectedPiecePosY);
                historyMove->posAfter = this->getChessBoardCoords(row, col);

                if(row == 0 && selectedPiece->getName() == "WPN" || row == 7 && selectedPiece->getName() == "BPN") {
                    ChessPiece* promotedPiece = this->promotePawn(selectedPiece);
                    newChessBoardState[row][col] = promotedPiece;
                } else {
                    newChessBoardState[row][col] = selectedPiece;
                }

                this->getMovesHistory()->addNewLog(historyMove);
                this->getChessBoard()->setChessBoardState(newChessBoardState);
                this->getChessBoard()->setSelectedPiece(nullptr);
                this->switchPlayer();

                ChessPiece* kingPiece = nullptr;

                for(auto& row : this->getChessBoard()->getChessBoardState()) {
                    for(auto& piece : row) {
                        if(piece != nullptr && piece->getColor() == this->getCurrentPlayer()->getColor() && piece->getName().find("KG") != std::string::npos) {
                            kingPiece = piece;
                            break;
                        }
                    }
                }

                qDebug()<< kingPiece->getName();
                if(isCheck(kingPiece)) {
                    std::vector<Game::Movement> possibleMovements = isCheckmate(kingPiece);

                    if(possibleMovements.empty()) {
                        this->endGame();
                    }
                }
            }
        }
    }
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
    this->getMovesHistory()->clearHistoryLogs();
}

void Game::surrender() {
    Player* winner;

    if(this->currentPlayer->getColor() == PieceColor::BLACK) {
        winner = this->getPlayers()[1];
    } else {
        winner = this->getPlayers()[0];
    }

    this->getChessBoard()->setSelectedPiece(nullptr);
    this->setWinner(winner);
    this->getPlayers()[0]->getTimer()->pauseTimer();
    this->getPlayers()[1]->getTimer()->pauseTimer();
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

ChessBoard* Game::getChessBoard() {
    return this->chessBoard;
}

Player* Game::getCurrentPlayer() {
    return this->currentPlayer;
}

MovesHistory* Game::getMovesHistory() {
    return this->movesHistory;
}

std::vector<Player*> Game::getPlayers() {
    return this->players;
}

Player* Game::getWinner() {
    return this->winner;
}

void Game::setChessBoard(ChessBoard* chessBoard) {
    this->chessBoard = chessBoard;
}

void Game::setCurrentPlayer(Player* currentPlayer) {
    this->currentPlayer = currentPlayer;
}

void Game::setMovesHistory(MovesHistory* movesHistory) {
    this->movesHistory = movesHistory;
}

void Game::setPlayers(std::vector<Player*> players) {
    this->players = players;
}

void Game::setWinner(Player* winner) {
    this->winner = winner;
}
