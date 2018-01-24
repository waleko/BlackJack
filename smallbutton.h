#ifndef SMALLBUTTON_H
#define SMALLBUTTON_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QLabel>
#include <QPixmap>
#include <QSize>

class SmallButton : public QGraphicsPixmapItem
{
public:
    SmallButton(QPixmap pix);
};

#endif // SMALLBUTTON_H
