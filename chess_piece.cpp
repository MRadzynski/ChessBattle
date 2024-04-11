#include "chess_piece.h"

ChessPiece::ChessPiece(PieceColor _color, int _posX, int _posY, QString _iconPath, std::string _name) : color(_color), posX(_posX), posY(_posY), iconPath(_iconPath), name(_name) {};

ChessPiece::~ChessPiece() {};

PieceColor ChessPiece::getColor() {
    return this->color;
}

QString ChessPiece::getIconPath() {
    return this->iconPath;
}

std::string ChessPiece::getName() {
    return this->name;
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

void ChessPiece::setIconPath(QString iconPath) {
    this->iconPath = iconPath;
}

void ChessPiece::setName(std::string name) {
    this->name = name;
}

void ChessPiece::setPosX(int posX) {
    this->posX = posX;
}

void ChessPiece::setPosY(int posY) {
    this->posY = posY;
}
