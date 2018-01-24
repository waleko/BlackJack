#include "bet.h"
#include "ui_bet.h"

Bet::Bet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bet)
{
    ui->setupUi(this);
    success = false;
}

Bet::~Bet()
{
    delete ui;
}

void Bet::on_buttonBox_accepted()
{
    bet = ui->line->text().toInt();
    success = true;
    close();
}

void Bet::on_buttonBox_rejected()
{
    close();
}
