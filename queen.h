#ifndef QUEEN_H
#define QUEEN_H

#include "chess_piece.h"

class Queen : public ChessPiece {
public:
    Queen(PieceColor color, int posX, int posY, QString iconPath, std::string name);

    bool isValidMove(int newX, int newY, const std::vector<std::vector<ChessPiece*>>& board);
};

#endif // QUEEN_H
