#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>

#include "chess_piece.h"

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

private:
    Ui::View *ui;
};
#endif // VIEW_H
