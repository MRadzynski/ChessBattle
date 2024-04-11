#ifndef MODEL_H
#define MODEL_H

#include <QAbstractListModel>
#include <QStringList>

#include "game.h"

/**
 * @class CModel
 * @brief This class represents the model in the MVC architecture. It is responsible for managing the data in the application.
 */
class CModel {
private:
    Game* game; ///< Pointer to the Game object.

public:
    /**
     * @brief Constructs a new CModel object.
     */
    CModel();

    /**
     * @brief Gets the Game object.
     * @return Pointer to the Game object.
     */
    Game* getGame();

    /**
     * @brief Sets the Game object.
     * @param game Pointer to the new Game object.
     */
    void setGame(Game* game);
};

#endif // MODEL_H
