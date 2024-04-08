#ifndef MOVES_HISTORY_H
#define MOVES_HISTORY_H

#include <QWidget>

struct HistoryLog {
    QString pieceIcon;
    QString posAfter;
    QString posBefore;
};

class MovesHistory : public QWidget {
    Q_OBJECT

private:
    std::vector<HistoryLog*> historyLogs;

private slots:
    void updateHistory(HistoryLog* lastMove);

signals:
    void historyUpdated(HistoryLog* lastMove);

public:
    MovesHistory();

    void addNewLog(HistoryLog* historyLog);

    void clearHistoryLogs();

    std::vector<HistoryLog*> getHistoryLogs();

    void setHistoryLogs(std::vector<HistoryLog*> historyLogs);
};

#endif // MOVES_HISTORY_H
