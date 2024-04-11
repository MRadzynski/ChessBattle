#ifndef PLAYER_VIEW_H
#define PLAYER_VIEW_H

#include "ui_view.h"

/**
 * @class PlayerView
 * @brief This class represents the Player related UI. It is responsible for displaying proper player names and timers in the UI.
 */
class PlayerView : public QWidget {
private:
    Ui::View* ui;  ///< The pointer to the UI instance.

public:
    /**
     * @brief Constructs a new PlayerView object.
     */
    PlayerView(Ui::View* ui);

    /**
     * @brief Updates the players' names in the UI.
     * @param blackPlayerName The name of the black player.
     * @param whitePlayerName The name of the white player.
     */
    void updatePlayersNames(QString blackPlayerName, QString whitePlayerName);

    /**
     * @brief Updates the player's timer UI element.
     * @param remainingTime The remaining time on the timer.
     * @param playerIndex The index of the player.
     */
    void updatePlayerTimer(int remainingTime, int playerIndex);

    /**
     * @brief Gets the UI instance.
     * @return The UI instance.
     */
    Ui::View* getUI();

    /**
     * @brief Sets the UI instance.
     * @param ui The UI instance to set.
     */
    void setUI(Ui::View* ui);
};

#endif // PLAYER_VIEW_H
