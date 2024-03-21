#include "chess_board.h"
#include "chess_piece.h"

void ChessBoard::initializeChessBoard() {

}

void ChessBoard::movePiece(ChessPiece* chessPiece) {

}

bool ChessBoard::isCheckMate() {

}

std::vector<std::vector<ChessPiece*>> ChessBoard::getChessBoardState() {
    return this->chessBoardState;
}

void ChessBoard::setChessBoardState(std::vector<std::vector<ChessPiece*>> chessBoardState) {
    this->chessBoardState = chessBoardState;
}
