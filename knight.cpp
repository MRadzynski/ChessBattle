#include "knight.h"

Knight::Knight(PieceColor color, int posX, int posY, QString iconPath): ChessPiece(color, posX, posY, iconPath){};

bool Knight::isValidMove(int posX, int posY,  const std::vector<std::vector<ChessPiece*>>& board) {

}
