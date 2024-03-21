#ifndef KNIGHT_H
#define KNIGHT_H

#include "chess_piece.h"

class Knight : public ChessPiece {
public:
    bool isValidMove(int newX, int newY, const std::vector<std::vector<ChessPiece*>>& board);
};


#endif // KNIGHT_H
