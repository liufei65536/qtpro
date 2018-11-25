#include "myscene.h"
#include<stdlib.h>
#include<QDebug>

myScene::myScene(QObject *parent) :QGraphicsScene(parent)
{

    for(int i=0;i<9;i++)
    {
        item[i] = new myItem;
        item[i]->setPos(i/3 * item[i]->boundingRect().width(),i%3*item[i]->boundingRect().height()) ;
        addItem(item[i]);
    }
    ptimer = new QTimer;
    connect(ptimer, SIGNAL(timeout()) ,this, SLOT (showMouse()) );

}

//随机显示老鼠
void myScene::showMouse()
{
    //清零老鼠
    for(int j = 0;j<9;j++)//
    {
        item[j]->setPic(":/bg/galaxy.png");
        item[j]->setMouse(false);
    }

    int count = rand()%3 + 1;

    int i = 0;
    for(i=0; i<count; i++)
    {
        int index = rand()%9 ;
        item[index]->setPic(":/mouse/dog.png"); // 变成老鼠
        item[index]->setMouse(true);
    }
}

void myScene::startGame()
{
    this->ptimer->start(1000);
    for(int j = 0;j<9;j++)//
    {
        item[j]->setStart(true);
    }
}

void myScene::pauseGame()
{
    ptimer->stop();
    for(int j = 0;j<9;j++)//
    {
        item[j]->setStart(false);
    }
}
void myScene::stopGame()
{
    ptimer->stop();
    //清零老鼠
    for(int j = 0;j<9;j++)
    {
        item[j]->setPic(":/bg/galaxy.png");
        item[j]->setMouse(false);
    }
    for(int j = 0;j<9;j++)//
    {
        item[j]->setStart(false);
    }
}
