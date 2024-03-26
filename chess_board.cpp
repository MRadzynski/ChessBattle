#include "chess_board.h"
#include "chess_piece.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include "pawn.h"

ChessBoard::ChessBoard() {
    std::vector<std::vector<ChessPiece*>> initChessBoardState(8, std::vector<ChessPiece*>(8, nullptr));
    this->chessBoardState = initChessBoardState;
}

void ChessBoard::initializeChessBoard() {
    std::vector<std::vector<ChessPiece*>> initChessBoardState(8, std::vector<ChessPiece*>(8, nullptr));

    Rook* blackFirstRook = new Rook(PieceColor::BLACK, 0, 0, ":/images/assets/rook_black.png");
    Rook* blackSecondRook = new Rook(PieceColor::BLACK, 7, 0, ":/images/assets/rook_black.png");

    Knight* blackFirstKnight = new Knight(PieceColor::BLACK, 1, 0, ":/images/assets/knight_black.png");
    Knight* blackSecondKnight = new Knight(PieceColor::BLACK, 6, 0, ":/images/assets/knight_black.png");

    Bishop* blackFirstBishop = new Bishop(PieceColor::BLACK, 2, 0, ":/images/assets/bishop_black.png");
    Bishop* blackSecondBishop = new Bishop(PieceColor::BLACK, 5, 0, ":/images/assets/bishop_black.png");

    King* blackKing = new King(PieceColor::BLACK, 3, 0, ":/images/assets/king_black.png");
    Queen* blackQueen = new Queen(PieceColor::BLACK, 4, 0, ":/images/assets/queen_black.png");

    Pawn* blackFirstPawn = new Pawn(PieceColor::BLACK, 0, 0, ":/images/assets/pawn_black.png");
    Pawn* blackSecondPawn = new Pawn(PieceColor::BLACK, 1, 0, ":/images/assets/pawn_black.png");
    Pawn* blackThirdPawn = new Pawn(PieceColor::BLACK, 2, 0, ":/images/assets/pawn_black.png");
    Pawn* blackFourthPawn = new Pawn(PieceColor::BLACK, 3, 0, ":/images/assets/pawn_black.png");
    Pawn* blackFifthPawn = new Pawn(PieceColor::BLACK, 4, 0, ":/images/assets/pawn_black.png");
    Pawn* blackSixthPawn = new Pawn(PieceColor::BLACK, 5, 0, ":/images/assets/pawn_black.png");
    Pawn* blackSeventhPawn = new Pawn(PieceColor::BLACK, 6, 0, ":/images/assets/pawn_black.png");
    Pawn* blackEighthPawn = new Pawn(PieceColor::BLACK, 7, 0, ":/images/assets/pawn_black.png");

    Rook* whiteFirstRook = new Rook(PieceColor::WHITE, 7, 0, ":/images/assets/rook_white.png");
    Rook* whiteSecondRook = new Rook(PieceColor::WHITE, 7, 7, ":/images/assets/rook_white.png");

    Knight* whiteFirstKnight = new Knight(PieceColor::WHITE, 7, 1, ":/images/assets/knight_white.png");
    Knight* whiteSecondKnight = new Knight(PieceColor::WHITE, 7, 6, ":/images/assets/knight_white.png");

    Bishop* whiteFirstBishop = new Bishop(PieceColor::WHITE, 7, 2, ":/images/assets/bishop_white.png");
    Bishop* whiteSecondBishop = new Bishop(PieceColor::WHITE, 7, 5, ":/images/assets/bishop_white.png");

    King* whiteKing = new King(PieceColor::WHITE, 7, 3, ":/images/assets/king_white.png");
    Queen* whiteQueen = new Queen(PieceColor::WHITE, 7, 4, ":/images/assets/queen_white.png");

    Pawn* whiteFirstPawn = new Pawn(PieceColor::WHITE, 0, 0, ":/images/assets/pawn_white.png");
    Pawn* whiteSecondPawn = new Pawn(PieceColor::WHITE, 1, 0, ":/images/assets/pawn_white.png");
    Pawn* whiteThirdPawn = new Pawn(PieceColor::WHITE, 2, 0, ":/images/assets/pawn_white.png");
    Pawn* whiteFourthPawn = new Pawn(PieceColor::WHITE, 3, 0, ":/images/assets/pawn_white.png");
    Pawn* whiteFifthPawn = new Pawn(PieceColor::WHITE, 4, 0, ":/images/assets/pawn_white.png");
    Pawn* whiteSixthPawn = new Pawn(PieceColor::WHITE, 5, 0, ":/images/assets/pawn_white.png");
    Pawn* whiteSeventhPawn = new Pawn(PieceColor::WHITE, 6, 0, ":/images/assets/pawn_white.png");
    Pawn* whiteEighthPawn = new Pawn(PieceColor::WHITE, 7, 0, ":/images/assets/pawn_white.png");

    initChessBoardState[0][0] = blackFirstRook;
    initChessBoardState[0][1] = blackFirstKnight;
    initChessBoardState[0][2] = blackFirstBishop;
    initChessBoardState[0][3] = blackKing;
    initChessBoardState[0][4] = blackQueen;
    initChessBoardState[0][5] = blackSecondBishop;
    initChessBoardState[0][6] = blackSecondKnight;
    initChessBoardState[0][7] = blackSecondRook;
    initChessBoardState[1][0] = blackFirstPawn;
    initChessBoardState[1][1] = blackSecondPawn;
    initChessBoardState[1][2] = blackThirdPawn;
    initChessBoardState[1][3] = blackFourthPawn;
    initChessBoardState[1][4] = blackFifthPawn;
    initChessBoardState[1][5] = blackSixthPawn;
    initChessBoardState[1][6] = blackSeventhPawn;
    initChessBoardState[1][7] = blackEighthPawn;

    initChessBoardState[6][0] = whiteFirstPawn;
    initChessBoardState[6][1] = whiteSecondPawn;
    initChessBoardState[6][2] = whiteThirdPawn;
    initChessBoardState[6][3] = whiteFourthPawn;
    initChessBoardState[6][4] = whiteFifthPawn;
    initChessBoardState[6][5] = whiteSixthPawn;
    initChessBoardState[6][6] = whiteSeventhPawn;
    initChessBoardState[6][7] = whiteEighthPawn;
    initChessBoardState[7][0] = whiteFirstRook;
    initChessBoardState[7][1] = whiteFirstKnight;
    initChessBoardState[7][2] = whiteFirstBishop;
    initChessBoardState[7][3] = whiteKing;
    initChessBoardState[7][4] = whiteQueen;
    initChessBoardState[7][5] = whiteSecondBishop;
    initChessBoardState[7][6] = whiteSecondKnight;
    initChessBoardState[7][7] = whiteSecondRook;

    this->setChessBoardState(initChessBoardState);
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

