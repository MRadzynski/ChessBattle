#include "knight.h"

Knight::Knight(PieceColor color, int posX, int posY, QString iconPath, std::string name): ChessPiece(color, posX, posY, iconPath, name){};

bool Knight::isValidMove(int potentialPosX, int potentialPosY,  const std::vector<std::vector<ChessPiece*>>& board) {
    struct movement {
        int x;
        int y;
    };
    std::vector<movement> possibleMoves;

    //TODO: add playerColor in the params
    PieceColor playerColor = PieceColor::WHITE;

    if(this->getPosX()+2 < 8 && this->getPosY()+1 < 8){
        if(board[this->getPosX()+2][this->getPosY()+1] == nullptr || board[this->getPosX()+2][this->getPosY()+1]->getColor() != playerColor) {
            possibleMoves.push_back({this->getPosX()+2, this->getPosY()+1});
        }
    }


    if(this->getPosX()+2 < 8 && this->getPosY()-1 > -1){
        if(board[this->getPosX()+2][this->getPosY()-1] == nullptr || board[this->getPosX()+2][this->getPosY()-1]->getColor() != playerColor){
            possibleMoves.push_back({this->getPosX()+2, this->getPosY()-1});
        }
    }

    if(this->getPosX()-2 > -1 && this->getPosY()+1 < 8){
        if(board[this->getPosX()-2][this->getPosY()+1] == nullptr || board[this->getPosX()-2][this->getPosY()+1]->getColor() != playerColor){
            possibleMoves.push_back({this->getPosX()-2, this->getPosY()+1});
        }
    }

    if(this->getPosX()-2 > -1 && this->getPosY()-1 > -1){
        if(board[this->getPosX()-2][this->getPosY()-1] == nullptr || board[this->getPosX()-2][this->getPosY()-1]->getColor() != playerColor){
            possibleMoves.push_back({this->getPosX()-2, this->getPosY()-1});
        }
    }

    if(this->getPosX()-1 > -1 && this->getPosY()+2 < 8){
        if(board[this->getPosX()-1][this->getPosY()+2] == nullptr || board[this->getPosX()-1][this->getPosY()+2]->getColor() != playerColor){
            possibleMoves.push_back({this->getPosX()-1, this->getPosY()+2});
        }
    }

    if(this->getPosX()+1 < 8 && this->getPosY()+2 < 8){
        if(board[this->getPosX()+1][this->getPosY()+2] == nullptr || board[this->getPosX()+1][this->getPosY()+2]->getColor() != playerColor){
            possibleMoves.push_back({this->getPosX()+1, this->getPosY()+2});
        }
    }

    if(this->getPosX()-1 > -1 && this->getPosY()-2 > -1){
        if(board[this->getPosX()-1][this->getPosY()-2] == nullptr || board[this->getPosX()-1][this->getPosY()-2]->getColor() != playerColor){
            possibleMoves.push_back({this->getPosX()-1, this->getPosY()-2});
        }
    }

    if(this->getPosX()+1 < 8 && this->getPosY()-2 > -1){
        if(board[this->getPosX()+1][this->getPosY()-2] == nullptr || board[this->getPosX()+1][this->getPosY()-2]->getColor() != playerColor){
            possibleMoves.push_back({this->getPosX()+1, this->getPosY()-2});
        }
    }

    for(auto possibleMove : possibleMoves) {
        if(possibleMove.x == potentialPosX && possibleMove.y == potentialPosY) {
            return true;
        }
    }

    return false;
}
