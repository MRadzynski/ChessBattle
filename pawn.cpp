#include "pawn.h"
#include "piece_color.h"

Pawn::Pawn(PieceColor color, int posX, int posY, QString iconPath, std::string name) : ChessPiece(color, posX, posY, iconPath, name) {
    this->initPosX = posX;
    this->initPosY = posY;
};

bool Pawn::isValidMove(int potentialPosX, int potentialPosY,  const std::vector<std::vector<ChessPiece*>>& board, PieceColor playerColor) {
    struct movement {
        int x;
        int y;
    };
    std::vector<movement> possibleMoves;

    int playerMoveDirection = 1;

    if(this->getColor() == PieceColor::WHITE) {
        playerMoveDirection = -1;
    }

    for(int col = -1; col < 2; col++) {
        int pieceNextRow = this->getPosX()+playerMoveDirection;
        int pieceNextCol = this->getPosY()+col;

        if(pieceNextRow > -1 && pieceNextRow < 8 && pieceNextCol > -1 && pieceNextCol < 8) {
            if(col == 0) {
                if(board[pieceNextRow][pieceNextCol] == nullptr) {
                    possibleMoves.push_back({pieceNextRow, pieceNextCol});
                }
            } else {
                if(board[pieceNextRow][pieceNextCol] != nullptr && board[pieceNextRow][pieceNextCol]->getColor() != playerColor) {
                    possibleMoves.push_back({pieceNextRow, pieceNextCol});
                }
            }
        }
    }

    if(this->getPosX() == this->getInitPosX() && this->getPosY() == this->getInitPosY()) {
        if(potentialPosY == this->getPosY() && (potentialPosX == this->getPosX()+playerMoveDirection || potentialPosX == this->getPosX()+(playerMoveDirection*2)) && board[this->getPosX()+playerMoveDirection][potentialPosY] == nullptr && board[this->getPosX()+(playerMoveDirection*2)][potentialPosY] == nullptr) {
            possibleMoves.push_back({this->getPosX()+(playerMoveDirection*2), this->getPosY()});
        }
    }

    for(auto possibleMove : possibleMoves) {
        if(possibleMove.x == potentialPosX && possibleMove.y == potentialPosY) {
            return true;
        }
    }

    return false;
};

int Pawn::getInitPosX() {
    return this->initPosX;
}

int Pawn::getInitPosY() {
    return this->initPosY;
}

void Pawn::setInitPosX(int initPosX) {
    this->initPosX = initPosX;
}

void Pawn::setInitPosY(int initPosY) {
    this->initPosY = initPosY;
}
