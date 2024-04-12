#include "controller.h"
#include "game.h"

#include <QMessageBox>

Controller::Controller(Model* _model, View* _view, QObject* _parent = nullptr) : model(_model), view(_view) {
    connect(this->getModel()->getGame()->getPlayers()[0]->getTimer(), SIGNAL(timeUpdated(int,bool)), this, SLOT(updatePlayerTimerView(int,bool)));
    connect(this->getModel()->getGame()->getPlayers()[1]->getTimer(), SIGNAL(timeUpdated(int,bool)), this, SLOT(updatePlayerTimerView(int,bool)));
    connect(this->getModel()->getGame()->getMovesHistory(), SIGNAL(historyUpdated(HistoryLog*)), this, SLOT(updateMovesHistoryView(HistoryLog*)));
    connect(this->getModel()->getGame(), SIGNAL(gameEnded()), this, SLOT(displayWinnerDialog()));
};

Controller::~Controller() {};

void Controller::setupGame(){
    this->getModel()->getGame()->initGame();
    this->getView()->getChessboardView()->renderChessBoard();
    this->getView()->getChessboardView()->updateChessBoard(this->getModel()->getGame()->getChessBoard()->getChessBoardState());
}

void Controller::displayWinnerDialog() {
    QString winnerName = this->getModel()->getGame()->getWinner()->getName();
    
    this->getView()->getDialogsView()->displayWinnerDialog(winnerName);
}

void Controller::updateMovesHistoryView(HistoryLog* lastMove) {
    if(lastMove == nullptr) {
        this->getView()->getMovesHistoryView()->clearMovesHistory();
    } else {
        QString text = lastMove->posBefore + " -> " + lastMove->posAfter;
        this->getView()->getMovesHistoryView()->updateMovesHistoryList(lastMove->pieceIcon, text);
    }
}

void Controller::updatePlayerTimerView(int playerTime, bool setBothTimers) {
    if(setBothTimers) {
        this->getView()->getPlayerView()->updatePlayerTimer(playerTime, 0);
        this->getView()->getPlayerView()->updatePlayerTimer(playerTime, 1);
    } else {
        int playerIndex = 0;

        if(this->getModel()->getGame()->getCurrentPlayer()->getColor() == PieceColor::WHITE) {
            playerIndex = 1;
        }

        if(playerTime < 0) {
            this->onSurrenderButtonClickHandler();
            this->getModel()->getGame()->getPlayers()[playerIndex]->getTimer()->pauseTimer();
        } else {
            this->getView()->getPlayerView()->updatePlayerTimer(playerTime, playerIndex);
        }
    }
}

Model* Controller::getModel(){
    return this->model;
}

View* Controller::getView() {
    return this->view;
}

void Controller::setModel(Model* model) {
    this->model = model;
}

void Controller::setView(View* view) {
    this->view = view;
}

void Controller::onCellClicked(int row, int col) {
    this->getModel()->getGame()->makeMove(row, col);
    this->getView()->getChessboardView()->updateChessBoard(this->getModel()->getGame()->getChessBoard()->getChessBoardState());

    ChessPiece* kingPiece = nullptr;

    for(auto& row : this->getModel()->getGame()->getChessBoard()->getChessBoardState()) {
        for(auto& piece : row) {
            if(piece != nullptr && piece->getColor() == this->getModel()->getGame()->getCurrentPlayer()->getColor() && piece->getName().find("KG") != std::string::npos) {
                kingPiece = piece;
                break;
            }
        }
    }

    if(this->getModel()->getGame()->isCheck(kingPiece)) {

        std::vector<Game::Movement> validMoves = this->getModel()->getGame()->isCheckmate(kingPiece);

        if(this->getModel()->getGame()->getChessBoard()->getSelectedPiece() != nullptr) {
            this->getView()->getChessboardView()->highlightSelectedPieceInCheck(this->getModel()->getGame()->getChessBoard()->getSelectedPiece(), this->getModel()->getGame()->getChessBoard()->getChessBoardState(), validMoves);
        } else {
            this->getView()->getChessboardView()->unhighlightSelectedPiece();
        }
    } else {
        if(this->getModel()->getGame()->getChessBoard()->getSelectedPiece() != nullptr) {
            this->getView()->getChessboardView()->highlightSelectedPiece(this->getModel()->getGame()->getChessBoard()->getSelectedPiece(), this->getModel()->getGame()->getChessBoard()->getChessBoardState());
        } else {
            this->getView()->getChessboardView()->unhighlightSelectedPiece();
        }
    }
}

void Controller::onNewButtonClickHandler() {
    this->getModel()->getGame()->restartGame();

    this->getView()->getChessboardView()->updateChessBoard(this->getModel()->getGame()->getChessBoard()->getChessBoardState());
    this->getView()->getChessboardView()->unhighlightSelectedPiece();

    int initTimerTime = this->getModel()->getGame()->getPlayers()[0]->getTimer()->getInitTime();
    this->getView()->getPlayerView()->updatePlayerTimer(initTimerTime, 0);
    this->getView()->getPlayerView()->updatePlayerTimer(initTimerTime, 1);
}

void Controller::onQuitButtonClickHandler() {
    std::vector<std::vector<ChessPiece*>> chessBoard = this->getModel()->getGame()->getChessBoard()->getChessBoardState();

    for(int row = 0; row < 8; row++) {
        for(int col = 0; col < 8; col++) {
            if(chessBoard[row][col] != nullptr) {
                delete chessBoard[row][col];
            }
        }
    }

    QCoreApplication::exit(0);
}

void Controller::onSettingsButtonClickHandler() {
    if(this->getModel()->getGame()->getPlayers()[0]->getTimer()->getIsRunning() || this->getModel()->getGame()->getPlayers()[1]->getTimer()->getIsRunning()) {
        QMessageBox::information(nullptr, "Information", "You can't modify the settings if the game is still in progress.");
        return;
    }

    std::tuple<QString, QString, int> gameSettings = this->getView()->getDialogsView()->displaySettingsDialog();

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
        this->getView()->getPlayerView()->updatePlayersNames(playerBlackName, playerWhiteName);
    }
}

void Controller::onSurrenderButtonClickHandler() {
    if(!this->getModel()->getGame()->getPlayers()[0]->getTimer()->getIsRunning() && !this->getModel()->getGame()->getPlayers()[1]->getTimer()->getIsRunning()) {
        QMessageBox::information(nullptr, "Information", "You can't surrender before the game is started");
        return;
    }

    this->getModel()->getGame()->surrender();

    this->getView()->getChessboardView()->unhighlightSelectedPiece();

    QString winnerName = this->getModel()->getGame()->getWinner()->getName();

    this->getView()->getDialogsView()->displayWinnerDialog(winnerName);
}
