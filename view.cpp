#include "view.h"
#include "controller.h"
#include "./ui_view.h"

#include <QMainWindow>
#include <QWidget>
#include <QDebug>

View::View(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);
}

View::~View()
{
    delete ui;
}


void View::renderChessBoard() {
    QTableWidget *tableWidget = this->findChild<QTableWidget*>("chessBoardTable");

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
                label->setPixmap(QPixmap(""));
                label->setStyleSheet("background-color: transparent;");
                tableWidget->setCellWidget(row, col, label);
            }
        }

        tableWidget->repaint();
    } else {
        qDebug() << "Table widget not found!";
    }
}

void View::updateChessBoard(std::vector<std::vector<ChessPiece*>> chessBoardState) {
    QTableWidget *tableWidget = this->findChild<QTableWidget*>("chessBoardTable");

    if (tableWidget) {
        for(int row = 0; row < 8; ++row) {
            for(int col = 0; col < 8; ++col) {
                QTableWidgetItem* item = tableWidget -> item(row, col);

                ChessPiece* piece = chessBoardState[row][col];

                if(piece != nullptr) {
                    qDebug()<< piece->getIconPath();
                    QLabel *label = new QLabel();
                    label->setPixmap(QPixmap(piece->getIconPath()));
                    label->setStyleSheet("background-color: transparent;");

                    tableWidget->setCellWidget(row, col, label);
                } else {
                      qDebug() << "YSYSYYS!";
                    QLabel *oldLabel = qobject_cast<QLabel*>(tableWidget->cellWidget(row, col));
                    oldLabel->setPixmap(QPixmap());
                    // item->text().clear();
                    // item->setIcon(nullptr);
                    // QLabel *label = new QLabel();
                    // label->setPixmap(nullptr);
                    // label->setStyleSheet("background-color: transparent;");

                    // tableWidget->setCellWidget(row, col, label);
                }
            }
        }
        tableWidget->repaint();
    } else {
        qDebug() << "Table widget not found!";
    }
}

CController* View::getController() {
    return this->controller;
}

void View::setController(CController* controller) {
    this->controller = controller;
}


void View::on_chessBoardTable_cellClicked(int row, int column) {
    qDebug() << "lool "<< row << ", "<< column;
    this->getController()->onCellClicked(row, column);
}

