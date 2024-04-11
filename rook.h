#ifndef ROOK_H
#define ROOK_H

#include "chess_piece.h"

/**
 * @class Rook
 * @brief This class represents a rook chess piece.
 */
class Rook : public ChessPiece {
public:
    /**
     * @brief Constructs a new Rook object.
     * @param color The color of the rook piece.
     * @param posX The x-coordinate of the rook piece on the board.
     * @param posY The y-coordinate of the rook piece on the board.
     * @param iconPath The path to the icon representing the rook piece.
     * @param name The name of the rook piece.
     */
    Rook(PieceColor color, int posX, int posY, QString iconPath, std::string name);

    /**
     * @brief Checks if the rook piece can move to the specified position.
     * @param potentialPosX The potential x-coordinate of the rook piece on the board.
     * @param potentialPosY The potential y-coordinate of the rook piece on the board.
     * @param board The current state of the chess board.
     * @param playerColor The color of the player making the move.
     * @return True if the move is valid, false otherwise.
     */
    bool isValidMove(int potentialPosX, int potentialPosY, const std::vector<std::vector<ChessPiece*>>& board, PieceColor playerColor);
};

#endif // ROOK_H
