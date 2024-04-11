#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>

#include "chess_piece.h"

class CController;

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
    CController* controller;
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
     * @brief Clears the moves history list in the UI.
     */
    void clearMovesHistory();

    /**
     * @brief Displays the settings dialog.
     * @return A tuple containing the black player's name, the white player's name, and the timer duration.
     */
    std::tuple<QString, QString, int> displaySettingsDialog();

    /**
     * @brief Displays the winner dialog.
     * @param winner The name of the winner.
     */
    void displayWinnerDialog(const QString& winner);

    /**
     * @brief Highlights the selected chess piece in the UI.
     * @param selectedPiece The selected chess piece.
     * @param chessBoard The current state of the chess board.
     */
    void highlightSelectedPiece(ChessPiece* selectedPiece, std::vector<std::vector<ChessPiece*>> chessBoard);

    /**
     * @brief Renders the chess board in the UI.
     */
    void renderChessBoard();

    /**
     * @brief Unhighlights the selected chess piece in the UI.
     */
    void unhighlightSelectedPiece();

    /**
     * @brief Updates the chess board in the UI.
     * @param chessBoardState The current state of the chess board.
     */
    void updateChessBoard(std::vector<std::vector<ChessPiece*>> chessBoardState);

    /**
     * @brief Updates the moves history list in the UI.
     * @param icon The icon representing the chess piece.
     * @param text The text describing the move.
     */
    void updateMovesHistoryList(QString icon, QString text);

 /**
     * @brief Updates the players' names in the UI.
     * @param blackPlayerName The name of the black player.
     * @param whitePlayerName The name of the white player.
     */
    void updatePlayersNames(QString blackPlayerName, QString whitePlayerName);

    /**
     * @brief Updates the player's timer UI element.
     * @param remainingTime The remaining time on the timer.
     * @param playerIndex The index of the player.
     */
    void updatePlayerTimer(int remainingTime, int playerIndex);

    /**
     * @brief Sets the controller instance.
     * @param controller The controller instance to set.
     */
    void setController(CController* controller);

    /**
     * @brief Gets the controller instance.
     * @return The controller instance.
     */
    CController* getController();
};

#endif // VIEW_H
