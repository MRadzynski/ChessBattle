#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "chess_piece.h"
#include <vector>

class ChessBoard {
private:
    std::vector<std::vector<ChessPiece*>> chessBoardState;

public:
    ChessBoard();

    void initializeChessBoard();

    void movePiece(ChessPiece* chessPiece);

    bool isCheckMate();

    std::vector<std::vector<ChessPiece*>> getChessBoardState();

    void setChessBoardState(std::vector<std::vector<ChessPiece*>> chessBoardState);

    void displayChessBoardState();
};

#endif // CHESS_BOARD_H
