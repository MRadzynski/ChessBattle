#include "rook.h"

Rook::Rook(PieceColor color, int posX, int posY, QString iconPath): ChessPiece(color, posX, posY, iconPath){};

bool Rook::isValidMove(int posX, int posY,  const std::vector<std::vector<ChessPiece*>>& board) {

}
