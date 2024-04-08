#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "chess_board.h"
#include "moves_history.h"

#include <vector>

class Game {
private:
    std::vector<Player*> players;
    Player* currentPlayer;
    ChessBoard* chessBoard;
    Player* winner;
    MovesHistory* movesHistory;

public:
    Game();

    void initGame();

    void restartGame();

    void surrender();

    void endGame();

    void playTurn(Player* player);

    ChessPiece* promotePawn(ChessPiece* selectedPiece);

    ChessPiece* isCheck(ChessPiece* king);

    void switchPlayer();

    void makeMove(int row, int col);

    Player* getCurrentPlayer();

    std::vector<Player*> getPlayers();

    Player* getWinner();

    ChessBoard* getChessBoard();

    MovesHistory* getMovesHistory();

    void setCurrentPlayer(Player* player);

    void setPlayers(std::vector<Player*> players);

    void setWinner(Player* winner);

    void setChessBoard(ChessBoard* chessboard);

    void setMovesHistory(MovesHistory* movesHistory);
};

#endif // GAME_H
