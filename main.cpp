#include "controller.h"
#include "model.h"
#include "view.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("Chess Battle");

    View v;
    v.show();

    Model* model = new Model();

    Controller* controller = new Controller(model, &v, nullptr);

    v.setController(controller);

    controller->setupGame();

    return app.exec();
}
