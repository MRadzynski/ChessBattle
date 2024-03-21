#include "view.h"
#include "./ui_view.h"

#include <QMainWindow>
#include <QWidget>

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
