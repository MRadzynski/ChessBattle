#include "timer.h"

Timer::Timer(int _remainingTime) : initTime(_remainingTime), isRunning(false), remainingTime(_remainingTime) {
    QTimer* timer = new QTimer();

    timer->setInterval(1000);
    this->timer = timer;

    connect(this->timer, SIGNAL(timeout()), this, SLOT(updateTime()));
};

Timer::~Timer() {
    delete this->timer;
}

void Timer::pauseTimer() {
    if (this->getIsRunning()) {
        this->setIsRunning(false);
        this->getTimer()->stop();
    }
}

void Timer::resetTimer() {
    this->getTimer()->stop();
    this->setIsRunning(false);
    this->setRemainingTime(this->initTime);
}

void Timer::startTimer() {
    if (!this->getIsRunning()) {
        this->setIsRunning(true);
        this->getTimer()->start();
    }
}

void Timer::updateTime() {
    if(this->getIsRunning()){
        int remainingTime = this->getRemainingTime() - 1000;
        this->setRemainingTime(remainingTime);

        emit timeUpdated(this->getRemainingTime(), false);
    }
}

int Timer::getInitTime() {
    return this->initTime;
}

bool Timer::getIsRunning() {
    return this->isRunning;
}

int Timer::getRemainingTime() {
    return this->remainingTime;
}

QTimer* Timer::getTimer(){
    return this->timer;
};

void Timer::setInitTime(int initTime) {
    this->initTime = initTime;

    emit timeUpdated(this->getInitTime(), true);
}

void Timer::setIsRunning(bool isRunning) {
    this->isRunning = isRunning;
}

void Timer::setRemainingTime(int remainingTime) {
    this->remainingTime = remainingTime;
}

void Timer::setTimer(QTimer* timer){
    this->timer = timer;
}
