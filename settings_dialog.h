#ifndef SETTINGS_DIALOG_H
#define SETTINGS_DIALOG_H

#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QVariant>
#include <QVBoxLayout>

/**
 * @class SettingsDialog
 * @brief This class represents a dialog for game settings.
 */
class SettingsDialog : public QDialog {
    Q_OBJECT

private:
    QLineEdit* playerNameBlackLineEdit; ///< Line edit for the black player's name.
    QLineEdit* playerNameWhiteLineEdit; ///< Line edit for the white player's name.
    QSpinBox* timerSpinBox; ///< Spin box for the timer duration.

public:
    /**
     * @brief Constructs a new SettingsDialog object. Creates the dialog's layout. Connects to the dialog's signals.
     * @param parent The parent widget.
     */
    SettingsDialog(QWidget* parent);

    /**
     * @brief Gets the selected name for the black player.
     * @return The name of the black player.
     */
    QString getPlayerBlackName();

    /**
     * @brief Gets the selected name for the white player.
     * @return The name of the white player.
     */
    QString getPlayerWhiteName();

    /**
     * @brief Gets the selected duration for the timer.
     * @return The duration of the timer.
     */
    int getTimerDuration();
};

#endif // SETTINGS_DIALOG_H
