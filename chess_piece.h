#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include "piece_color.h"

#include <QString>
#include <string>
#include <vector>

/**
 * @class ChessPiece
 * @brief The ChessPiece class represents a single piece in the chess game.
 */
class ChessPiece {
private:
    PieceColor color; ///< The color of the chess piece.
    QString iconPath; ///< The path to the icon representing the chess piece.
    std::string name; ///< The name of the chess piece.
    int posX; ///< The x-coordinate of the chess piece on the board.
    int posY; ///< The y-coordinate of the chess piece on the board.

public:
    /**
     * @brief Constructs a new ChessPiece object.
     * @param _color The color of the chess piece.
     * @param _posX The x-coordinate of the chess piece on the board.
     * @param _posY The y-coordinate of the chess piece on the board.
     * @param _iconPath The path to the icon representing the chess piece.
     * @param _name The name of the chess piece.
     */
    ChessPiece(PieceColor _color, int _posX, int _posY, QString _iconPath, std::string _name);

    /**
     * @brief Destroys the ChessPiece object.
     */
    virtual ~ChessPiece();

    /**
     * @brief Gets the color of the chess piece.
     * @return The color of the chess piece.
     */
    PieceColor getColor();

    /**
     * @brief Gets the path to the icon representing the chess piece.
     * @return The path to the icon representing the chess piece.
     */
    QString getIconPath();

    /**
     * @brief Gets the name of the chess piece.
     * @return The name of the chess piece.
     */
    std::string getName();

    /**
     * @brief Gets the x-coordinate of the chess piece on the board.
     * @return The x-coordinate of the chess piece on the board.
     */
    int getPosX();

    /**
     * @brief Gets the y-coordinate of the chess piece on the board.
     * @return The y-coordinate of the chess piece on the board.
     */
    int getPosY();

    /**
     * @brief Sets the color of the chess piece.
     * @param color The new color of the chess piece.
     */
    void setColor(PieceColor color);

    /**
     * @brief Sets the path to the icon representing the chess piece.
     * @param iconPath The new path to the icon representing the chess piece.
     */
    void setIconPath(QString iconPath);

    /**
     * @brief Sets the name of the chess piece.
     * @param name The new name of the chess piece.
     */
    void setName(std::string name);

    /**
     * @brief Sets the x-coordinate of the chess piece on the board.
     * @param posX The new x-coordinate of the chess piece on the board.
     */
    void setPosX(int posX);

    /**
     * @brief Sets the y-coordinate of the chess piece on the board.
     * @param posY The new y-coordinate of the chess piece on the board.
     */
    void setPosY(int posY);

    /**
     * @brief Checks if a move is valid for this chess piece.
     * @param potentialPosX The potential x-coordinate of the chess piece on the board.
     * @param potentialPosY The potential y-coordinate of the chess piece on the board.
     * @param board The current state of the chess board.
     * @param playerColor The color of the player making the move.
     * @return True if the move is valid, false otherwise.
     */
    virtual bool isValidMove(int potentialPosX, int potentialPosY, const std::vector<std::vector<ChessPiece*>>& board, PieceColor playerColor) = 0;
};

#endif // CHESS_PIECE_H
