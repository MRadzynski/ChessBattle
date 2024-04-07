#include "promotion_dialog.h"

PromotionDialog::PromotionDialog(const QString& playerColor, QWidget *parent = nullptr) : QDialog(parent) {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QLabel *label = new QLabel(tr("You've promoted the Pawn!\nPlease, select the desired figure"));
    label->setAlignment(Qt::AlignCenter);

    QIcon iconRook(":/images/assets/rook_"+playerColor+".png");
    QIcon iconBishop(":/images/assets/bishop_"+playerColor+".png");
    QIcon iconKnight(":/images/assets/knight_"+playerColor+".png");
    QIcon iconQueen(":/images/assets/queen_"+playerColor+".png");

    int iconSize = 64;

    QHBoxLayout *buttonsLayout = new QHBoxLayout(this);

    QPushButton *buttonQueen = new QPushButton(iconQueen, "", this);
    buttonQueen->setIconSize(QSize(iconSize, iconSize));
    buttonQueen->setProperty("id", QVariant("queen"));
    connect(buttonQueen, &QPushButton::clicked, this, &PromotionDialog::onButtonClicked);

    QPushButton *buttonRook = new QPushButton(iconRook, "", this);
    buttonRook->setIconSize(QSize(iconSize, iconSize));
    buttonRook->setProperty("id", QVariant("rook"));
    connect(buttonRook, &QPushButton::clicked, this, &PromotionDialog::onButtonClicked);

    QPushButton *buttonBishop = new QPushButton(iconBishop, "", this);
    buttonBishop->setIconSize(QSize(iconSize, iconSize));
    buttonBishop->setProperty("id", QVariant("bishop"));
    connect(buttonBishop, &QPushButton::clicked, this, &PromotionDialog::onButtonClicked);

    QPushButton *buttonKnight = new QPushButton(iconKnight, "", this);
    buttonKnight->setIconSize(QSize(iconSize, iconSize));
    buttonKnight->setProperty("id", QVariant("knight"));
    connect(buttonKnight, &QPushButton::clicked, this, &PromotionDialog::onButtonClicked);

    mainLayout->addWidget(label);
    buttonsLayout->addWidget(buttonQueen);
    buttonsLayout->addWidget(buttonRook);
    buttonsLayout->addWidget(buttonBishop);
    buttonsLayout->addWidget(buttonKnight);

    mainLayout->addLayout(buttonsLayout);

    setLayout(mainLayout);
    setWindowTitle("Pawn Promotion");
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
}

QString PromotionDialog::getSelectedOption() {
    return this->selectedOption;
}

void PromotionDialog::onButtonClicked() {
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    if (button) {
        QString id = button->property("id").toString();
        selectedOption = id;

        accept();
    }
}
