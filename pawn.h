#ifndef PAWN_H
#define PAWN_H

#include "chess_piece.h"

class Pawn : public ChessPiece {
private:
    int initPosX;
    int initPosY;
public:
    Pawn(PieceColor color, int posX, int posY, QString iconPath, std::string name);

    bool isValidMove(int potentialPosX, int potentialPosY, const std::vector<std::vector<ChessPiece*>>& board);

    int getInitPosX();

    int getInitPosY();

    void setInitPosX(int initPosX);

    void setInitPosY(int initPosY);
};


#endif // PAWN_H
