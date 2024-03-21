#include "timer.h"

Timer::Timer(int _actualTime): actualTime(_actualTime) {};

void Timer::start_timer() {

}

void Timer::reset_timer() {

}

void Timer::pause_timer() {

}

unsigned int Timer::getActualTime() {
    return this->actualTime;
}

void Timer::setActualTime(int actualTime) {
    this->actualTime = actualTime;
}
