#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QCloseEvent>
#include"myscene.h"
#include"handler.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void closeEvent(QCloseEvent * event );
private slots:
    void uppdateScore();
private:
    Ui::MainWindow *ui;
    myScene * sc;
    int score;
};

#endif // MAINWINDOW_H
