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

class SettingsDialog : public QDialog {
    Q_OBJECT

private:
    QLineEdit* playerNameBlackLineEdit;
    QLineEdit* playerNameWhiteLineEdit;
    QSpinBox* timerSpinBox;

public:
    SettingsDialog(QWidget* parent);

    QString getPlayerBlackName();

    QString getPlayerWhiteName();

    int getTimerDuration();
};

#endif // SETTINGS_DIALOG_H
