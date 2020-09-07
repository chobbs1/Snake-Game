#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "snake.h"
#include "apple.h"

#define HEIGHT_SCREEN 800
#define WIDTH_SCREEN 1000

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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
    void init();
    void updateScore();
    void redrawScore();
    int score;
};
#endif // MAINWINDOW_H
