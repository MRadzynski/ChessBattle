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

private:
    CController* controller;
    Ui::View *ui;

private slots:
    void on_chessBoardTable_cellClicked(int row, int column);

    void on_newGameBtn_clicked();

    void on_quitBtn_clicked();

    void on_settingsBtn_clicked();

    void on_surrenderBtn_clicked();

public:
    View(QWidget *parent = nullptr);

    ~View();

    void clearMovesHistory();

    std::tuple<QString, QString, int> displaySettingsDialog();

    void displayWinnerDialog(const QString& winner);

    void highlightSelectedPiece(ChessPiece* selectedPiece, std::vector<std::vector<ChessPiece*>> chessBoard);

    void renderChessBoard();

    void unhighlightSelectedPiece();

    void updateChessBoard(std::vector<std::vector<ChessPiece*>> chessBoardState);

    void updateMovesHistoryList(QString icon, QString text);

    void updatePlayersNames(QString blackPlayerName, QString whitePlayerName);

    void updatePlayerTimer(int remainingTime, int playerIndex);

    void setController(CController* controller);

    CController* getController();
};

#endif // VIEW_H
