#ifndef CHESSBOARD_VIEW_H
#define CHESSBOARD_VIEW_H

#include "chessboard_view.h"
#include "chess_piece.h"
#include "ui_view.h"

/**
 * @class ChessboardView
 * @brief This class represents the chessboard UI. It is responsible for updating the UI of the chessboard depending on the game state.
 */
class ChessboardView : public QWidget {
private:
    Ui::View* ui;  ///< The pointer to the UI instance.

public:
    /**
     * @brief Constructs a new ChessboardView object.
     */
    ChessboardView(Ui::View* ui);

    /**
     * @brief Highlights the selected chess piece in the UI.
     * @param selectedPiece The selected chess piece.
     * @param chessBoard The current state of the chess board.
     */
    void highlightSelectedPiece(ChessPiece* selectedPiece, std::vector<std::vector<ChessPiece*>> chessBoard);

    /**
     * @brief Renders the chess board in the UI.
     */
    void renderChessBoard();

    /**
     * @brief Unhighlights the selected chess piece in the UI.
     */
    void unhighlightSelectedPiece();

    /**
     * @brief Updates the chess board in the UI.
     * @param chessBoardState The current state of the chess board.
     */
    void updateChessBoard(std::vector<std::vector<ChessPiece*>> chessBoardState);

    /**
     * @brief Gets the UI instance.
     * @return The UI instance.
     */
    Ui::View* getUI();

    /**
     * @brief Sets the UI instance.
     * @param ui The UI instance to set.
     */
    void setUI(Ui::View* ui);
};

#endif // CHESSBOARD_VIEW_H
