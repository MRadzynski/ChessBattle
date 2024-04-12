#ifndef GAME_H
#define GAME_H

#include "chess_board.h"
#include "moves_history.h"
#include "player.h"

#include <QObject>
#include <vector>

/**
 * @class Game
 * @brief This class represents a chess game. It contains the chess board, the players, the current player, the moves history and the winner. It also contains the methods to play the game.
 */
class Game : public QObject {
    Q_OBJECT

private:
    ChessBoard* chessBoard; ///< The chess board.
    Player* currentPlayer; ///< The current player.
    MovesHistory* movesHistory; ///< The moves history.
    std::vector<Player*> players; ///< The players.
    Player* winner; ///< The winner.

    /**
     * @brief Ends the game.
     */
    void endGame();

    /**
     * @brief Translates the numeric coords to the chess moves naming standard.
     * @param posX The x position.
     * @param posY The y position.
     * @return The chess board coordinates e.g. A5, E7, D2.
     */
    QString getChessBoardCoords(int posX, int posY);

    /**
     * @brief Promotes a pawn.
     * @param selectedPiece The selected chess piece.
     * @return The promoted chess piece.
     */
    ChessPiece* promotePawn(ChessPiece* selectedPiece);

    /**
     * @brief Switches the current player.
     */
    void switchPlayer();

public:    
    struct Movement {
        int x;
        int y;
    };

    /**
     * @brief Constructs a new Game object.
     */
    Game();

    /**
     * @brief Initializes the game.
     */
    void initGame();

    /**
     * @brief Checks if the king is in check.
     * @param king The king chess piece.
     * @return The chess piece that is checking the king, or nullptr if the king is not in check.
     */
    ChessPiece* isCheck(ChessPiece* king);
    

    std::vector<Movement> isCheckmate(ChessPiece* king);

    /**
     * @brief Makes a move.
     * @param row The row to move to.
     * @param col The column to move to.
     */
    void makeMove(int row, int col);

    /**
     * @brief Plays a turn.
     * @param player The player whose turn it is.
     */
    void playTurn(Player* player);

    /**
     * @brief Restarts the game.
     */
    void restartGame();

    /**
     * @brief Surrenders the game.
     */
    void surrender();

    /**
     * @brief Gets the chess board.
     * @return The chess board.
     */
    ChessBoard* getChessBoard();

    /**
     * @brief Gets the current player.
     * @return The current player.
     */
    Player* getCurrentPlayer();

    /**
     * @brief Gets the moves history.
     * @return The moves history.
     */
    MovesHistory* getMovesHistory();

    /**
     * @brief Gets the players.
     * @return The players.
     */
    std::vector<Player*> getPlayers();

    /**
     * @brief Gets the winner.
     * @return The winner.
     */
    Player* getWinner();

    /**
     * @brief Sets the chess board.
     * @param chessboard The chess board.
     */
    void setChessBoard(ChessBoard* chessboard);

    /**
     * @brief Sets the current player.
     * @param player The current player.
     */
    void setCurrentPlayer(Player* player);

    /**
     * @brief Sets the moves history.
     * @param movesHistory The moves history.
     */
    void setMovesHistory(MovesHistory* movesHistory);

    /**
     * @brief Sets the players.
     * @param players The players.
     */
    void setPlayers(std::vector<Player*> players);

    /**
     * @brief Sets the winner.
     * @param winner The winner.
     */
    void setWinner(Player* winner);

signals:
    /**
     * @brief Signal emitted when the game has ended.
     */
    void gameEnded();
};

#endif // GAME_H
