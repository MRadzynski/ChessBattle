#ifndef KING_H
#define KING_H

#include "chess_piece.h"

class King : public ChessPiece {
public:
    King(PieceColor color, int posX, int posY, QString iconPath, std::string name);

    bool isValidMove(int potentialPosX, int potentialPosY, const std::vector<std::vector<ChessPiece*>>& board);
};

#endif // KING_H
