#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "chess_piece.h"

#include <vector>

class ChessBoard {
private:
    std::vector<std::vector<ChessPiece*>> chessBoardState;
    ChessPiece* selectedPiece;

public:
    ChessBoard();

    void displayChessBoardState();

    void initializeChessBoard();

    bool isCheckMate();

    void movePiece(int row, int col);

    std::vector<std::vector<ChessPiece*>> getChessBoardState();

    ChessPiece* getSelectedPiece();

    void setChessBoardState(std::vector<std::vector<ChessPiece*>> chessBoardState);

    void setSelectedPiece(ChessPiece* selectedPiece);
};

#endif // CHESS_BOARD_H
