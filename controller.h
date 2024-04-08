#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"
#include "view.h"

#include <QObject>

class CController : public QObject {
    Q_OBJECT
private:
    CModel *model;
    View *view;

private slots:
    void updateMovesHistoryView(HistoryLog* lastMove);
    void updatePlayerTimerView(int playerTime, bool setBothTimers);

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

    void onSettingsButtonClickHandler();

    void onSurrenderButtonClickHandler();
};

#endif // CONTROLLER_H
