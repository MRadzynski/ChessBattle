#include "settings_dialog.h"

#include <QDialogButtonBox>
#include <QFormLayout>

SettingsDialog::SettingsDialog(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Game settings");

    QFormLayout* layout = new QFormLayout(this);

    playerNameBlackLineEdit = new QLineEdit(this);
    playerNameWhiteLineEdit = new QLineEdit(this);

    layout->addRow("Player Black Name:", playerNameBlackLineEdit);
    layout->addRow("Player White Name:", playerNameWhiteLineEdit);

    timerSpinBox = new QSpinBox(this);
    timerSpinBox->setRange(1, 59);
    timerSpinBox->setValue(5);
    timerSpinBox->setSuffix(" minutes");

    layout->addRow("Timer Duration:", timerSpinBox);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, this);
    layout->addRow(buttonBox);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &SettingsDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &SettingsDialog::reject);
}

QString SettingsDialog::getPlayerBlackName() {
    return this->playerNameBlackLineEdit->text();
}

QString SettingsDialog::getPlayerWhiteName() {
    return this->playerNameWhiteLineEdit->text();
}

int SettingsDialog::getTimerDuration() {
    return this->timerSpinBox->value();
}
