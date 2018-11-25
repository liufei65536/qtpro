#ifndef MYSCENE_H
#define MYSCENE_H

#include <QObject>
#include<QGraphicsScene>
#include<QTimer>
#include"myitem.h"

class myScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit myScene(QObject *parent = nullptr);

signals:

public slots:
    void showMouse();
    void startGame();
    void pauseGame();
    void stopGame();
private:
    myItem * item[9];
    QTimer * ptimer;
};

#endif // MYSCENE_H
