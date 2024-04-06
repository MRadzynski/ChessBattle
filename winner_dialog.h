#ifndef WINNER_DIALOG_H
#define WINNER_DIALOG_H

#include <QApplication>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class WinnerDialog : public QDialog {
    Q_OBJECT
public:
    WinnerDialog(const QString& winnerName, QWidget *parent);
};


#endif // WINNER_DIALOG_H
