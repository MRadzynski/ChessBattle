#ifndef PLAYER_H
#define PLAYER_H

#include "piece_color.h"
#include "timer.h"

/**
 * @class Player
 * @brief This class represents a player in the game.
 */
class Player {
private:
    PieceColor color; ///< The color of the player's pieces.
    QString name; ///< The name of the player.
    Timer* timer; ///< The timer showing the time available to the user

public:
    /**
     * @brief Constructs a new Player object.
     * @param _color The color of the player's pieces.
     * @param _name The name of the player.
     */
    Player(PieceColor _color, QString _name);

    /**
     * @brief Gets the color of the player's pieces.
     * @return The color of the pieces.
     */
    PieceColor getColor();

    /**
     * @brief Gets the name of the player.
     * @return The name of the player.
     */
    QString getName();

    /**
     * @brief Gets the player's timer.
     * @return The timer.
     */
    Timer* getTimer();

    /**
     * @brief Sets the color of the player's pieces.
     * @param color The new color of the pieces.
     */
    void setColor(PieceColor color);

    /**
     * @brief Sets the name of the player.
     * @param name The new name of the player.
     */
    void setName(QString name);

    /**
     * @brief Sets the player's timer.
     * @param timer The new timer.
     */
    void setTimer(Timer* timer);
};

#endif // PLAYER_H
