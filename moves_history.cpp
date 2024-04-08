#include "moves_history.h"

MovesHistory::MovesHistory() {};

void MovesHistory::addNewLog(HistoryLog* historyLog) {
    std::vector<HistoryLog*> newHistoryLogs = this->getHistoryLogs();
    newHistoryLogs.push_back(historyLog);

    this->setHistoryLogs(newHistoryLogs);
    this->updateHistory(historyLog);
}

void MovesHistory::clearHistoryLogs() {
    std::vector<HistoryLog*> emptyLogs;
    this->setHistoryLogs(emptyLogs);

    updateHistory(nullptr);
}

void MovesHistory::updateHistory(HistoryLog * lastMove) {
    emit historyUpdated(lastMove);
}

std::vector<HistoryLog*> MovesHistory::getHistoryLogs() {
    return this->historyLogs;
}

void MovesHistory::setHistoryLogs(std::vector<HistoryLog*> historyLogs) {
    this->historyLogs = historyLogs;
}
