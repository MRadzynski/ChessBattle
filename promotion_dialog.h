#ifndef PROMOTION_DIALOG_H
#define PROMOTION_DIALOG_H

#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVariant>
#include <QVBoxLayout>

class PromotionDialog : public QDialog {
    Q_OBJECT

private:
    QString selectedOption = "";

private slots:
    void onButtonClicked();

public:
    PromotionDialog(const QString& playerColor, QWidget *parent);

    QString getSelectedOption();
};

#endif // PROMOTION_DIALOG_H
