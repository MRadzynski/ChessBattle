#include "chess_piece.h"

ChessPiece::ChessPiece(PieceColor _color, int _posX, int _posY) : color(_color), posX(_posX), posY(_posY) {}

PieceColor ChessPiece::getColor() {
    return this->color;
}

int ChessPiece::getPosX() {
    return this->posX;
}

int ChessPiece::getPosY() {
    return this->posY;
}

void ChessPiece::setColor(PieceColor color) {
    this->color = color;
}

void ChessPiece::setPosX(int posX) {
    this->posX = posX;
}

void ChessPiece::setPosY(int posX) {
    this->posX = posX;
}
