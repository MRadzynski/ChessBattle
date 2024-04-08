#ifndef MOVES_HISTORY_H
#define MOVES_HISTORY_H

#include <QWidget>

struct HistoryLog {
    QString posBefore;
    QString posAfter;
    QString pieceIcon;
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

    std::vector<HistoryLog*> getHistoryLogs();

    void setHistoryLogs(std::vector<HistoryLog*> historyLogs);

    void addNewLog(HistoryLog* historyLog);

    void clearHistoryLogs();
};

#endif // MOVES_HISTORY_H
