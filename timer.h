#ifndef TIMER_H
#define TIMER_H

#include <QTimer>
#include <QWidget>

class Timer : public QWidget {
    Q_OBJECT
private:
    int initTime;
    bool isRunning;
    int remainingTime;
    QTimer* timer;

private slots:
    void updateTime();

signals:
    void timeUpdated(int remainingTime, bool setBothTimers);

public:
    Timer(int remainingTime);

    void pauseTimer();

    void resetTimer();

    void startTimer();

    int getInitTime();

    bool getIsRunning();

    int getRemainingTime();

    QTimer* getTimer();

    void setInitTime(int initTime);

    void setIsRunning(bool isRunning);

    void setRemainingTime(int remainingTime);

    void setTimer(QTimer* timer);
};

#endif // TIMER_H
