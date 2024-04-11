#include "controller.h"

#include <QCoreApplication>
#include <QMessageBox>

CController::CController(CModel* _model, View* _view, QObject* _parent = nullptr) : model(_model), view(_view) {
    connect(this->getModel()->getGame()->getPlayers()[0]->getTimer(), SIGNAL(timeUpdated(int, bool)), this, SLOT(updatePlayerTimerView(int, bool)));
    connect(this->getModel()->getGame()->getPlayers()[1]->getTimer(), SIGNAL(timeUpdated(int, bool)), this, SLOT(updatePlayerTimerView(int, bool)));
    connect(this->getModel()->getGame()->getMovesHistory(), SIGNAL(historyUpdated(HistoryLog*)), this, SLOT(updateMovesHistoryView(HistoryLog*)));
};

CController::~CController() {};

void CController::setupGame(){
    this->getModel()->getGame()->initGame();
    this->getView()->renderChessBoard();
    this->getView()->updateChessBoard(this->getModel()->getGame()->getChessBoard()->getChessBoardState());
}

void CController::updateMovesHistoryView(HistoryLog* lastMove) {
    if(lastMove == nullptr) {
        this->getView()->clearMovesHistory();
    } else {
        QString text = lastMove->posBefore + " -> " + lastMove->posAfter;
        this->getView()->updateMovesHistoryList(lastMove->pieceIcon, text);
    }
}

void CController::updatePlayerTimerView(int playerTime, bool setBothTimers) {
    if(setBothTimers) {
        this->getView()->updatePlayerTimer(playerTime, 0);
        this->getView()->updatePlayerTimer(playerTime, 1);
    } else {
        int playerIndex = 0;

        if(this->getModel()->getGame()->getCurrentPlayer()->getColor() == PieceColor::WHITE) {
            playerIndex = 1;
        }

        if(playerTime < 0) {
            this->onSurrenderButtonClickHandler();
            this->getModel()->getGame()->getPlayers()[playerIndex]->getTimer()->pauseTimer();
        } else {
            this->getView()->updatePlayerTimer(playerTime, playerIndex);
        }
    }
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

void CController::onSettingsButtonClickHandler() {
    if(this->getModel()->getGame()->getPlayers()[0]->getTimer()->getIsRunning() || this->getModel()->getGame()->getPlayers()[1]->getTimer()->getIsRunning()) {
        QMessageBox::information(nullptr, "Information", "You can't modify the settings if the game is still in progress.");
        return;
    }

    std::tuple<QString, QString, int> gameSettings = this->getView()->displaySettingsDialog();

    QString playerBlackName = std::get<0>(gameSettings);
    QString playerWhiteName = std::get<1>(gameSettings);
    int timerDuration = std::get<2>(gameSettings);

    if(playerBlackName != "") {
        this->getModel()->getGame()->getPlayers()[0]->setName(playerBlackName);
    }

    if(playerWhiteName != "") {
        this->getModel()->getGame()->getPlayers()[1]->setName(playerWhiteName);
    }

    if(timerDuration != -1) {
        this->getModel()->getGame()->getPlayers()[0]->getTimer()->setInitTime(timerDuration * 60 * 1000);
        this->getModel()->getGame()->getPlayers()[0]->getTimer()->resetTimer();
        this->getModel()->getGame()->getPlayers()[1]->getTimer()->setInitTime(timerDuration * 60 * 1000);
        this->getModel()->getGame()->getPlayers()[1]->getTimer()->resetTimer();
    }

    if(playerBlackName != "" || playerWhiteName != "") {
        this->getView()->updatePlayersNames(playerBlackName, playerWhiteName);
    }
}

void CController::onSurrenderButtonClickHandler() {
    this->getModel()->getGame()->surrender();

    this->getView()->unhighlightSelectedPiece();

    QString winnerName = this->getModel()->getGame()->getWinner()->getName();

    this->getView()->displayWinnerDialog(winnerName);
}
