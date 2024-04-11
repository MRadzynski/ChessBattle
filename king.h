#ifndef KING_H
#define KING_H

#include "chess_piece.h"

/**
 * @class King
 * @brief This class represents a king chess piece.
 */
class King : public ChessPiece {
public:
    /**
     * @brief Constructs a new King object.
     * @param color The color of the king piece.
     * @param posX The x-coordinate of the king piece on the board.
     * @param posY The y-coordinate of the king piece on the board.
     * @param iconPath The path to the icon representing the king piece.
     * @param name The name of the king piece.
     */
    King(PieceColor color, int posX, int posY, QString iconPath, std::string name);

    /**
     * @brief Gets the positions that other king can move to.
     * @param otherKing The other king piece.
     * @return A vector of pairs representing the potential threatened positions.
     */
    std::vector<std::pair<int, int>> getPotentialThreatenedPositions(ChessPiece* otherKing);

    /**
     * @brief Gets the restricted moves for the king.
     * @param king The king piece.
     * @param otherKing The other king piece.
     * @return A vector of pairs representing the restricted moves for the king.
     */
    std::vector<std::pair<int, int>> getRestrictedKingMoves(ChessPiece* king, ChessPiece* otherKing);

    /**
     * @brief Checks if the king piece can move to the specified position.
     * @param potentialPosX The potential x-coordinate of the king piece on the board.
     * @param potentialPosY The potential y-coordinate of the king piece on the board.
     * @param board The current state of the chess board.
     * @param playerColor The color of the player making the move.
     * @return True if the move is valid, false otherwise.
     */
    bool isValidMove(int potentialPosX, int potentialPosY, const std::vector<std::vector<ChessPiece*>>& board, PieceColor playerColor);
};

#endif // KING_H
