#include "king.h"

King::King(PieceColor color, int posX, int posY, QString iconPath, std::string name): ChessPiece(color, posX, posY, iconPath, name){};

bool King::isValidMove(int posX, int posY,  const std::vector<std::vector<ChessPiece*>>& board) {

}
