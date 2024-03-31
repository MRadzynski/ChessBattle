#include "controller.h"

CController::CController(CModel* _model, View* _view, QObject* _parent = nullptr) : model(_model), view(_view) {};

CController::~CController() {};

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
    if(this->getModel()->getGame()->getSelectedPiece() == nullptr) {
        if(this->getModel()->getGame()->getChessBoard()->getChessBoardState()[row][col] != nullptr) {
            ChessPiece* selectedPiece = this->getModel()->getGame()->getChessBoard()->getChessBoardState()[row][col];
            this->getModel()->getGame()->setSelectedPiece(selectedPiece);
        }
    } else {
        int selectedPiecePosX = this->getModel()->getGame()->getSelectedPiece()->getPosX();
        int selectedPiecePosY = this->getModel()->getGame()->getSelectedPiece()->getPosY();

        std::vector<std::vector<ChessPiece*>> newChessBoardState = this->getModel()->getGame()->getChessBoard()->getChessBoardState();
        newChessBoardState[selectedPiecePosX][selectedPiecePosY] = nullptr;
        newChessBoardState[row][col] = this->getModel()->getGame()->getSelectedPiece();

        this->getModel()->getGame()->getChessBoard()->setChessBoardState(newChessBoardState);
        this->getView()->updateChessBoard(this->getModel()->getGame()->getChessBoard()->getChessBoardState());
        this->getModel()->getGame()->setSelectedPiece(nullptr);
    }

    if(this->getModel()->getGame()->getChessBoard()->getChessBoardState()[row][col] == nullptr) {
        qDebug() << "Empty cell";
    } else {
        qDebug() << "Piece cell";
    }
    qDebug() << "row: "<<row << " col: "<<col;
    // qDebug() << "piece: " << this->getModel()->getGame()->getChessBoard()->getChessBoardState()[row][col]->getPosX();
}
