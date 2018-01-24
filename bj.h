#ifndef BJ_H
#define BJ_H

#include <QMainWindow>
#include <card.h>
#include <QVector>
#include <QTime>
#include <focusrect.h>
#include <smallbutton.h>
#include <QGraphicsItemAnimation>
#include <myqgraphicsscene.h>
#include <QMessageBox>
//deb
#include <QGraphicsRectItem>

namespace Ui {
class BJ;
}

class BJ : public QMainWindow
{
    Q_OBJECT

public:
    explicit BJ(QWidget *parent = 0);
    ~BJ();
    void showoptions();
    void hideoptions();
    void hideall();
    void victory();
    void defeat();
    void newgame();
    void pluscard();
    void stay();
    void changeBal(int v, bool add);
    void updsum(bool rev);
public slots:
    void pl();
    void min();
    void betnew();
    void game();
private slots:

    void on_actionAbout_us_triggered();
    //void hideF(QTimer * timer);

private:
    Ui::BJ *ui;
    QVector <Card*> BotCards;
    QVector <Card*> PlCards;
    myQGraphicsScene * myscene;
    int oper;
    void alert(QString text);
    int balance();
    int randBuff;
    int bet;
    Card *nc(QPoint f);
    Card *gc(bool ifPlayer);
    Card *cc(int v);
    int valuessum(QVector<Card*> u);
    QGraphicsPixmapItem* plus;
    QGraphicsPixmapItem* minus;
    int random(int limit);
    SmallButton* k;
    //deb
    FocusRect * p;
    bool inGame;
    int all;
    int won;
    QGraphicsView * test;
    QMessageBox * f;
};

#endif // BJ_H
