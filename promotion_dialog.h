#ifndef PROMOTION_DIALOG_H
#define PROMOTION_DIALOG_H

#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVariant>
#include <QVBoxLayout>

/**
 * @class PromotionDialog
 * @brief This class represents a dialog for pawn promotion.
 */
class PromotionDialog : public QDialog {
    Q_OBJECT

private:
    QString selectedOption; ///< The selected promotion option.

private slots:
    /**
     * @brief Handles the button click event. It sets the selected option and closes the dialog.
     */
    void onButtonClicked();

public:
    /**
     * @brief Constructs a new PromotionDialog object. Creates the dialog's layout. Connects to the dialog's signals.
     * @param playerColor The color of the player's pieces.
     * @param parent The parent widget.
     */
    PromotionDialog(const QString& playerColor, QWidget *parent);

    /**
     * @brief Gets the selected promotion option.
     * @return The selected option.
     */
    QString getSelectedOption();
};

#endif // PROMOTION_DIALOG_H
