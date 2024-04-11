#include "player_view.h"
#include "view.h"

PlayerView::PlayerView(Ui::View* _ui) : ui(_ui) {};

void PlayerView::updatePlayersNames(QString blackPlayerName, QString whitePlayerName) {
    QLabel* blackPlayerNameField = this->getUI()->blackPlayerNameField;
    QLabel* whitePlayerNameField = this->getUI()->whitePlayerNameField;

    if(blackPlayerName != "") {
        if(blackPlayerNameField) {
            blackPlayerNameField->setText(blackPlayerName);
        } else {
            qDebug() << "QLabel widget for black player not found!";
        }
    }

    if(whitePlayerName != "") {
        if(whitePlayerNameField) {
            whitePlayerNameField->setText(whitePlayerName);
        } else {
            qDebug() << "QLabel widget for white player not found!";
        }
    }
}

void PlayerView::updatePlayerTimer(int milliseconds, int playerIndex) {
    QTimeEdit* blackPlayerTimer = this->getUI()->blackPlayerTimer;
    QTimeEdit* whitePlayerTimer = this->getUI()->whitePlayerTimer;

    int hours = milliseconds / (1000 * 60 * 60);
    milliseconds -= hours * (1000 * 60 * 60);
    int minutes = milliseconds / (1000 * 60);
    milliseconds -= minutes * (1000 * 60);
    int seconds = milliseconds / 1000;
    milliseconds -= seconds * 1000;

    QTime newTime(hours, minutes, seconds, milliseconds);

    if(playerIndex == 0) {
        if(blackPlayerTimer) {
            blackPlayerTimer->setTime(newTime);
        } else {
            qDebug() << "QTimeEdit widget for black player not found!";
        }
    } else {
        if(whitePlayerTimer) {
            whitePlayerTimer->setTime(newTime);
        } else {
            qDebug() << "QTimeEdit widget for white player not found!";
        }
    }
}


Ui::View* PlayerView::getUI() {
    return this->ui;
}

void PlayerView::setUI(Ui::View* ui) {
    this->ui = ui;
}
