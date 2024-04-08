#ifndef GAME_H
#define GAME_H

#include "chess_board.h"
#include "moves_history.h"
#include "player.h"

#include <vector>

class Game {
private:
    ChessBoard* chessBoard;
    Player* currentPlayer;
    MovesHistory* movesHistory;
    std::vector<Player*> players;
    Player* winner;

    QString getChessBoardCoords(int posX, int posY);

public:
    Game();

    void endGame();

    void initGame();

    ChessPiece* isCheck(ChessPiece* king);

    void makeMove(int row, int col);

    void playTurn(Player* player);

    ChessPiece* promotePawn(ChessPiece* selectedPiece);

    void restartGame();

    void surrender();

    void switchPlayer();

    ChessBoard* getChessBoard();

    Player* getCurrentPlayer();

    MovesHistory* getMovesHistory();

    std::vector<Player*> getPlayers();

    Player* getWinner();

    void setChessBoard(ChessBoard* chessboard);

    void setCurrentPlayer(Player* player);

    void setMovesHistory(MovesHistory* movesHistory);

    void setPlayers(std::vector<Player*> players);

    void setWinner(Player* winner);
};

#endif // GAME_H
