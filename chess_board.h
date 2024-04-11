#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "chess_piece.h"

#include <vector>

/**
 * @class ChessBoard
 * @brief This class represents a chess board.
 * 
 * The chess board is represented as a 2D vector of ChessPiece pointers which are pointing to the specific chess pieces.
 * The class also keeps track of the currently selected piece.
 */
class ChessBoard {
private:
    /**
     * @brief 2D vector representing the state of the chess board.
     * Each element is a pointer to a chess piece.
     */
    std::vector<std::vector<ChessPiece*>> chessBoardState;

    /**
     * @brief Pointer to the currently selected chess piece.
     */
    ChessPiece* selectedPiece;

public:
    /**
     * @brief Constructs a new ChessBoard object.
     */
    ChessBoard();

    /**
     * @brief Displays the current state of the chess board.
     */
    void displayChessBoardState();

    /**
     * @brief Initializes the chess board with the standard setup of pieces.
     */
    void initializeChessBoard();

    /**
     * @brief Checks if the current state of the board is a checkmate.
     * 
     * @return true if the current state is a checkmate, false otherwise.
     */
    bool isCheckMate();

    /**
     * @brief Moves the selected piece to the specified row and column.
     * 
     * @param row The row to move the piece to.
     * @param col The column to move the piece to.
     */
    void movePiece(int row, int col);

    /**
     * @brief Returns the current state of the chess board.
     * 
     * @return A 2D vector representing the state of the chess board.
     */
    std::vector<std::vector<ChessPiece*>> getChessBoardState();

    /**
     * @brief Returns the currently selected piece.
     * 
     * @return A pointer to the currently selected ChessPiece.
     */
    ChessPiece* getSelectedPiece();

    /**
     * @brief Sets the state of the chess board.
     * 
     * @param chessBoardState A 2D vector representing the new state of the chess board.
     */
    void setChessBoardState(std::vector<std::vector<ChessPiece*>> chessBoardState);

    /**
     * @brief Sets the currently selected piece.
     * 
     * @param selectedPiece A pointer to the ChessPiece to select.
     */
    void setSelectedPiece(ChessPiece* selectedPiece);
};

#endif // CHESS_BOARD_H
