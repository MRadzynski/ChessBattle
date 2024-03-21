#ifndef GAME_H
#define GAME_H

#include "player.h"

class Game {
private:
    Player currentPlayer;

public:
    void start_game();

    void restart_game();

    void end_game();

    void playTurn(Player player);

    void promotePawn();

    Player getCurrentPlayer();

    void setCurrentPlayer(Player player);
};

#endif // GAME_H
