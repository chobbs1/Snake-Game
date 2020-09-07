#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "snake.h"
#include "apple.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void paintEvent(QPaintEvent *e);
public slots:
    void gameUpdate();
protected:
    void keyPressEvent(QKeyEvent *event);
private:
    Ui::MainWindow *ui;
    Snake snake;
    Apple apple;
    int GAME_CLK_SPEED;
    QTimer *timer;
    void restartApp();
    void init();
    void updateScore();
    void redrawScore();
    int score;
    int HEIGHT_SCREEN,WIDTH_SCREEN,INTERVAL;
};
#endif // MAINWINDOW_H
