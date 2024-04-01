#ifndef KNIGHT_H
#define KNIGHT_H

#include "chess_piece.h"

class Knight : public ChessPiece {
public:
    Knight(PieceColor color, int posX, int posY, QString iconPath, std::string name);

    bool isValidMove(int newX, int newY, const std::vector<std::vector<ChessPiece*>>& board);
};


#endif // KNIGHT_H
