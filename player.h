#ifndef PLAYER_H
#define PLAYER_H

#include "piece_color.h"
#include "timer.h"

class Player {
private:
    PieceColor color;
    Timer* timer;
public:
    Player(PieceColor color);

    void makeMove(int posX, int PosY);

    PieceColor getColor();

    Timer* getTimer();

    void setColor(PieceColor color);

    void setTimer(Timer* timer);
};

#endif // PLAYER_H
