#include "view.h"
#include "controller.h"
#include "model.h"

#include <QApplication>
#include <QTableWidget>
#include <QLabel>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    View w;
    w.show();

    CModel model = CModel();
    CController controller = CController(&model, &w);

    QTableWidget *tableWidget = w.findChild<QTableWidget*>("chessBoardTable");

    if (tableWidget) {
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setFocusPolicy(Qt::NoFocus);
        tableWidget->setSelectionMode(QAbstractItemView::NoSelection);

        for (int row = 0; row < tableWidget->rowCount(); ++row) {
            for (int col = 0; col < tableWidget->columnCount(); ++col) {
                QTableWidgetItem *item = new QTableWidgetItem();

                if((row+col) % 2 == 0) {
                    item->setBackground(QColor(242,242,242));
                } else {
                    item->setBackground(QColor(51,51,51));
                }

                tableWidget->setItem(row, col, item);

                QLabel *label = new QLabel();
                //label->setPixmap(QPixmap(":/images/assets/white_tower.png"));
                label->setPixmap(QPixmap(""));
                label->setStyleSheet("background-color: transparent;");
                tableWidget->setCellWidget(row, col, label);
            }
        }

        tableWidget->repaint();
    } else {
        qDebug() << "Table widget not found!";
    }




    return a.exec();
}
