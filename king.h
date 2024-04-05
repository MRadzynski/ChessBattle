#ifndef KING_H
#define KING_H

#include "chess_piece.h"

class King : public ChessPiece {
public:
    King(PieceColor color, int posX, int posY, QString iconPath, std::string name);

    std::vector<std::pair<int, int>> getPotentialThreatenedPositions(ChessPiece* otherKing);

    std::vector<std::pair<int, int>> getRestrictedKingMoves(ChessPiece* king, ChessPiece* otherKing);

    bool isValidMove(int potentialPosX, int potentialPosY, const std::vector<std::vector<ChessPiece*>>& board, PieceColor playerColor);
};

#endif // KING_H
