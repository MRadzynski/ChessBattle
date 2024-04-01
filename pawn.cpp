#include "pawn.h"

Pawn::Pawn(PieceColor color, int posX, int posY, QString iconPath, std::string name): ChessPiece(color, posX, posY, iconPath, name){};

bool Pawn::isValidMove(int posX, int posY,  const std::vector<std::vector<ChessPiece*>>& board) {

}
