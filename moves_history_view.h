#ifndef MOVES_HISTORY_VIEW_H
#define MOVES_HISTORY_VIEW_H

#include "ui_view.h"

/**
 * @class MovesHistoryView
 * @brief This class represents the moves history view. It is responsible for managing the moves history logs.
 */
class MovesHistoryView : public QWidget {
private:
    Ui::View* ui;  ///< The pointer to the UI instance.

public:
    /**
     * @brief Constructs a new MovesHistoryView object.
     */
    MovesHistoryView(Ui::View* ui);

    /**
     * @brief Clears the moves history list in the UI.
     */
    void clearMovesHistory();

    /**
     * @brief Updates the moves history list in the UI.
     * @param icon The icon representing the chess piece.
     * @param text The text describing the move.
     */
    void updateMovesHistoryList(QString icon, QString text);

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

#endif // MOVES_HISTORY_VIEW_H
