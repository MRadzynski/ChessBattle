#ifndef ROOK_H
#define ROOK_H

#include "chess_piece.h"

class Rook : public ChessPiece {
public:
    Rook(PieceColor color, int posX, int posY, QString iconPath);

    bool isValidMove(int newX, int newY, const std::vector<std::vector<ChessPiece*>>& board);
};


#endif // ROOK_H
