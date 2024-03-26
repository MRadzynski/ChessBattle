#include "pawn.h"

Pawn::Pawn(PieceColor color, int posX, int posY, QString iconPath): ChessPiece(color, posX, posY, iconPath){};

bool Pawn::isValidMove(int posX, int posY,  const std::vector<std::vector<ChessPiece*>>& board) {

}
