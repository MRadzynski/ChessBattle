#include "rook.h"

Rook::Rook(PieceColor color, int posX, int posY, QString iconPath, std::string name): ChessPiece(color, posX, posY, iconPath, name){};

bool Rook::isValidMove(int posX, int posY,  const std::vector<std::vector<ChessPiece*>>& board) {

}
