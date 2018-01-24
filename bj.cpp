#include "bj.h"
#include "ui_bj.h"
#include <QMessageBox>
#include <about.h>
#include <bet.h>
BJ::BJ(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BJ)
{
    ui->setupUi(this);
    oper = 0;
    QTime d = QTime::currentTime();
    randBuff = (d.msecsSinceStartOfDay() * 71236) % 8640000;
    inGame = false;
    all = 0;
    won = 0;
    //Graphics
    myscene = new myQGraphicsScene(10000, 100);
    f = new QMessageBox();
    bet = 100;
    //ui->graph->setScene(myscene);
    ///test
    //test = new QGraphicsView();
    //ui->graph->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //ui->graph->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    myscene->setSceneRect(-384, -288, 1024, 576);
    //test->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
    //myQGraphicsScene * o = new myQGraphicsScene();
    //test->setScene(myscene);
    ui->graph->setScene(myscene);
    //test->show();
    connect(myscene, SIGNAL(pl()), this, SLOT(pl()));
    connect(myscene, SIGNAL(min()), this, SLOT(min()));
    connect(myscene, SIGNAL(betnew()), this, SLOT(betnew()));
    connect(myscene, SIGNAL(game()), this, SLOT(game()));

    oper = 0;
    //p = new FocusRect();
    //myscene->addItem(p);

}
BJ::~BJ()
{
    delete ui;
}

void BJ::pl()
{
    pluscard();
}
void BJ::min()
{
    stay();
}

void BJ::betnew()
{
    Bet y;
    y.exec();
    if(y.success)
        myscene->setBet(y.bet);
}

void BJ::game()
{
    newgame();
}

Card * BJ::nc(QPoint f)
{
    int x = 150;
    Card * t = new Card(randBuff, QSize(x, 1.452 * x), f, QPoint(-400, -400));
    randBuff = ((randBuff + 239) * ++oper) % (randBuff + 566);
    return t;
}

Card * BJ::gc(bool ifPlayer)
{
    Card * u;
    if(!ifPlayer) {
        int x = 80 * BotCards.size();
        u = nc(QPoint(x, -259));
        myscene->addItem(u);
        BotCards.push_back(u);
    }
    else
    {
        int x = 80 * PlCards.size();
        u = nc(QPoint(x, 40));
        myscene->addItem(u);
        PlCards.push_back(u);
    }

    return u;
}
Card* BJ::cc(int v)
{
    int x = 150;
    int s = 80 * BotCards.size();
    Card * t = new Card(v, randBuff, QSize(x, 1.452 * x), QPoint(s, -259), QPoint(-400, -400));
    randBuff = ((randBuff + 239) * ++oper) % (randBuff + 566);
    myscene->addItem(t);
    BotCards.push_back(t);
    return t;
}
int BJ::valuessum(QVector<Card*> u)
{
    int sum = 0;
    for(int i = 0; i < u.size(); i++)
        sum += u[i]->value();
    return sum;
}
int BJ::balance()
{ return myscene->balance; }
void BJ::newgame()
{
    inGame = true;
    //Cleaning

    // Bet Proccessing
    bet = myscene->bet;
    if(bet + 1 > balance()) {
        alert("Ставка не может быть больше баланса!");
        //ui->bet->setText("");
        return;
    }
    if(bet <= 0) {
        alert("Ставка должна быть положительна!");
        //ui->bet->setText("");
        return;
    }
    changeBal(-bet - 1, true);
    myscene->hideNewGame();
    myscene->hideBet();
    hideall();
    // Game Proccess
    gc(true);
    gc(false);
    gc(true);
    gc(false);
    BotCards[1]->hideV();
    updsum(false);
    int sump = valuessum(PlCards);
    if(sump >= 21) {
        if(sump == 22)
            //ui->sump->setText("21");
            myscene->setSums(QString::number(21), myscene->sumd->toPlainText());
        victory();
        return;
    }
    int sumd = valuessum(PlCards);
    if(sumd >= 21) {
        if(sumd == 22)
            //ui->sump->setText("21");
            myscene->setSums(myscene->sump->toPlainText(), QString::number(21));
        defeat();
        return;
    }
    showoptions();
}
void BJ::hideall()
{
    for(int i = 0; i < PlCards.size(); i++)
        PlCards[i]->goAway();
    for(int i = 0; i < BotCards.size(); i++)
        BotCards[i]->goAway();
    PlCards.clear();
    BotCards.clear();
    /*for(int i = 0; i < PlCards.size(); i++)
        myscene->removeItem(PlCards[i]);
    for(int i = 0; i < BotCards.size(); i++)
        myscene->removeItem(BotCards[i]);*/
}

void BJ::showoptions()
{ myscene->showOptions(); }
void BJ::hideoptions()
{ myscene->hideOptions(); }
void BJ::changeBal(int v, bool add)
{
    if(!add)
        myscene->setBal(v);
    else
        myscene->setBal(balance() + v);
}

void BJ::updsum(bool rev)
{
    QString p = QString::number(valuessum(PlCards));
    QString d;
    if(rev) {
        int u = valuessum(BotCards);
        d = QString::number(u);
    }
    else
        d = "?";
    myscene->setSums(p, d);
}

void BJ::alert(QString text)
{   
    f->setText(text);
    f->exec();
    //QTimer * timer = new QTimer();
    //connect(timer, SIGNAL(timeout()), this, SLOT(hideF(timer)));
    //timer->start(3000);
}

void BJ::victory()
{
    BotCards[1]->showV();
    updsum(true);
    changeBal(2 * bet, true);
    //ui->bet->setEnabled(true);
    alert("Вы победили!");
    inGame = false;
    myscene->showNewGame();
    myscene->showBet();
    all++;
    won++;
}
void BJ::defeat()
{
    BotCards[1]->showV();
    updsum(true);
    //ui->bet->setEnabled(true);
    alert("Дилер выйграл");
    myscene->showNewGame();
    myscene->showBet();
    inGame = false;
    all++;
}

void BJ::pluscard()
{
    if(!inGame)
        return;
    hideoptions();
    gc(true);
    updsum(false);
    int sump = valuessum(PlCards);

    if(sump == 21)
        victory();
    else if(sump > 21)
        defeat();
    else
        showoptions();
}

void BJ::stay()
{
    if(!inGame)
        return;
    hideoptions();
    BotCards[1]->showV();

    // Types of game
    enum policy { STD, MULT, IMP };
    policy cur = STD;
    //---
    //Cheat code
    int chance; // in procents
    if(all == 0)
        chance = 15;
    else
        chance = 50 * won / all;
    chance %= 101;
    if(random(100) < chance)
        cur = IMP;
    int sump = valuessum(PlCards);
    switch(cur)
    {
    case STD:
        while(valuessum(BotCards) <= sump)
            gc(false);
        if(valuessum(BotCards) > 21)
            victory();
        else
            defeat();
        break;
    case MULT:
        while(valuessum(BotCards) < 17)
            gc(false);
        if(valuessum(BotCards) > 21 || valuessum(BotCards) <= sump)
            victory();
        else
            defeat();
        break;
    case IMP:
        while(valuessum(BotCards) < 9)
            gc(false);
        if(valuessum(BotCards) > sump) {
            defeat();
            return;
        }
        if(valuessum(BotCards) == 20 && sump >= 20) {
            victory();
            return;
        }
        int goal = random(21 - sump) + sump + 1;
        if(valuessum(BotCards) >= 10) {
            if(goal - valuessum(BotCards) == 1)
                goal++;
            cc(goal - valuessum(BotCards));
            defeat();
        }
        else {
            int v = 5;
            while(v == 5)
                v = random(9) + 2;
            cc(v);
            cc(21 - valuessum(BotCards));
        }
        break;
    }
    updsum(true);
}
int BJ::random(int limit)
{
    srand(randBuff);
    randBuff = ((randBuff + 239) * ++oper) % (randBuff + 566);
    int res = rand() % limit;
    return res;
}

void BJ::on_actionAbout_us_triggered()
{
    About r;
    r.exec();
}

/*void BJ::hideF(QTimer * timer)
{
    timer->stop();
    f->close();
}*/
