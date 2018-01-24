#ifndef MYQGRAPHICSSCENE_H
#define MYQGRAPHICSSCENE_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QLabel>
#include <QPixmap>
#include <QSize>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

class myQGraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    myQGraphicsScene(int bal, int b);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void showOptions();
    void hideOptions();
    void showNewGame();
    void hideNewGame();
    void showBet();
    void hideBet();
    void setBet(int b);
    void setBal(int bal);
    int balance;
    int bet;
    void setSums(QString p, QString d);
    QGraphicsTextItem * sump;
    QGraphicsTextItem * sumd;
signals:
    void pl();
    void min();
    void betnew();
    void game();
private:
    QGraphicsPixmapItem * plus;
    QGraphicsPixmapItem * minus;
    QGraphicsPixmapItem * newgame;
    QGraphicsPixmapItem * betItm;
    QGraphicsTextItem * bettext;
    QGraphicsTextItem * baltext;
    QPixmap l(QString path);
    bool first;
};

#endif // MYQGRAPHICSSCENE_H
