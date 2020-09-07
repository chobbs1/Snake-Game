#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->init();
    snake.init();
    apple.init();

    snake.redrawSnake();
    apple.redrawApple();
    this->redrawScore();

    timer->start(GAME_CLK_SPEED);
}


void MainWindow::gameUpdate() {
    qDebug() << "Tick";

    if(snake.checkBodyCollision() || snake.checkWallCollision()) {
        qDebug() << "Game Over!";
        timer->stop();
    }

    if(snake.checkEatApple()) {
        apple.updatePosition();
        apple.redrawApple();
        this->updateScore();
        this->redrawScore();
    }

    snake.updatePosition();
    snake.redrawSnake();
}

void MainWindow::updateScore() {

}

void MainWindow::redrawScore() {

}


void MainWindow::init()
{
    // Setup UI Styles
    setStyleSheet("background-color:gray");
    setWindowTitle("Snake");
    setFixedSize(WIDTH_SCREEN,HEIGHT_SCREEN);

    // Setup score counter
    score = 0;
    this->redrawScore();

    // Setup game clock
    GAME_CLK_SPEED = 1000;
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(gameUpdate()));
}


void MainWindow::keyPressEvent(QKeyEvent *event) {
    int KEY_PRESS = event->key();

    if(KEY_PRESS == Qt::Key_Left && !snake.right) {
        snake.up = false;
        snake.down = false;
        snake.left = true;
        snake.right = false;
    } else if(KEY_PRESS == Qt::Key_Right && !snake.left) {
        snake.up = false;
        snake.down = false;
        snake.left = false;
        snake.right = true;
    } else if(KEY_PRESS == Qt::Key_Up && !snake.down) {
        snake.up = true;
        snake.down = false;
        snake.left = false;
        snake.right = false;
    } else if(KEY_PRESS == Qt::Key_Down && !snake.up) {
        snake.up = false;
        snake.down = true;
        snake.left = false;
        snake.right = false;
    }

    qDebug() << "Left" << snake.left;
    qDebug() << "Right" << snake.right;
    qDebug() << "Up" << snake.up;
    qDebug() << "Down" << snake.down;

}

MainWindow::~MainWindow()
{
    delete ui;
}

