#ifndef BISHOP_H
#define BISHOP_H

#include "chess_piece.h"

class Bishop : public ChessPiece {
public:
    bool isValidMove(int newX, int newY, const std::vector<std::vector<ChessPiece*>>& board);
};


#endif // BISHOP_H
