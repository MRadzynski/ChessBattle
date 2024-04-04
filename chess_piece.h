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
    std::string name;

public:
    ChessPiece(PieceColor _color, int _posX, int _posY, QString iconPath, std::string name);

    PieceColor getColor();

    int getPosX();

    int getPosY();

    QString getIconPath();

    std::string getName();

    void setColor(PieceColor color);

    void setPosX(int posX);

    void setPosY(int posX);

    void setIconPath(QString iconPath);

    void setName(std::string name);

    virtual bool isValidMove(int potentialPosX, int potentialPosY, const std::vector<std::vector<ChessPiece*>>& board, PieceColor playerColor) = 0;
};

#endif // CHESS_PIECE_H
