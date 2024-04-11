#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"
#include "view.h"

/**
 * @class Controller
 * @brief This class represents the controller in the MVC pattern.
 */
class Controller : public QObject {
    Q_OBJECT
private:
    Model *model; ///< The pointer to the model instance.
    View *view; ///< The pointer to the view instance.

private slots:
    /**
     * @brief Updates the moves history view.
     * @param lastMove The last move.
     */
    void updateMovesHistoryView(HistoryLog* lastMove);

    /**
     * @brief Updates the player timer view.
     * @param playerTime The player time.
     * @param setBothTimers Whether to set both timers.
     */
    void updatePlayerTimerView(int playerTime, bool setBothTimers);

public:
    /**
     * @brief Constructs a new Controller object. It connects the signals and slots.
     * @param _model The model.
     * @param _view The view.
     * @param _parent The parent QObject.
     */
    Controller(Model* _model, View* _view, QObject* _parent);
    
    /**
     * @brief Destroys the Controller object.
     */
    ~Controller();

    /**
     * @brief Sets up the game.
     */
    void setupGame();

    /**
     * @brief Gets the mode; instance.
     * @return The model instance.
     */
    Model* getModel();

    /**
     * @brief Gets the view instance.
     * @return The view instance.
     */
    View* getView();

    /**
     * @brief Sets the model instance.
     * @param model The model instance to set.
     */
    void setModel(Model* model);

    /**
     * @brief Sets the view instance.
     * @param view The view instance to set.
     */
    void setView(View* view);

    /**
    * @brief Handles the event when a cell is clicked.
    * @param row The row of the clicked cell.
    * @param col The column of the clicked cell.
    */
    void onCellClicked(int row, int col);

    /**
    * @brief Handles the event when the New Game button is clicked.
    */
    void onNewButtonClickHandler();

    /**
    * @brief Handles the event when the Quit button is clicked.
    */
    void onQuitButtonClickHandler();

    /**
    * @brief Handles the event when the Settings button is clicked.
    */
    void onSettingsButtonClickHandler();

    /**
    * @brief Handles the event when the Surrender button is clicked.
    */
    void onSurrenderButtonClickHandler();
};

#endif // CONTROLLER_H
