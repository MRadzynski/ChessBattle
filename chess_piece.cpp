#include "chess_piece.h"

ChessPiece::ChessPiece(PieceColor _color, int _posX, int _posY, QString _iconPath) : color(_color), posX(_posX), posY(_posY), iconPath(_iconPath) {}

PieceColor ChessPiece::getColor() {
    return this->color;
}

int ChessPiece::getPosX() {
    return this->posX;
}

int ChessPiece::getPosY() {
    return this->posY;
}

QString ChessPiece::getIconPath() {
    return this->iconPath;
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

void ChessPiece::setIconPath(QString iconPath) {
    this->iconPath = iconPath;
}
