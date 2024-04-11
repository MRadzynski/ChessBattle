#ifndef KNIGHT_H
#define KNIGHT_H

#include "chess_piece.h"

/**
 * @class Knight
 * @brief This class represents a knight chess piece.
 */
class Knight : public ChessPiece {
public:
    /**
     * @brief Constructs a new Knight object.
     * @param color The color of the knight piece.
     * @param posX The x-coordinate of the knight piece on the board.
     * @param posY The y-coordinate of the knight piece on the board.
     * @param iconPath The path to the icon representing the knight piece.
     * @param name The name of the knight piece.
     */
    Knight(PieceColor color, int posX, int posY, QString iconPath, std::string name);

    /**
     * @brief Checks if the knight piece can move to the specified position.
     * @param potentialPosX The potential x-coordinate of the knight piece on the board.
     * @param potentialPosY The potential y-coordinate of the knight piece on the board.
     * @param board The current state of the chess board.
     * @param playerColor The color of the player making the move.
     * @return True if the move is valid, false otherwise.
     */
    bool isValidMove(int potentialPosX, int potentialPosY, const std::vector<std::vector<ChessPiece*>>& board, PieceColor playerColor);
};

#endif // KNIGHT_H
