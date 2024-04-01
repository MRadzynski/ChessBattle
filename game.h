#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "chess_board.h"
#include <vector>

class Game {
private:
    std::vector<Player*> players;
    Player* currentPlayer;
    ChessBoard* chessBoard;

public:
    Game();

    void initGame();

    void restartGame();

    void endGame();

    void playTurn(Player* player);

    void promotePawn();

    void makeMove(int row, int col);

    Player* getCurrentPlayer();

    std::vector<Player*> getPlayers();

    ChessBoard* getChessBoard();

    void setCurrentPlayer(Player* player);

    void setPlayers(std::vector<Player*> players);

    void setChessBoard(ChessBoard* chessboard);
};

#endif // GAME_H
