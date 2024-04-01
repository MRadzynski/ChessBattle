#include "knight.h"

Knight::Knight(PieceColor color, int posX, int posY, QString iconPath, std::string name): ChessPiece(color, posX, posY, iconPath, name){};

bool Knight::isValidMove(int posX, int posY,  const std::vector<std::vector<ChessPiece*>>& board) {

}
