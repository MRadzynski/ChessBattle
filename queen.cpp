#include "queen.h"

Queen::Queen(PieceColor color, int posX, int posY, QString iconPath): ChessPiece(color, posX, posY, iconPath){};

bool Queen::isValidMove(int posX, int posY,  const std::vector<std::vector<ChessPiece*>>& board) {

}
