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

    void initializeChessBoard();

    void movePiece(int row, int col);

    bool isCheckMate();

    std::vector<std::vector<ChessPiece*>> getChessBoardState();

    ChessPiece* getSelectedPiece();

    void setChessBoardState(std::vector<std::vector<ChessPiece*>> chessBoardState);

    void displayChessBoardState();

    void setSelectedPiece(ChessPiece* selectedPiece);
};

#endif // CHESS_BOARD_H
