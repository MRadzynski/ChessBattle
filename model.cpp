#include "model.h"

Model::Model() {
    Game* game = new Game();
    this->game = game;
}

Game* Model::getGame() {
    return this->game;
}

void Model::setGame(Game* game) {
    this->game = game;
}
