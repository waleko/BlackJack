#include "myqgraphicsscene.h"

myQGraphicsScene::myQGraphicsScene(int bal = 10000, int b = 100)
{
    //sp
    first = true;
    /*QGraphicsRectItem * luc = new QGraphicsRectItem();
    QGraphicsRectItem * rdc = new QGraphicsRectItem();
    int x = 985;
    int y = 555;
    x = 0;
    y = 0;

    luc->setRect(-x, y, 1, 1);
    rdc->setRect(x, -y, 1, 1);
    this->addItem(luc);
    this->addItem(rdc);*/

    //main items
    QGraphicsPixmapItem * tab = new QGraphicsPixmapItem();
    tab->setPixmap(l(":/table.jpg"));
    //this->setSceneRect();
    this->addItem(tab);
    tab->setPos(-384, -288);
    plus = new QGraphicsPixmapItem();
    minus = new QGraphicsPixmapItem();
    betItm = new QGraphicsPixmapItem();
    newgame = new QGraphicsPixmapItem();
    plus->setPixmap(l(":/plus.png").scaled(60, 60));
    minus->setPixmap(l(":/minus.png").scaled(60, 60));
    betItm->setPixmap(l(":/bet.png").scaled(60, 60));
    newgame->setPixmap(l(":/newgame.png").scaled(60, 60));

    balance = bal;
    bet = b;
    bettext = new QGraphicsTextItem(QString::number(bet));
    baltext = new QGraphicsTextItem(QString::number(balance));
    sump = new QGraphicsTextItem("");
    sumd = new QGraphicsTextItem("");
    sump->setDefaultTextColor(Qt::white);
    sumd->setDefaultTextColor(Qt::white);
    baltext->setDefaultTextColor(Qt::white);
    bettext->setDefaultTextColor(Qt::white);
    this->addItem(sump);
    this->addItem(sumd);
    sumd->setPos(115, -224);
    sump->setPos(115, 224);
    showNewGame();
    showBet();
    //deb

}
QPixmap myQGraphicsScene::l(QString path)
{
    QPixmap o;
    o.load(path);
    return o;
}
void myQGraphicsScene::showOptions()
{
    this->addItem(minus);
    plus->setPos(125, -30);
    this->addItem(plus);
    minus->setPos(55, -30);
}

void myQGraphicsScene::hideOptions()
{
    this->removeItem(plus);
    this->removeItem(minus);
}

void myQGraphicsScene::showNewGame()
{
    this->addItem(newgame);
    this->addItem(baltext);
    newgame->setPos(125, -30);
    baltext->setPos(195, 0);
}

void myQGraphicsScene::hideNewGame()
{
    this->removeItem(newgame);
    this->removeItem(baltext);
}

void myQGraphicsScene::showBet()
{
    this->addItem(betItm);
    this->addItem(bettext);
    betItm->setPos(55, -30);
    bettext->setPos(5, 0);
}

void myQGraphicsScene::hideBet()
{
    this->removeItem(betItm);
    this->removeItem(bettext);
}

void myQGraphicsScene::setBet(int b)
{
    hideBet();
    bet = b;
    bettext = new QGraphicsTextItem(QString::number(bet));
    bettext->setDefaultTextColor(Qt::white);
    showBet();
    first = false;
}

void myQGraphicsScene::setBal(int bal)
{
    hideNewGame();
    balance = bal;
    baltext = new QGraphicsTextItem(QString::number(balance));
    baltext->setDefaultTextColor(Qt::white);
    showNewGame();
    first = false;
}

void myQGraphicsScene::setSums(QString p, QString d)
{
    this->removeItem(sump);
    this->removeItem(sumd);
    sump = new QGraphicsTextItem(p);
    sumd = new QGraphicsTextItem(d);
    sump->setDefaultTextColor(Qt::white);
    sumd->setDefaultTextColor(Qt::white);
    this->addItem(sump);
    this->addItem(sumd);
    sumd->setPos(115, -284);
    sump->setPos(115, 254);
}

void myQGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF p = event->scenePos();
    QGraphicsItem* itm = this->itemAt(p, QTransform());
    if(itm == plus)
        emit pl();
    else if(itm == minus)
        emit min();
    else if(itm == betItm || itm == bettext)
        emit betnew();
    else if(itm == newgame)
        emit game();
}
