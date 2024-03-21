#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "model.h"
#include "view.h"

class CController : public QObject {
    Q_OBJECT

public:
    CController(CModel* _model, QMainWindow* _view, QObject* _parent = nullptr) : model(_model), view(_view) {};
    ~CController(){};

private:
    CModel *model;
    QMainWindow *view;
};

#endif // CONTROLLER_H
