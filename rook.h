#ifndef ROOK_H
#define ROOK_H

#include "chess_piece.h"

class Rook : public ChessPiece {
public:
    bool isValidMove(int newX, int newY, const std::vector<std::vector<ChessPiece*>>& board);
};


#endif // ROOK_H
