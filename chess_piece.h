#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include "piece_color.h"
#include <vector>
#include <string>

#include <QString>

class ChessPiece {
private:
    PieceColor color;
    int posX;
    int posY;
    QString iconPath;

public:
    ChessPiece(PieceColor _color, int _posX, int _posY, QString iconPath);

    PieceColor getColor();

    int getPosX();

    int getPosY();

    QString getIconPath();

    void setColor(PieceColor color);

    void setPosX(int posX);

    void setPosY(int posX);

    void setIconPath(QString iconPath);

    virtual bool isValidMove(int newX, int newY, const std::vector<std::vector<ChessPiece*>>& board) = 0;
};

#endif // CHESS_PIECE_H
