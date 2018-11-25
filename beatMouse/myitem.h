#ifndef MYITEM_H
#define MYITEM_H
#include<QGraphicsPixmapItem>
#include<QString>
#include<QGraphicsSceneMouseEvent>
#include"handler.h"
class myItem : public QGraphicsPixmapItem
{
public:
    myItem();
    void setPic(QString path);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
    void setMouse(bool m_mouse);
    bool isMouse();

    void setStart(bool m_start);
    bool isStart();

private:
    bool mouse;
    bool started;

};

#endif // MYITEM_H
