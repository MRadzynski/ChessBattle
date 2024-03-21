#ifndef TIMER_H
#define TIMER_H

class Timer {
private:
    unsigned int actualTime;
public:
    Timer(int _actualTime);

    void start_timer();

    void pause_timer();

    void reset_timer();

    unsigned int getActualTime();

    void setActualTime(int actualTime);
};

#endif // TIMER_H
