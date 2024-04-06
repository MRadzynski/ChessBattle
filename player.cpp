#include "player.h"

Player::Player(PieceColor _color) : color(_color) {
    Timer* timer = new Timer(300000);
    this->timer = timer;
};

void Player::makeMove(int posX, int posY) {

}

PieceColor Player::getColor() {
    return this->color;
}

Timer* Player::getTimer() {
    return this->timer;
}

void Player::setColor(PieceColor color) {
    this->color = color;
}

void Player::setTimer(Timer* timer) {
    this->timer = timer;
}
