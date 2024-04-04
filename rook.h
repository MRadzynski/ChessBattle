#ifndef ROOK_H
#define ROOK_H

#include "chess_piece.h"

class Rook : public ChessPiece {
public:
    Rook(PieceColor color, int posX, int posY, QString iconPath, std::string name);

    bool isValidMove(int potentialPosX, int potentialPosY, const std::vector<std::vector<ChessPiece*>>& board, PieceColor playerColor);
};


#endif // ROOK_H
