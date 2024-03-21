#ifndef PLAYER_H
#define PLAYER_H

#include "piece_color.h"

class Player {
private:
    PieceColor color;
public:
    Player(PieceColor color);

    void makeMove(int posX, int PosY);

    PieceColor getColor();

    void setColor(PieceColor color);
};

#endif // PLAYER_H
