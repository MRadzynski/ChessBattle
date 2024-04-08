#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>

#include "chess_piece.h"

class CController;

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

class View : public QMainWindow
{
    Q_OBJECT

public:
    View(QWidget *parent = nullptr);
    ~View();

    void renderChessBoard();

    void updateChessBoard(std::vector<std::vector<ChessPiece*>> chessBoardState);

    void setController(CController* controller);

    CController* getController();

    void highlightSelectedPiece(ChessPiece* selectedPiece, std::vector<std::vector<ChessPiece*>> chessBoard);

    void unhighlightSelectedPiece();

    void displayWinnerDialog(const QString& winner);

    std::tuple<QString, QString, int> displaySettingsDialog();

    void updatePlayerTimer(int remainingTime, int playerIndex);

    void updateMovesHistoryList(QString icon, QString text);

    void updatePlayersNames(QString blackPlayerName, QString whitePlayerName);

    void clearMovesHistory();

private slots:
    void on_chessBoardTable_cellClicked(int row, int column);

    void on_newGameBtn_clicked();

    void on_quitBtn_clicked();

    void on_surrenderBtn_clicked();

    void on_settingsBtn_clicked();

private:
    Ui::View *ui;
    CController* controller;
};
#endif // VIEW_H
