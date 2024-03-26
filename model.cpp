#include "model.h"

CModel::CModel() {
    Game* game = new Game();
    this->game = game;
}

Game* CModel::getGame() {
    return this->game;
}

void CModel::setGame(Game* game) {
    this->game = game;
}
