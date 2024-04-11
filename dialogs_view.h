#ifndef DIALOGS_VIEW_H
#define DIALOGS_VIEW_H

#include <QWidget>

/**
 * @class DialogsView
 * @brief This class represents the dialogs in the UI. It is responsible for showing the dialogs.
 */
class DialogsView : public QWidget {
public:
    /**
     * @brief Constructs a new DialogsView object.
     */
    DialogsView();

    /**
     * @brief Displays the settings dialog.
     * @return A tuple containing the black player's name, the white player's name, and the timer duration.
     */
    std::tuple<QString, QString, int> displaySettingsDialog();

    /**
     * @brief Displays the winner dialog.
     * @param winner The name of the winner.
     */
    void displayWinnerDialog(const QString& winner);
};

#endif // DIALOGS_VIEW_H
