#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    restartApp();
}

void MainWindow::restartApp() {
    this->init();
    snake.init(WIDTH_SCREEN,HEIGHT_SCREEN,INTERVAL);
    apple.init(WIDTH_SCREEN,HEIGHT_SCREEN,INTERVAL);

    repaint();

    timer->start(GAME_CLK_SPEED);
}


void MainWindow::gameUpdate() {

    if(snake.checkBodyCollision() || snake.checkWallCollision()) {
//        qDebug() << "Game Over!";
        timer->stop();
        QMessageBox::StandardButton response = QMessageBox::question(this,
            "Game Over!","Would you like to play again?",
            QMessageBox::Yes |  QMessageBox::No);
        if(response == QMessageBox::Yes) {
            restartApp();
        } else if(response == QMessageBox::No) {
            QApplication::quit();
        }
        return;
    };

    if(snake.checkEatApple(apple.x,apple.y)) {
        apple.updatePosition();
        score++;
        if(GAME_CLK_SPEED>50) {
            GAME_CLK_SPEED -= 2;
        }
        timer->stop();
        timer->start(GAME_CLK_SPEED);
    }

    snake.updatePosition();
    repaint();
}

void MainWindow::updateScore() {

}

void MainWindow::redrawScore() {

}


void MainWindow::init()
{
    // Setup UI Styles
    HEIGHT_SCREEN = 800;
    WIDTH_SCREEN = 1000;
    INTERVAL = 20;
    setFixedSize(WIDTH_SCREEN,HEIGHT_SCREEN);

    setWindowTitle("Snake");

    // Setup score counter
    score = 0;
    this->redrawScore();

    // Setup game clock
    GAME_CLK_SPEED = 100;
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

//    qDebug() << "Left" << snake.left;
//    qDebug() << "Right" << snake.right;
//    qDebug() << "Up" << snake.up;
//    qDebug() << "Down" << snake.down;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    QPainter scoreText(this);
    scoreText.setFont(QFont("Times", 20, QFont::Bold));
    scoreText.setPen(Qt::black);
    scoreText.drawText(QPoint(10,30), QStringLiteral("Score: %1").arg(score));

    QPainter appleImage(this);
    apple.redrawApple(&appleImage);

    QPainter snakeImage(this);
    snake.redrawSnake(&snakeImage);

}

