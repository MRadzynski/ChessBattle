#include "king.h"

#include <QDebug>

King::King(PieceColor color, int posX, int posY, QString iconPath, std::string name): ChessPiece(color, posX, posY, iconPath, name){};

bool King::isValidMove(int potentialPosX, int potentialPosY,  const std::vector<std::vector<ChessPiece*>>& board, PieceColor playerColor) {
    if(board[potentialPosX][potentialPosY] != nullptr) {
        qDebug() << "Piece: "<<board[potentialPosX][potentialPosY]->getName() << " X: "<<potentialPosX<< " Y: "<<potentialPosY;
    }

    struct movement {
        int x;
        int y;
    };
    std::vector<movement> possibleMoves;

    for(int row = -1; row < 2; row++) {
        for(int col = -1; col < 2; col++) {
            if(this->getPosX()+row < 8 && this->getPosX()+row > -1 && this->getPosY()+col < 8 && this->getPosY()+col > -1) {
                if(board[this->getPosX()+row][this->getPosY()+col] != nullptr && board[this->getPosX()+row][this->getPosY()+col]->getColor() == playerColor) {
                    continue;
                } else {
                    possibleMoves.push_back({this->getPosX()+row, this->getPosY()+col});
                }
            }
        }
    }

    std::vector<movement> restrictedMoves;

    PieceColor oppositePlayer = PieceColor::BLACK;

    if(playerColor == oppositePlayer) {
        oppositePlayer = PieceColor::WHITE;
    }

    //TODO: make the expection for the king piece
    for (auto& row : board) {
        for (auto& piece : row) {
            if(piece == nullptr || piece->getColor() == playerColor || piece == this || piece->getName() == "BKG" || piece->getName() == "WKG") {
                continue;
            } else {
                for (auto& possibleMove : possibleMoves) {
                    bool isValidMove = piece->isValidMove(possibleMove.x, possibleMove.y, board, oppositePlayer);

                    if(isValidMove) {
                        restrictedMoves.push_back({possibleMove.x, possibleMove.y});
                    }
                }
            }
        }
    }

    std::vector<movement> availableMoves;

    for(auto& possibleMove : possibleMoves) {
        bool foundInRestrictedMoves = false;

        for(auto& restrictedMove : restrictedMoves) {
            if(possibleMove.x == restrictedMove.x && possibleMove.y == restrictedMove.y) {
                foundInRestrictedMoves = true;
            }
        }

        if(!foundInRestrictedMoves) {
            availableMoves.push_back(possibleMove);
        }
    }

    for(auto& availableMove : availableMoves) {
        if(availableMove.x == potentialPosX && availableMove.y == potentialPosY) {
            return true;
        }
    }

    return false;
}
