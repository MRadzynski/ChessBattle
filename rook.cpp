#include "rook.h"

Rook::Rook(PieceColor color, int posX, int posY, QString iconPath, std::string name) : ChessPiece(color, posX, posY, iconPath, name) {};

bool Rook::isValidMove(int potentialPosX, int potentialPosY,  const std::vector<std::vector<ChessPiece*>>& board, PieceColor playerColor) {
    struct movement {
        int x;
        int y;
    };
    std::vector<movement> possibleMoves;

    for(int row = this->getPosX()+1; row < 8; row++) {
        if(board[row][this->getPosY()] == nullptr){
            possibleMoves.push_back({row, this->getPosY()});
        } else {
            if(board[row][this->getPosY()]->getColor() != playerColor) {
                possibleMoves.push_back({row, this->getPosY()});
            }
            break;
        }
    }

    for(int row = this->getPosX()-1; row > -1; row--) {
        if(board[row][this->getPosY()] == nullptr){
            possibleMoves.push_back({row, this->getPosY()});
        } else {
            if(board[row][this->getPosY()]->getColor() != playerColor) {
                possibleMoves.push_back({row, this->getPosY()});

            }
            break;
        }
    }

    for(int col = this->getPosY()+1; col < 8; col++) {
        if(board[this->getPosX()][col] == nullptr){
            possibleMoves.push_back({this->getPosX(), col});
        } else {
            if(board[this->getPosX()][col]->getColor() != playerColor) {
                possibleMoves.push_back({this->getPosX(), col});
            }
            break;
        }
    }

    for(int col = this->getPosY()-1; col > -1; col--) {
        if(board[this->getPosX()][col] == nullptr){
            possibleMoves.push_back({this->getPosX(), col});
        } else {
            if(board[this->getPosX()][col]->getColor() != playerColor) {
                possibleMoves.push_back({this->getPosX(), col});
            }
            break;
        }
    }

    for(auto possibleMove : possibleMoves) {
        if(possibleMove.x == potentialPosX && possibleMove.y == potentialPosY) {
            return true;
        }
    }

    return false;
}
