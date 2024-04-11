#ifndef TIMER_H
#define TIMER_H

#include <QTimer>
#include <QWidget>

/**
 * @class Timer
 * @brief This class represents a timer.
 */
class Timer : public QWidget {
    Q_OBJECT

private:
    int initTime; ///< The initial time set on the timer.
    bool isRunning; ///< Indicates whether the timer is currently running.
    int remainingTime; ///< The remaining time on the timer.
    QTimer* timer; ///< The QTimer object used for the timer.

private slots:
    /**
     * @brief Updates the time on the timer.
     */
    void updateTime();

signals:
    /**
     * @brief Signal emitted when the time is updated.
     * @param remainingTime The remaining time on the timer.
     * @param setBothTimers Whether to set both timers.
     */
    void timeUpdated(int remainingTime, bool setBothTimers);

public:
    /**
     * @brief Constructs a new Timer object. Sets the interval for 1 second and connects to signal.
     * @param remainingTime The remaining time to set on the timer.
     */
    Timer(int remainingTime);

    /**
     * @brief Pauses the timer.
     */
    void pauseTimer();

    /**
     * @brief Resets the timer.
     */
    void resetTimer();

    /**
     * @brief Starts the timer.
     */
    void startTimer();

    /**
     * @brief Gets the initial timer time.
     * @return The initial timer time.
     */
    int getInitTime();

    /**
     * @brief Gets the running status of the timer.
     * @return The running timer status.
     */
    bool getIsRunning();

    /**
     * @brief Gets the remaining timer time.
     * @return The remaining timer time.
     */
    int getRemainingTime();

    /**
     * @brief Gets the QTimer object used for the timer.
     * @return The QTimer object.
     */
    QTimer* getTimer();

    /**
     * @brief Sets the initial timer time.
     * @param initTime The initial timer time.
     */
    void setInitTime(int initTime);

    /**
     * @brief Sets the running status of the timer.
     * @param isRunning The running timer status.
     */
    void setIsRunning(bool isRunning);

    /**
     * @brief Sets the remaining timer time.
     * @param remainingTime The remaining timer time.
     */
    void setRemainingTime(int remainingTime);

    /**
     * @brief Sets the QTimer object used for the timer.
     * @param timer The QTimer object.
     */
    void setTimer(QTimer* timer);
};

#endif // TIMER_H
