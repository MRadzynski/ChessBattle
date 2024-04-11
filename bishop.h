#ifndef BISHOP_H
#define BISHOP_H

#include "chess_piece.h"

/**
* @class Bishop
* @brief This class represents a bishop chess piece.
*/
class Bishop : public ChessPiece {
public:
    /**
     * @brief Constructs a new Bishop object.
     * @param color The color of the bishop piece.
     * @param posX The x-coordinate of the bishop piece on the board.
     * @param posY The y-coordinate of the bishop piece on the board.
     * @param iconPath The path to the icon representing the bishop piece.
     * @param name The name of the bishop piece.
     */
    Bishop(PieceColor color, int posX, int posY, QString iconPath, std::string name);

    /**
     * @brief Checks if the bishop piece can move to the specified position.
     * @param potentialPosX The potential x-coordinate of the bishop piece on the board.
     * @param potentialPosY The potential y-coordinate of the bishop piece on the board.
     * @param board The current state of the chess board.
     * @param playerColor The color of the player making the move.
     * @return True if the move is valid, false otherwise.
     */
    bool isValidMove(int potentialPosX, int potentialPosY, const std::vector<std::vector<ChessPiece*>>& board, PieceColor playerColor);
};

#endif // BISHOP_H
