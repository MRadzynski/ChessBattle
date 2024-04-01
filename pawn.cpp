#include "pawn.h"
#include "piece_color.h"

#include <QDebug>

Pawn::Pawn(PieceColor color, int posX, int posY, QString iconPath, std::string name): ChessPiece(color, posX, posY, iconPath, name){
    this->initPosX = posX;
    this->initPosY = posY;
};

bool Pawn::isValidMove(int potentialMoveX, int potentialMoveY,  const std::vector<std::vector<ChessPiece*>>& board) {
    int playerMoveDirection = 1;

    if(this->getColor() == PieceColor::WHITE) {
        playerMoveDirection = -1;
    }

    if(this->getPosX() == this->getInitPosX() && this->getPosY() == this->getInitPosY()) {
        if(((potentialMoveX == this->getPosX()+playerMoveDirection && potentialMoveY == this->getPosY()) || (potentialMoveX == this->getPosX()+(playerMoveDirection*2) && potentialMoveY == this->getPosY())) && board[potentialMoveX][potentialMoveY] == nullptr) {
            return true;
        } else {
            return false;
        }
    } else {
        if(potentialMoveX == this->getPosX()+playerMoveDirection && potentialMoveY == this->getPosY() && board[potentialMoveX][potentialMoveY] == nullptr) {
            return true;
        } else {
            return false;
        }
    }
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
