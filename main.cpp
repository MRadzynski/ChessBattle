#include "view.h"
#include "controller.h"
#include "model.h"

#include "promotion_dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("Chess Battle");

    View v;
    v.show();

    CModel* model = new CModel();

    CController* controller = new CController(model, &v, nullptr);

    v.setController(controller);

    controller->setupGame();

    // PromotionDialog dialog("white", nullptr);
    // dialog.exec();

    return app.exec();
}
