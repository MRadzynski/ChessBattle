#include "bishop.h"

Bishop::Bishop(PieceColor color, int posX, int posY, QString iconPath, std::string name): ChessPiece(color, posX, posY, iconPath, name){};

bool Bishop::isValidMove(int posX, int posY,  const std::vector<std::vector<ChessPiece*>>& board) {

}
