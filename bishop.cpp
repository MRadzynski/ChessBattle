#include "bishop.h"

Bishop::Bishop(PieceColor color, int posX, int posY, QString iconPath, std::string name): ChessPiece(color, posX, posY, iconPath, name){};

bool Bishop::isValidMove(int potentialPosX, int potentialPosY,  const std::vector<std::vector<ChessPiece*>>& board, PieceColor playerColor) {
    struct movement {
        int x;
        int y;
    };
    std::vector<movement> possibleMoves;

    for(int row = this->getPosX()+1, col = this->getPosY()+1; row < 8 && col < 8; row++, col++) {
        if(board[row][col] == nullptr){
            possibleMoves.push_back({row, col});
        } else {
            if(board[row][col]->getColor() != playerColor) {
                possibleMoves.push_back({row, col});
            }
            break;
        }
    }

    for(int row = this->getPosX()-1, col = this->getPosY()-1; row > -1 && col > -1; row--, col--) {
        if(board[row][col] == nullptr){
            possibleMoves.push_back({row, col});
        } else {
            if(board[row][col]->getColor() != playerColor) {
                possibleMoves.push_back({row, col});
            }
            break;
        }
    }

    for(int row = this->getPosX()+1, col = this->getPosY()-1; row < 8 && col > -1; row++, col--) {
        if(board[row][col] == nullptr){
            possibleMoves.push_back({row, col});
        } else {
            if(board[row][col]->getColor() != playerColor) {
                possibleMoves.push_back({row, col});
            }
            break;
        }
    }

    for(int row = this->getPosX()-1, col = this->getPosY()+1; row > -1 && col < 8; row--, col++) {
        if(board[row][col] == nullptr){
            possibleMoves.push_back({row, col});
        } else {
            if(board[row][col]->getColor() != playerColor) {
                possibleMoves.push_back({row, col});
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
