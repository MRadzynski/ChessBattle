#include "player.h"

Player::Player(PieceColor _color): color(_color) {};

void Player::makeMove(int posX, int posY) {

}

PieceColor Player::getColor() {
    return this->color;
}

void Player::setColor(PieceColor color) {
    this->color = color;
}
