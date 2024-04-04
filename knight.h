#ifndef KNIGHT_H
#define KNIGHT_H

#include "chess_piece.h"

class Knight : public ChessPiece {
public:
    Knight(PieceColor color, int posX, int posY, QString iconPath, std::string name);

    bool isValidMove(int potentialPosX, int potentialPosY, const std::vector<std::vector<ChessPiece*>>& board, PieceColor playerColor);
};


#endif // KNIGHT_H
