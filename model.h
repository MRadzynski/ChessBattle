#ifndef MODEL_H
#define MODEL_H

#include <QAbstractListModel>
#include <QStringList>

#include "game.h"

class CModel {
private:
    Game* game;

public:
    CModel();

    Game* getGame();

    void setGame(Game* game);

};

#endif // MODEL_H
