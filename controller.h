#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "model.h"
#include "view.h"

class CController : public QObject {
    Q_OBJECT

private slots:
    void updatePlayerTimerView(int playerTime);

public:
    CController(CModel* _model, View* _view, QObject* _parent);
    ~CController();

    void setupGame();

    CModel* getModel();

    View* getView();

    void setModel(CModel* model);

    void setView(View* view);

    void onCellClicked(int row, int col);

    void onNewButtonClickHandler();

    void onQuitButtonClickHandler();

    void onSurrenderButtonClickHandler();

private:
    CModel *model;
    View *view;
};

#endif // CONTROLLER_H
