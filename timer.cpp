#include "timer.h"

#include <QTimer>

Timer::Timer(int _remainingTime, int _playerIndex): remainingTime(_remainingTime), playerIndex(_playerIndex), initTime(_remainingTime), isRunning(false) {
    QTimer* timer = new QTimer();

    timer->setInterval(1000);
    this->timer = timer;

    connect(this->timer, SIGNAL(timeout()), this, SLOT(updateTime()));
};

void Timer::updateTime() {
    if(this->getIsRunning()){
        int remainingTime = this->getRemainingTime() - 1000;
        this->setRemainingTime(remainingTime);

        emit timeUpdated(this->getRemainingTime(), this->getPlayerIndex());
    }
}

void Timer::startTimer() {
    if (!this->getIsRunning()) {
        this->setIsRunning(true);
        this->getTimer()->start();
    }
}

void Timer::resetTimer() {
    this->getTimer()->stop();
    this->setIsRunning(false);
    this->setRemainingTime(this->initTime);
}

void Timer::pauseTimer() {
    if (this->getIsRunning()) {
        this->setIsRunning(false);
        this->getTimer()->stop();
    }
}

int Timer::getRemainingTime() {
    return this->remainingTime;
}

bool Timer::getIsRunning() {
    return this->isRunning;
}

int Timer::getPlayerIndex() {
    return this->playerIndex;
}

int Timer::getInitTime() {
    return this->initTime;
}

QTimer* Timer::getTimer(){
    return this->timer;
};

void Timer::setRemainingTime(int remainingTime) {
    this->remainingTime = remainingTime;
}

void Timer::setIsRunning(bool isRunning) {
    this->isRunning = isRunning;
}

void Timer::setTimer(QTimer* timer){
    this->timer = timer;
}
