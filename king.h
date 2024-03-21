#ifndef KING_H
#define KING_H

#include "chess_piece.h"

class King : public ChessPiece {
public:
    bool isValidMove(int newX, int newY, const std::vector<std::vector<ChessPiece*>>& board);
};

#endif // KING_H
