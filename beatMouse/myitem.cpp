#include<QPixmap>
#include<QDebug>
#include<QCursor>
#include "myitem.h"

myItem::myItem()
{
    this->setPixmap(QPixmap(":/bg/galaxy.png") ); // 传图片
    mouse = false;
    started = false;
    setCursor(QCursor(QPixmap(":/mouse/锤子1.png")));
}
void myItem::setPic(QString path)
{
    this->setPixmap(QPixmap(path) ); // 传图片

}
void myItem::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    setCursor(QCursor(QPixmap(":/mouse/锤子2.png")));
    if(isStart() )
    {
     handler * hand = handler::getInstance();
     if(isMouse())
     {
         hand->addScore();
         setPixmap(QPixmap(":/bg/galaxy.png"));
         mouse = false;
     }
    }
    else
    {
       qDebug()<<"0";
    }
}

void myItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(QCursor(QPixmap(":/mouse/锤子.png")));

}
void myItem::setMouse(bool m_mouse)
{
    mouse = m_mouse;
}

bool myItem::isMouse()
{
    return mouse;
}

void myItem::setStart(bool m_start)
{
    started = m_start;
}
bool myItem::isStart()
{
    return started;
}
