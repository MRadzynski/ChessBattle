#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include "piece_color.h"
#include <vector>

class ChessPiece {
private:
    PieceColor color;
    int posX;
    int posY;

public:
    ChessPiece(PieceColor _color, int _posX, int _posY);

    PieceColor getColor();

    int getPosX();

    int getPosY();

    void setColor(PieceColor color);

    void setPosX(int posX);

    void setPosY(int posX);

    virtual bool isValidMove(int newX, int newY, const std::vector<std::vector<ChessPiece*>>& board) = 0;
};

#endif // CHESS_PIECE_H
