#ifndef PLAYER_H
#define PLAYER_H

#include "piece_color.h"
#include "timer.h"

class Player {
private:
    PieceColor color;
    QString name;
    Timer* timer;

public:
    Player(PieceColor _color, QString _name);

    PieceColor getColor();

    QString getName();

    Timer* getTimer();

    void setColor(PieceColor color);

    void setName(QString name);

    void setTimer(Timer* timer);
};

#endif // PLAYER_H
