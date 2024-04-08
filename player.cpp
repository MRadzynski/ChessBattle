#include "player.h"

Player::Player(PieceColor _color, QString _name) : color(_color), name(_name) {
    Timer* timer = new Timer(300000);
    this->timer = timer;
};

void Player::makeMove(int posX, int posY) {

}

PieceColor Player::getColor() {
    return this->color;
}

QString Player::getName() {
    return this->name;
}

Timer* Player::getTimer() {
    return this->timer;
}

void Player::setColor(PieceColor color) {
    this->color = color;
}

void Player::setName(QString name) {
    this->name = name;
}

void Player::setTimer(Timer* timer) {
    this->timer = timer;
}
