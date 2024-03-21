#ifndef QUEEN_H
#define QUEEN_H

#include "chess_piece.h"

class Queen : public ChessPiece {
public:
    bool isValidMove(int newX, int newY, const std::vector<std::vector<ChessPiece*>>& board);
};

#endif // QUEEN_H
