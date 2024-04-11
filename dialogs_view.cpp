#include "dialogs_view.h"
#include "settings_dialog.h"
#include "winner_dialog.h"

DialogsView::DialogsView() {};

std::tuple<QString, QString, int>  DialogsView::displaySettingsDialog() {
    SettingsDialog settingsDialog(nullptr);
    int timerDuration;

    if (settingsDialog.exec() == QDialog::Accepted) {
        QString playerBlackName = settingsDialog.getPlayerBlackName();
        QString playerWhiteName = settingsDialog.getPlayerWhiteName();
        int timerDuration = settingsDialog.getTimerDuration();

        return std::make_tuple(playerBlackName, playerWhiteName, timerDuration);
    } else {
        return std::make_tuple("", "", -1);
    }
}

void DialogsView::displayWinnerDialog(const QString& winner) {
    WinnerDialog winnerDialog(winner, nullptr);

    winnerDialog.exec();
}
