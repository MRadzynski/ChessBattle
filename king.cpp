#include "king.h"

King::King(PieceColor color, int posX, int posY, QString iconPath, std::string name): ChessPiece(color, posX, posY, iconPath, name){};

bool King::isValidMove(int potentialPosX, int potentialPosY,  const std::vector<std::vector<ChessPiece*>>& board) {
    struct movement {
        int x;
        int y;
    };
    std::vector<movement> possibleMoves;

    //TODO: add playerColor in the params
    PieceColor playerColor = PieceColor::WHITE;

    // for(int row = -1; row < 2; row++) {
    //     for(int col = -1; col < 2; col++) {
    //         if(this->getPosX()+row <)
    //     }
    // }
}
