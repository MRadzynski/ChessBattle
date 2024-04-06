#include "winner_dialog.h"

WinnerDialog::WinnerDialog(const QString& winnerName, QWidget *parent = nullptr) : QDialog(parent) {
    QLabel *label = new QLabel(tr("Congratulations, ") + winnerName + tr("! \nYou won the game!\n\n Click the 'New Game' button to play again."));
    label->setAlignment(Qt::AlignCenter);

    QPushButton *okButton = new QPushButton(tr("OK"));
    okButton->setFixedWidth(100);

    connect(okButton, &QPushButton::clicked, this, &WinnerDialog::accept);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addWidget(okButton, 0, Qt::AlignHCenter);

    setLayout(layout);
    setWindowTitle(tr("You won!"));
}
