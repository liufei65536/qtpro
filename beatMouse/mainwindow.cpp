#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"handler.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->sc = new myScene;
    this->ui->graphicsView->setScene(sc);
    connect(ui->btn_start,SIGNAL(clicked(bool)), sc,SLOT(startGame()));
    connect(ui->btn_pause, SIGNAL(clicked(bool)), sc, SLOT(pauseGame()));
    connect(ui->btn_stop, SIGNAL(clicked(bool)), sc, SLOT(stopGame()));
    score = 0;
    handler * hand = handler::getInstance();

    connect(hand, SIGNAL(beatMouse()), this, SLOT(uppdateScore()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    int ret = QMessageBox::question(this,"确定","确定关闭?", "是的", "不是");
    if(ret == 1)
    {
        event->ignore();
    }
}

void MainWindow::uppdateScore()
{
    score += 10;
    ui->lcdNumber->display(score);
}
