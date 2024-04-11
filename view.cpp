#include "./ui_view.h"
#include "controller.h"
#include "view.h"
#include "chessboard_view.h"

View::View(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::View)
{
    ui->setupUi(this);

    ChessboardView* chessboardView = new ChessboardView(ui);
    DialogsView* dialogsView = new DialogsView();
    MovesHistoryView* movesHistoryView = new MovesHistoryView(ui);
    PlayerView* playerView = new PlayerView(ui);

    this->chessboardView = chessboardView;
    this->dialogsView = dialogsView;
    this->movesHistoryView = movesHistoryView;
    this->playerView = playerView;
}

View::~View()
{
    delete chessboardView;
    delete dialogsView;
    delete movesHistoryView;
    delete playerView;
    delete ui;
}

ChessboardView* View::getChessboardView() {
    return this->chessboardView;
}

Controller* View::getController() {
    return this->controller;
}

DialogsView* View::getDialogsView() {
    return this->dialogsView;
}

MovesHistoryView* View::getMovesHistoryView() {
    return this->movesHistoryView;
}

PlayerView* View::getPlayerView() {
    return this->playerView;
}

void View::setChessboardView(ChessboardView* chessboardView) {
    this->chessboardView = chessboardView;
}

void View::setController(Controller* controller) {
    this->controller = controller;
}

void View::setDialogsView(DialogsView* dialogsView) {
    this->dialogsView = dialogsView;
}

void View::setMovesHistoryView(MovesHistoryView* movesHistoryView) {
    this->movesHistoryView = movesHistoryView;
}

void View::setPlayerView(PlayerView* playerView) {
    this->playerView = playerView;
}

void View::on_chessBoardTable_cellClicked(int row, int column) {
    this->getController()->onCellClicked(row, column);
}

void View::on_newGameBtn_clicked() {
    this->getController()->onNewButtonClickHandler();
}

void View::on_quitBtn_clicked() {
    this->getController()->onQuitButtonClickHandler();
}

void View::on_settingsBtn_clicked() {
    this->getController()->onSettingsButtonClickHandler();
}

void View::on_surrenderBtn_clicked() {
    this->getController()->onSurrenderButtonClickHandler();
}
