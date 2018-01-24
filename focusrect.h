#ifndef FOCUSRECT_H
#define FOCUSRECT_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QLabel>
#include <QPixmap>
#include <QSize>
#include <QGraphicsRectItem>

class FocusRect : public QGraphicsRectItem
{
public:
    FocusRect();
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
};

#endif // FOCUSRECT_H
