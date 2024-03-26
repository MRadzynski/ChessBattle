#include "king.h"

King::King(PieceColor color, int posX, int posY, QString iconPath): ChessPiece(color, posX, posY, iconPath){};

bool King::isValidMove(int posX, int posY,  const std::vector<std::vector<ChessPiece*>>& board) {

}
