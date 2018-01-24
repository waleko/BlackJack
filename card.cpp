#include "card.h"

Card::Card(int rG, QSize size, QPoint fin, QPoint st) // size here
{
    _v = 5;
    while(_v == 5)
        _v = random(10, rG++) + 2;
    _c = random(4, rG * 2 + 1);
    _spec = _c * 12 + _v;
    _size = size;
    setPixmap(genPixmap(_spec));
    _fin = fin;
    _s = st;
    mov = new QTimer();
    away = false;
    connect(mov, SIGNAL(timeout()), this, SLOT(move()));
    this->setPos(st);
    phase = 1;
    mov->start(10);
}
Card::Card(int v, int rG, QSize size, QPoint fin, QPoint st)
{
    _v = v;
    _c = random(4, rG * 2 + 1);
    _spec = _c * 12 + _v;
    _size = size;
    setPixmap(genPixmap(_spec));
    _fin = fin;
    _s = st;
    away = false;
    mov = new QTimer();
    connect(mov, SIGNAL(timeout()), this, SLOT(move()));
    this->setPos(st);
    phase = 1;
    mov->start(10);
}

Card::~Card() { }
int Card::random(int limit, int rndmGen)
{
    srand(rndmGen);
    int res = rand() % limit;
    return res;
}
QPixmap Card::genPixmap(int spec)
{
    QPixmap pix;
    QString sp;
    bool addtwo = false;
    switch(spec % 12)
    {
    case 2:
        sp = "jack";
        addtwo = true;
        break;
    case 3:
        sp = "queen";
        addtwo = true;
        break;
    case 4:
        sp = "king";
        addtwo = true;
        break;
    case 11:
        sp = "ace";
        break;
    default:
        sp = QString::number(spec % 12);
        break;
    }
    sp += "_of_";
    switch(spec / 12)
    {
    case 0:
        sp += "hearts";
        break;
    case 1:
        sp += "diamonds";
        break;
    case 2:
        sp += "clubs";
        break;
    case 3:
        sp += "spades";
        break;
    }
    if(addtwo)
        sp += "2";
    pix.load(":/cards/" + sp + ".png");
    return pix.scaled(_size);
}
int Card::value()
{
    return _v;
}
int Card::color()
{
    return _c;
}
int Card::spec()
{
    return _spec;
}

void Card::goAway()
{
    QTimer * newmov = new QTimer();
    connect(newmov, SIGNAL(timeout()), this, SLOT(move()));
    _s = this->pos().toPoint();
    _fin = QPoint(1000, 0);
    phase = 1;
    away = true;
    newmov->start(10);
}

void Card::move()
{
    if(phase > 55) {
        mov->stop();
        if(away)
            delete this;
        return;
    }
    this->moveBy((_fin.x() - _s.x()) / 50, (_fin.y() - _s.y()) / 50);
    phase++;
}
void Card::hideV()
{
    QPixmap p;
    p.load(":/hidden.png");
    setPixmap(p.scaled(_size));
}
void Card::showV()
{
    setPixmap(genPixmap(_spec));
}
