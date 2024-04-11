#ifndef PAWN_H
#define PAWN_H

#include "chess_piece.h"

/**
 * @class Pawn
 * @brief This class represents a pawn chess piece.
 */
class Pawn : public ChessPiece {
private:
    int initPosX; ///< The initial x-coordinate of the pawn piece on the board.
    int initPosY; ///< The initial y-coordinate of the pawn piece on the board.

public:
    /**
     * @brief Constructs a new Pawn object.
     * @param color The color of the pawn piece.
     * @param posX The x-coordinate of the pawn piece on the board.
     * @param posY The y-coordinate of the pawn piece on the board.
     * @param iconPath The path to the icon representing the pawn piece.
     * @param name The name of the pawn piece.
     */
    Pawn(PieceColor color, int posX, int posY, QString iconPath, std::string name);

    /**
     * @brief Checks if the pawn piece can move to the specified position.
     * @param potentialPosX The potential x-coordinate of the pawn piece on the board.
     * @param potentialPosY The potential y-coordinate of the pawn piece on the board.
     * @param board The current state of the chess board.
     * @param playerColor The color of the player making the move.
     * @return True if the move is valid, false otherwise.
     */
    bool isValidMove(int potentialPosX, int potentialPosY, const std::vector<std::vector<ChessPiece*>>& board, PieceColor playerColor);

    /**
     * @brief Gets the initial x-coordinate of the pawn piece on the board.
     * @return The initial x-coordinate.
     */
    int getInitPosX();

    /**
     * @brief Gets the initial y-coordinate of the pawn piece on the board.
     * @return The initial y-coordinate.
     */
    int getInitPosY();

    /**
     * @brief Sets the initial x-coordinate of the pawn piece on the board.
     * @param initPosX The new initial x-coordinate.
     */
    void setInitPosX(int initPosX);

    /**
     * @brief Sets the initial y-coordinate of the pawn piece on the board.
     * @param initPosY The new initial y-coordinate.
     */
    void setInitPosY(int initPosY);
};

#endif // PAWN_H
