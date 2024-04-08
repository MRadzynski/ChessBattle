#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include "piece_color.h"

#include <QString>
#include <string>
#include <vector>

class ChessPiece {
private:
    PieceColor color;
    QString iconPath;
    std::string name;
    int posX;
    int posY;

public:
    ChessPiece(PieceColor _color, int _posX, int _posY, QString _iconPath, std::string _name);

    virtual ~ChessPiece();

    PieceColor getColor();

    QString getIconPath();

    std::string getName();

    int getPosX();

    int getPosY();

    void setColor(PieceColor color);

    void setIconPath(QString iconPath);

    void setName(std::string name);

    void setPosX(int posX);

    void setPosY(int posX);

    virtual bool isValidMove(int potentialPosX, int potentialPosY, const std::vector<std::vector<ChessPiece*>>& board, PieceColor playerColor) = 0;
};

#endif // CHESS_PIECE_H
