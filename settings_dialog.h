#ifndef SETTINGS_DIALOG_H
#define SETTINGS_DIALOG_H

#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QVariant>
#include <QLineEdit>
#include <QSpinBox>

class SettingsDialog : public QDialog {
    Q_OBJECT

private:
    QLineEdit* playerNameWhiteLineEdit;
    QLineEdit* playerNameBlackLineEdit;
    QSpinBox* timerSpinBox;

public:
    SettingsDialog(QWidget* parent);

    QString getPlayerWhiteName();

    QString getPlayerBlackName();

    int getTimerDuration();
};

#endif // SETTINGS_DIALOG_H
