#include "bishop.h"

Bishop::Bishop(PieceColor color, int posX, int posY, QString iconPath): ChessPiece(color, posX, posY, iconPath){};

bool Bishop::isValidMove(int posX, int posY,  const std::vector<std::vector<ChessPiece*>>& board) {

}
