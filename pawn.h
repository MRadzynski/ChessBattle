#ifndef PAWN_H
#define PAWN_H

#include "chess_piece.h"

class Pawn : public ChessPiece {
public:
    bool isValidMove(int newX, int newY, const std::vector<std::vector<ChessPiece*>>& board);
};


#endif // PAWN_H
