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
        ChessPiece* selectedPiece = this->getModel()->getGame()->getSelectedPiece();
        int selectedPiecePosX = selectedPiece->getPosX();
        int selectedPiecePosY = selectedPiece->getPosY();
        std::vector<std::vector<ChessPiece*>> newChessBoardState = this->getModel()->getGame()->getChessBoard()->getChessBoardState();

        selectedPiece->setPosX(row);
        selectedPiece->setPosY(col);
        newChessBoardState[selectedPiecePosX][selectedPiecePosY] = nullptr;
        newChessBoardState[row][col] = selectedPiece;

        this->getModel()->getGame()->getChessBoard()->setChessBoardState(newChessBoardState);
        this->getModel()->getGame()->setSelectedPiece(nullptr);

        this->getView()->updateChessBoard(this->getModel()->getGame()->getChessBoard()->getChessBoardState());
    }

    this->getModel()->getGame()->getChessBoard()->displayChessBoardState();
}
