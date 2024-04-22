#include "chess_board.h"
#include "chess_piece.h"
#include "bishop.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"

#include <QDebug>

ChessBoard::ChessBoard() {
    std::vector<std::vector<ChessPiece*>> initChessBoardState(8, std::vector<ChessPiece*>(8, nullptr));
    this->chessBoardState = initChessBoardState;
    this->selectedPiece = nullptr;
}

ChessBoard::~ChessBoard() {
    for(auto& row : this->chessBoardState) {
        for(auto& piece : row) {
            if(piece != nullptr) {
                delete piece;
            }
        }
    }
}

void ChessBoard::initializeChessBoard() {
    std::vector<std::vector<ChessPiece*>> initChessBoardState(8, std::vector<ChessPiece*>(8, nullptr));

    Rook* blackFirstRook = new Rook(PieceColor::BLACK, 0, 0, ":/images/assets/rook_black.png", "BRK");
    Rook* blackSecondRook = new Rook(PieceColor::BLACK, 0, 7, ":/images/assets/rook_black.png", "BRK");

    Knight* blackFirstKnight = new Knight(PieceColor::BLACK, 0, 1, ":/images/assets/knight_black.png", "BKT");
    Knight* blackSecondKnight = new Knight(PieceColor::BLACK, 0, 6, ":/images/assets/knight_black.png", "BKT");

    Bishop* blackFirstBishop = new Bishop(PieceColor::BLACK, 0, 2, ":/images/assets/bishop_black.png", "BBP");
    Bishop* blackSecondBishop = new Bishop(PieceColor::BLACK, 0, 5, ":/images/assets/bishop_black.png", "BBP");

    Queen* blackQueen = new Queen(PieceColor::BLACK, 0, 3, ":/images/assets/queen_black.png", "BQN");
    King* blackKing = new King(PieceColor::BLACK, 0, 4, ":/images/assets/king_black.png", "BKG");

    Pawn* blackFirstPawn = new Pawn(PieceColor::BLACK, 1, 0, ":/images/assets/pawn_black.png", "BPN");
    Pawn* blackSecondPawn = new Pawn(PieceColor::BLACK, 1, 1, ":/images/assets/pawn_black.png", "BPN");
    Pawn* blackThirdPawn = new Pawn(PieceColor::BLACK, 1, 2, ":/images/assets/pawn_black.png", "BPN");
    Pawn* blackFourthPawn = new Pawn(PieceColor::BLACK, 1, 3, ":/images/assets/pawn_black.png", "BPN");
    Pawn* blackFifthPawn = new Pawn(PieceColor::BLACK, 1, 4, ":/images/assets/pawn_black.png", "BPN");
    Pawn* blackSixthPawn = new Pawn(PieceColor::BLACK, 1, 5, ":/images/assets/pawn_black.png", "BPN");
    Pawn* blackSeventhPawn = new Pawn(PieceColor::BLACK, 1, 6, ":/images/assets/pawn_black.png", "BPN");
    Pawn* blackEighthPawn = new Pawn(PieceColor::BLACK, 1, 7, ":/images/assets/pawn_black.png", "BPN");

    Rook* whiteFirstRook = new Rook(PieceColor::WHITE, 7, 0, ":/images/assets/rook_white.png", "WRK");
    Rook* whiteSecondRook = new Rook(PieceColor::WHITE, 7, 7, ":/images/assets/rook_white.png", "WRK");

    Knight* whiteFirstKnight = new Knight(PieceColor::WHITE, 7, 1, ":/images/assets/knight_white.png", "WKT");
    Knight* whiteSecondKnight = new Knight(PieceColor::WHITE, 7, 6, ":/images/assets/knight_white.png", "WKT");

    Bishop* whiteFirstBishop = new Bishop(PieceColor::WHITE, 7, 2, ":/images/assets/bishop_white.png", "WBP");
    Bishop* whiteSecondBishop = new Bishop(PieceColor::WHITE, 7, 5, ":/images/assets/bishop_white.png", "WBP");

    Queen* whiteQueen = new Queen(PieceColor::WHITE, 7, 3, ":/images/assets/queen_white.png", "WQN");
    King* whiteKing = new King(PieceColor::WHITE, 7, 4, ":/images/assets/king_white.png", "WKG");

    Pawn* whiteFirstPawn = new Pawn(PieceColor::WHITE, 6, 0, ":/images/assets/pawn_white.png", "WPN");
    Pawn* whiteSecondPawn = new Pawn(PieceColor::WHITE, 6, 1, ":/images/assets/pawn_white.png", "WPN");
    Pawn* whiteThirdPawn = new Pawn(PieceColor::WHITE, 6, 2, ":/images/assets/pawn_white.png", "WPN");
    Pawn* whiteFourthPawn = new Pawn(PieceColor::WHITE, 6, 3, ":/images/assets/pawn_white.png", "WPN");
    Pawn* whiteFifthPawn = new Pawn(PieceColor::WHITE, 6, 4, ":/images/assets/pawn_white.png", "WPN");
    Pawn* whiteSixthPawn = new Pawn(PieceColor::WHITE, 6, 5, ":/images/assets/pawn_white.png", "WPN");
    Pawn* whiteSeventhPawn = new Pawn(PieceColor::WHITE, 6, 6, ":/images/assets/pawn_white.png", "WPN");
    Pawn* whiteEighthPawn = new Pawn(PieceColor::WHITE, 6, 7, ":/images/assets/pawn_white.png", "WPN");

    initChessBoardState[0][0] = blackFirstRook;
    initChessBoardState[0][1] = blackFirstKnight;
    initChessBoardState[0][2] = blackFirstBishop;
    initChessBoardState[0][3] = blackQueen;
    initChessBoardState[0][4] = blackKing;
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
    initChessBoardState[7][3] = whiteQueen;
    initChessBoardState[7][4] = whiteKing;
    initChessBoardState[7][5] = whiteSecondBishop;
    initChessBoardState[7][6] = whiteSecondKnight;
    initChessBoardState[7][7] = whiteSecondRook;

    this->setChessBoardState(initChessBoardState);
}

void ChessBoard::movePiece(int row, int col) {
    if(this->getSelectedPiece() == nullptr) {
        if(this->getChessBoardState()[row][col] != nullptr) {
            ChessPiece* selectedPiece = this->getChessBoardState()[row][col];
            this->setSelectedPiece(selectedPiece);
        }
    } else {
        ChessPiece* selectedPiece = this->getSelectedPiece();
        int selectedPiecePosX = selectedPiece->getPosX();
        int selectedPiecePosY = selectedPiece->getPosY();
        std::vector<std::vector<ChessPiece*>> newChessBoardState = this->getChessBoardState();

        selectedPiece->setPosX(row);
        selectedPiece->setPosY(col);
        newChessBoardState[selectedPiecePosX][selectedPiecePosY] = nullptr;
        newChessBoardState[row][col] = selectedPiece;

        this->setChessBoardState(newChessBoardState);
        this->setSelectedPiece(nullptr);
    }
    this->displayChessBoardState();
}

std::vector<std::vector<ChessPiece*>> ChessBoard::getChessBoardState() {
    return this->chessBoardState;
}

ChessPiece* ChessBoard::getSelectedPiece() {
    return this->selectedPiece;
}

void ChessBoard::setChessBoardState(std::vector<std::vector<ChessPiece*>> chessBoardState) {
    this->chessBoardState = chessBoardState;
}

void ChessBoard::setSelectedPiece(ChessPiece* selectedPiece) {
    this->selectedPiece = selectedPiece;
}

void ChessBoard::displayChessBoardState() {
    for (auto& row : this->getChessBoardState()) {
        for (auto& piece : row) {
            if(piece == nullptr) {
                qDebug() << "--- ";
            } else {
                qDebug() << piece->getName() << " ";
            }
        }
    }

    // for (auto& row : this->getChessBoardState()) {
    //     for (auto& piece : row) {
    //         if(piece == nullptr) {
    //             qDebug() << "--- ";
    //         } else {
    //             qDebug() << piece->getPosX() << "," << piece->getPosY()<< " ";
    //         }
    //     }
    // }
}
