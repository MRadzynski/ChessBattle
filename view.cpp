#include "view.h"
#include "controller.h"
#include "./ui_view.h"
#include "winner_dialog.h"

#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include <QTime>

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


void View::displayWinnerDialog(const QString& winner) {
    WinnerDialog winnerDialog(winner, nullptr);

    winnerDialog.exec();
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
                ChessPiece* piece = chessBoardState[row][col];

                if(piece != nullptr) {
                    QLabel *label = new QLabel();
                    label->setPixmap(QPixmap(piece->getIconPath()));
                    label->setStyleSheet("background-color: transparent;");

                    tableWidget->setCellWidget(row, col, label);
                } else {
                    QLabel *oldLabel = qobject_cast<QLabel*>(tableWidget->cellWidget(row, col));
                    oldLabel->setPixmap(QPixmap());
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
    this->getController()->onCellClicked(row, column);
}

void View::highlightSelectedPiece(ChessPiece* selectedPiece, std::vector<std::vector<ChessPiece*>> chessBoard) {
    QTableWidget *tableWidget = this->findChild<QTableWidget*>("chessBoardTable");

    if(tableWidget) {
        for(int row = 0; row < 8; ++row) {
            for(int col = 0; col < 8; ++col) {
                QTableWidgetItem* item = tableWidget -> item(row, col);

                bool isValidMove = selectedPiece->isValidMove(row, col, chessBoard, selectedPiece->getColor());

                if(isValidMove) {
                    item->setBackground(QColor(244, 67, 54));
                }
            }
        }

        int row = selectedPiece->getPosX();
        int col = selectedPiece->getPosY();

        QTableWidgetItem* item = tableWidget -> item(row, col);
        item->setBackground(QColor(76, 175, 115));
    } else {
        qDebug() << "Table widget not found!";
    }
}

void View::unhighlightSelectedPiece() {
    QTableWidget *tableWidget = this->findChild<QTableWidget*>("chessBoardTable");

    if(tableWidget) {
        for(int row = 0; row < 8; ++row) {
            for(int col = 0; col < 8; ++col) {
                QTableWidgetItem* item = tableWidget -> item(row, col);

                if((row+col) % 2 == 0) {
                    item->setBackground(QColor(242,242,242));
                } else {
                    item->setBackground(QColor(51,51,51));
                }
            }
        }
    } else {
        qDebug() << "Table widget not found!";
    }
}

void View::updatePlayerTimer(int milliseconds, int playerIndex) {
    QTimeEdit timer;

    int hours = milliseconds / (1000 * 60 * 60);
    milliseconds -= hours * (1000 * 60 * 60);
    int minutes = milliseconds / (1000 * 60);
    milliseconds -= minutes * (1000 * 60);
    int seconds = milliseconds / 1000;
    milliseconds -= seconds * 1000;

    QTime newTime(hours, minutes, seconds, milliseconds);

    if(playerIndex == 0) {
        ui->player_1_timer->setTime(newTime);
    } else {
        ui->player_2_timer->setTime(newTime);
    }
}

void View::on_newGameBtn_clicked()
{
    this->getController()->onNewButtonClickHandler();
}

void View::on_quitBtn_clicked()
{
    this->getController()->onQuitButtonClickHandler();
}

void View::on_surrenderBtn_clicked()
{
    this->getController()->onSurrenderButtonClickHandler();
}

void View::on_player_1_timer_userTimeChanged(const QTime &time)
{
    qDebug() << time.second();
}

