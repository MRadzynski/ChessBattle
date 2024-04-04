#ifndef BISHOP_H
#define BISHOP_H

#include "chess_piece.h"

class Bishop : public ChessPiece {
public:
    Bishop(PieceColor color, int posX, int posY, QString iconPath, std::string name);

    bool isValidMove(int potentialPosX, int potentialPosY, const std::vector<std::vector<ChessPiece*>>& board, PieceColor playerColor);
};


#endif // BISHOP_H
