#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ptime = new QTimer;
    connect((this->ptime),SIGNAL(timeout()),this,
            SLOT(updateTimeAndDsiplay()) );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTimeAndDsiplay()
{
  QTime current = QTime::currentTime();
  int t = baseTime.msecsTo(current);
  QTime showtime(0,0,0,0);
  showtime = showtime.addMSecs(t);
  showStr = showtime.toString("hh:mm:ss:zzz");
  ui->lcdNumber->display(showStr);
}
//开始
void MainWindow::on_btn_start_clicked()
{
    this->baseTime = QTime::currentTime() ;
    this->ptime->start(1);
    this->ui->btn_start->setEnabled(false);
}
//停止
void MainWindow::on_btn_stop_clicked()
{
    //点击停止时
  if( this->ui->btn_stop->text() == "停止")
  {
      this->ui->btn_stop->setText("清零");
      this->ui->btn_pause->setEnabled(false);
      this->ptime->stop();
  }
  //点击清零
  else
  {
      this->ui->lcdNumber->display("00:00:00:000");
      this->ui->textBrowser->clear();
      this->ui->btn_stop->setText("停止");
       this->ui->btn_pause->setEnabled(true);
      this->ui->btn_start->setEnabled(true);

  }
}

//暂停
void MainWindow::on_btn_pause_clicked()
{
  static QTime pauseTime;

  if( ui->btn_pause->text() == "暂停")
  {
      pauseTime = QTime::currentTime();
      ptime->stop();
      ui->btn_pause->setText("继续");
      ui->btn_start->setEnabled(false);
      ui->btn_stop->setEnabled(false);

  }
  else
  {
      QTime cut = QTime::currentTime();
      int t = pauseTime.msecsTo(cut);
      baseTime = baseTime.addMSecs(t);
      ptime->start(1);
      ui->btn_pause->setText("暂停");
      ui->btn_start->setEnabled(true);
      ui->btn_stop->setEnabled(true);
  }


}

//打点
void MainWindow::on_btn_log_clicked()
{
    ui->textBrowser->append(showStr);
}
