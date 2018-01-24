#ifndef CARD_H
#define CARD_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QLabel>
#include <QPixmap>
#include <QSize>
#include <QTimer>
#include <QObject>

class Card : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Card(int rG, QSize size, QPoint fin, QPoint st);
    Card(int v, int rG, QSize size, QPoint fin, QPoint st);
    ~Card();
    int random(int limit, int rndmGen);
    QPixmap genPixmap(int spec);
    void hideV();
    void showV();

    int value();
    int color();
    int spec();
    void goAway();
private slots:
    void move();

private:
    int _v;
    int _c;
    int _spec;
    QSize _size;
    int phase;
    QPoint _fin;
    QPoint _s;
    QTimer * mov;
    bool away;
};

#endif // CARD_H
