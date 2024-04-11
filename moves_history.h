#ifndef MOVES_HISTORY_H
#define MOVES_HISTORY_H

#include <QWidget>

/**
 * @struct HistoryLog
 * @brief This struct represents a log of a move in the game.
 */
struct HistoryLog {
    QString pieceIcon; ///< The icon of the piece that was moved.
    QString posAfter; ///< The position of the piece after the move.
    QString posBefore; ///< The position of the piece before the move.
};

/**
 * @class MovesHistory
 * @brief This class represents the history of moves in the game.
 */
class MovesHistory : public QWidget {
    Q_OBJECT

private:
    std::vector<HistoryLog*> historyLogs; ///< The logs of the moves.

private slots:
    /**
     * @brief Updates the history with the last move by emitting the historyUpdated signal.
     * @param lastMove The last move that was made.
     */
    void updateHistory(HistoryLog* lastMove);

signals:
    /**
     * @brief Signal that is emitted when the history is updated.
     * @param lastMove The last move that was made.
     */
    void historyUpdated(HistoryLog* lastMove);

public:
    /**
     * @brief Constructs a new MovesHistory object.
     */
    MovesHistory();

    /**
     * @brief Adds a new log to the history.
     * @param historyLog The log to add.
     */
    void addNewLog(HistoryLog* historyLog);

    /**
     * @brief Clears the history logs.
     */
    void clearHistoryLogs();

    /**
     * @brief Gets the history logs.
     * @return The history logs.
     */
    std::vector<HistoryLog*> getHistoryLogs();

    /**
     * @brief Sets the history logs.
     * @param historyLogs The history logs to set.
     */
    void setHistoryLogs(std::vector<HistoryLog*> historyLogs);
};

#endif // MOVES_HISTORY_H
