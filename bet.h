#ifndef BET_H
#define BET_H

#include <QDialog>

namespace Ui {
class Bet;
}

class Bet : public QDialog
{
    Q_OBJECT

public:
    explicit Bet(QWidget *parent = 0);
    ~Bet();
    int bet;
    bool success;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Bet *ui;
};

#endif // BET_H
