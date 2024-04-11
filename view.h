#ifndef VIEW_H
#define VIEW_H

#include "chessboard_view.h"
#include "dialogs_view.h"
#include "moves_history_view.h"
#include "player_view.h"

#include <QMainWindow>

class Controller;

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

/**
 * @class View
 * @brief This class represents the view (in the MVC architecture) of the chess game. It is responsible for rendering the UI and handling user input.
 */
class View : public QMainWindow {
    Q_OBJECT

private:
    ChessboardView* chessboardView;
    Controller* controller;
    DialogsView* dialogsView;
    MovesHistoryView* movesHistoryView;
    PlayerView* playerView;
    Ui::View *ui;

private slots:
    /**
     * @brief Handles the event when a cell on the chess board is clicked.
     * @param row The row of the clicked cell.
     * @param column The column of the clicked cell.
     */
    void on_chessBoardTable_cellClicked(int row, int column);

    /**
     * @brief Handles the event when the new game button is clicked.
     */
    void on_newGameBtn_clicked();

    /**
     * @brief Handles the event when the quit button is clicked.
     */
    void on_quitBtn_clicked();

    /**
     * @brief Handles the event when the settings button is clicked.
     */
    void on_settingsBtn_clicked();

    /**
     * @brief Handles the event when the surrender button is clicked.
     */
    void on_surrenderBtn_clicked();

public:
    /**
     * @brief Constructs a new View object. Setup the UI.
     * @param parent The parent widget.
     */
    View(QWidget *parent = nullptr);

    /**
     * @brief Destroys the View object.
     */
    ~View();

    /**
     * @brief Gets the ChessboardView instance.
     * @return The ChessboardView instance.
     */
    ChessboardView* getChessboardView();

    /**
     * @brief Gets the controller instance.
     * @return The controller instance.
     */
    Controller* getController();

    /**
     * @brief Gets the DialogsView instance.
     * @return The DialogsView instance.
     */
    DialogsView* getDialogsView();

    /**
     * @brief Gets the MovesHistoryView instance.
     * @return The MovesHistoryView instance.
     */
    MovesHistoryView* getMovesHistoryView();

    /**
     * @brief Gets the PlayerView instance.
     * @return The PlayerView instance.
     */
    PlayerView* getPlayerView();

    /**
     * @brief Sets the ChessboardView instance.
     * @param chessboardView The ChessboardView instance to set.
     */
    void setChessboardView(ChessboardView* chessboardView);

    /**
     * @brief Sets the controller instance.
     * @param controller The controller instance to set.
     */
    void setController(Controller* controller);

    /**
     * @brief Sets the DialogsView instance.
     * @param dialogsView The DialogsView instance to set.
     */
    void setDialogsView(DialogsView* dialogsView);

    /**
     * @brief Sets the MovesHistoryView instance.
     * @param movesHistoryView The MovesHistoryView instance to set.
     */
    void setMovesHistoryView(MovesHistoryView* movesHistoryView);

    /**
     * @brief Sets the PlayerView instance.
     * @param playerView The PlayerView instance to set.
     */
    void setPlayerView(PlayerView* playerView);
};

#endif // VIEW_H
