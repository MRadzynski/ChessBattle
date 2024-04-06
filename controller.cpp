#include "controller.h"

#include <QCoreApplication>

CController::CController(CModel* _model, View* _view, QObject* _parent = nullptr) : model(_model), view(_view) {
    connect(this->getModel()->getGame()->getPlayers()[0]->getTimer(), SIGNAL(timeUpdated(int, int)), this, SLOT(updatePlayerTimerView(int, int)));
    connect(this->getModel()->getGame()->getPlayers()[1]->getTimer(), SIGNAL(timeUpdated(int, int)), this, SLOT(updatePlayerTimerView(int, int)));
};

CController::~CController() {};

void CController::updatePlayerTimerView(int playerTime, int playerIndex) {
    if(playerTime < 0) {
        this->onSurrenderButtonClickHandler();
        this->getModel()->getGame()->getPlayers()[playerIndex]->getTimer()->pauseTimer();
    }

    view->updatePlayerTimer(playerTime, playerIndex);
}

void CController::setupGame(){
    this->getModel()->getGame()->initGame();
    this->getView()->renderChessBoard();
    this->getView()->updateChessBoard(this->getModel()->getGame()->getChessBoard()->getChessBoardState());
}

CModel* CController::getModel(){
    return this->model;
}

View* CController::getView() {
    return this->view;
}

void CController::setModel(CModel* model) {
    this->model = model;
}

void CController::setView(View* view) {
    this->view = view;
}

void CController::onCellClicked(int row, int col) {
    this->getModel()->getGame()->makeMove(row, col);
    this->getView()->updateChessBoard(this->getModel()->getGame()->getChessBoard()->getChessBoardState());

    if(this->getModel()->getGame()->getChessBoard()->getSelectedPiece() != nullptr) {
        this->getView()->highlightSelectedPiece(this->getModel()->getGame()->getChessBoard()->getSelectedPiece(), this->getModel()->getGame()->getChessBoard()->getChessBoardState());
    } else {
        this->getView()->unhighlightSelectedPiece();
    }
}

void CController::onNewButtonClickHandler() {
    this->getModel()->getGame()->restartGame();

    this->getView()->updateChessBoard(this->getModel()->getGame()->getChessBoard()->getChessBoardState());
    this->getView()->unhighlightSelectedPiece();

    int initTimerTime = this->getModel()->getGame()->getPlayers()[0]->getTimer()->getInitTime();
    this->getView()->updatePlayerTimer(initTimerTime, 0);
    this->getView()->updatePlayerTimer(initTimerTime, 1);
}

void CController::onQuitButtonClickHandler() {
    std::vector<std::vector<ChessPiece*>> chessBoard = this->getModel()->getGame()->getChessBoard()->getChessBoardState();

    for(int row = 0; row < 8; row++) {
        for(int col = 0; col < 8; col++) {
            if(chessBoard[row][col] != nullptr) {
                delete chessBoard[row][col];
            }
        }
    }

    //TODO: Cleanup memory before exit the app

    // for(int playerIndex = 0; playerIndex < 2; playerIndex++) {
    //     delete this->getModel()->getGame()->getPlayers()[playerIndex];
    // }

    // delete this->getModel()->getGame()->getChessBoard();
    // delete this->getModel()->getGame();
    // delete this->getModel();
    // delete this->getView();

    QCoreApplication::exit(0);
}

void CController::onSurrenderButtonClickHandler() {
    this->getModel()->getGame()->surrender();

    this->getView()->unhighlightSelectedPiece();

    QString winnerName;

    if(this->getModel()->getGame()->getWinner()->getColor() == PieceColor::BLACK) {
        winnerName = "BLACK";
    } else {
        winnerName = "WHITE";
    }

    this->getView()->displayWinnerDialog(winnerName);
}
