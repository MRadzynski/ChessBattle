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
    View v;
    v.show();

    CModel* model = new CModel();

    CController* controller = new CController(model, &v, nullptr);

    v.setController(controller);

    controller->setupGame();

    return a.exec();
}
