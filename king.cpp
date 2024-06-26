#include "king.h"

King::King(PieceColor color, int posX, int posY, QString iconPath, std::string name) : ChessPiece(color, posX, posY, iconPath, name) {};

std::vector<std::pair<int, int>> King::getPotentialThreatenedPositions(ChessPiece* otherKing) {
    std::vector<std::pair<int, int>> threatenedPositions;

    for (int row = -1; row <= 1; ++row) {
        for (int col = -1; col <= 1; ++col) {
            if (row == 0 && col == 0)
                continue;

            int posX = otherKing->getPosX() + row;
            int posY = otherKing->getPosY() + col;

            if (posX >= 0 && posX < 8 && posY >= 0 && posY < 8) {
                threatenedPositions.push_back({posX, posY});
            }
        }
    }

    return threatenedPositions;
}

std::vector<std::pair<int, int>> King::getRestrictedKingMoves(ChessPiece* king, ChessPiece* otherKing) {
    std::vector<std::pair<int, int>> invalidMoves;
    std::vector<std::pair<int, int>> threatenedPositions = this->getPotentialThreatenedPositions(otherKing);

    for (int row = -1; row <= 1; ++row) {
        for (int col = -1; col <= 1; ++col) {
            if (row == 0 && col == 0)
                continue;

            int posX = king->getPosX() + row;
            int posY = king->getPosY() + col;

            if (posX >= 0 && posX < 8 && posY >= 0 && posY < 8) {
                bool threatened = false;

                for (const auto& threatenedPosition : threatenedPositions) {
                    if (posX == threatenedPosition.first && posY == threatenedPosition.second) {
                        threatened = true;
                        break;
                    }
                }

                if (threatened) {
                    invalidMoves.push_back({posX, posY});
                }
            }
        }
    }

    return invalidMoves;
}

bool King::isValidMove(int potentialPosX, int potentialPosY, const std::vector<std::vector<ChessPiece*>>& board, PieceColor playerColor) {
    struct movement {
        int x;
        int y;
    };
    std::vector<movement> possibleMoves;

    for(int row = -1; row < 2; row++) {
        for(int col = -1; col < 2; col++) {
            if(this->getPosX()+row < 8 && this->getPosX()+row > -1 && this->getPosY()+col < 8 && this->getPosY()+col > -1) {
                if(board[this->getPosX()+row][this->getPosY()+col] != nullptr && board[this->getPosX()+row][this->getPosY()+col]->getColor() == playerColor) {
                    continue;
                } else {
                    possibleMoves.push_back({this->getPosX()+row, this->getPosY()+col});
                }
            }
        }
    }

    std::vector<movement> restrictedMoves;

    PieceColor oppositePlayer = PieceColor::BLACK;

    if(playerColor == oppositePlayer) {
        oppositePlayer = PieceColor::WHITE;
    }

    for (auto& row : board) {
        for (auto& piece : row) {
            if(piece == nullptr || piece->getColor() == playerColor || piece == this) {
                continue;
            } else {
                if(piece->getName() == "BKG" || piece->getName() == "WKG") {
                    std::vector<std::pair<int, int>> restrictedKingMoves = this->getRestrictedKingMoves(this, piece);

                    for (auto& restrictedKingMove : restrictedKingMoves) {
                        restrictedMoves.push_back({restrictedKingMove.first, restrictedKingMove.second});
                    }
                } else if(piece->getName() == "BPN" || piece->getName() == "WPN") {
                    for (auto& possibleMove : possibleMoves) {
                        if(piece->getPosY() == possibleMove.y) continue;

                        if(piece->getName() == "WPN") {
                            if(piece->getPosX()-1 > -1 && piece->getPosX()-1 == possibleMove.x && (piece->getPosY()-1 > -1 && piece->getPosY()-1 == possibleMove.y || piece->getPosY()+1 < 8 && piece->getPosY()+1 == possibleMove.y)) {
                                restrictedMoves.push_back({possibleMove.x, possibleMove.y});
                            }
                        } else {
                            if(piece->getPosX()+1 < 8 && piece->getPosX()+1 == possibleMove.x && (piece->getPosY()-1 > -1 && piece->getPosY()-1 == possibleMove.y || piece->getPosY()+1 < 8 && piece->getPosY()+1 == possibleMove.y)) {
                                restrictedMoves.push_back({possibleMove.x, possibleMove.y});
                            }
                        }
                    }
                } else {
                    for (auto& possibleMove : possibleMoves) {
                        bool isValidMove = piece->isValidMove(possibleMove.x, possibleMove.y, board, oppositePlayer);

                        if(isValidMove) {
                            restrictedMoves.push_back({possibleMove.x, possibleMove.y});
                        }
                    }
                }
            }
        }
    }

    std::vector<movement> availableMoves;

    for(auto& possibleMove : possibleMoves) {
        bool foundInRestrictedMoves = false;

        for(auto& restrictedMove : restrictedMoves) {
            if(possibleMove.x == restrictedMove.x && possibleMove.y == restrictedMove.y) {
                foundInRestrictedMoves = true;
            }
        }

        if(!foundInRestrictedMoves) {
            availableMoves.push_back(possibleMove);
        }
    }

    for(auto& availableMove : availableMoves) {
        if(availableMove.x == potentialPosX && availableMove.y == potentialPosY) {
            return true;
        }
    }

    return false;
}
