#ifndef TIMER_H
#define TIMER_H

#include <QWidget>
#include <QTimer>

class Timer : public QWidget {
    Q_OBJECT
private:
    unsigned int remainingTime;
    bool isRunning;
    int initTime;
    int playerIndex;
    QTimer* timer;

signals:
    void timeUpdated(int remainingTime, int playerIndex);

private slots:
    void updateTime();

public:
    Timer(int remainingTime, int playerIndex);

    void startTimer();

    void pauseTimer();

    void resetTimer();

    int getRemainingTime();

    bool getIsRunning();

    int getInitTime();

    int getPlayerIndex();

    QTimer* getTimer();

    void setRemainingTime(int remainingTime);

    void setIsRunning(bool isRunning);

    void setInitTime(int initTime);

    void setTimer(QTimer* timer);
};

#endif // TIMER_H
