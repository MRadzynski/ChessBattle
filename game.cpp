#include "game.h"

Game::Game() {
    std::vector<Player*> players;
    Player blackPlayer = Player(PieceColor::BLACK);
    Player whitePlayer = Player(PieceColor::WHITE);

    players.push_back(&blackPlayer);
    players.push_back(&whitePlayer);

    ChessBoard* chessBoard = new ChessBoard();

    this->chessBoard = chessBoard;
    this->currentPlayer = &whitePlayer;
    this->players = players;
}

void Game::initGame() {
    this->getChessBoard()->initializeChessBoard();
}

void Game::restartGame() {

}

void Game::endGame() {

}

void Game::playTurn(Player* player) {
    this->setCurrentPlayer(player);
}

void Game::promotePawn() {

}

Player* Game::getCurrentPlayer() {
    return this->currentPlayer;
}

ChessBoard* Game::getChessBoard() {
    return this->chessBoard;
}

std::vector<Player*> Game::getPlayers() {
    return this->players;
}

void Game::setCurrentPlayer(Player* currentPlayer) {
    this->currentPlayer = currentPlayer;
}

void Game::setChessBoard(ChessBoard* chessBoard) {
    this->chessBoard = chessBoard;
}

void Game::setPlayers(std::vector<Player*> players) {
    this->players = players;
}
