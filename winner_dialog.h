#ifndef WINNER_DIALOG_H
#define WINNER_DIALOG_H

#include <QApplication>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

/**
 * @class WinnerDialog
 * @brief This class represents a dialog for displaying the winner.
 */
class WinnerDialog : public QDialog {
    Q_OBJECT

public:
    /**
     * @brief Constructs a new WinnerDialog object. Creates a dialog with the name of the winner.
     * @param winnerName The name of the winner.
     * @param parent The parent widget.
     */
    WinnerDialog(const QString& winnerName, QWidget *parent);
};

#endif // WINNER_DIALOG_H
