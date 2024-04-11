#include "moves_history_view.h"
#include "view.h"

#include <QHBoxLayout>

MovesHistoryView::MovesHistoryView(Ui::View* _ui) : ui(_ui) {};

void MovesHistoryView::clearMovesHistory() {
    QListWidget* listWidget = this->getUI()->movesHistoryContainer;

    if(listWidget) {
        listWidget->clear();
    } else {
        qDebug() << "List widget not found!";
    }
}

void MovesHistoryView::updateMovesHistoryList(QString iconPath, QString text) {
    QListWidget* listWidget = this->getUI()->movesHistoryContainer;

    QLabel* iconLabel = new QLabel;
    QLabel* textLabel = new QLabel(text);
    QPixmap pixmap(iconPath);

    iconLabel->setPixmap(pixmap.scaled(32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation));

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(iconLabel);
    layout->addWidget(textLabel);
    layout->setContentsMargins(5, 5, 5, 5);

    QWidget* widget = new QWidget;
    widget->setFixedSize(150, 60);
    widget->setLayout(layout);
    widget->setStyleSheet("background-color: #8b5a2b; color: #f2f2f2;");

    QListWidgetItem* listItem = new QListWidgetItem;
    listItem->setSizeHint(QSize(150, 70));

    if(listWidget) {
        listWidget->insertItem(0, listItem);
        listWidget->setItemWidget(listItem, widget);
        listWidget->setSelectionMode(QAbstractItemView::NoSelection);
        listWidget->setFocusPolicy(Qt::NoFocus);
    } else {
        qDebug() << "List widget not found!";
    }
}


Ui::View* MovesHistoryView::getUI() {
    return this->ui;
}

void MovesHistoryView::setUI(Ui::View* ui) {
    this->ui = ui;
}
