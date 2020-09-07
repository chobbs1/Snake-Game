#include "snake.h"
#include <QDebug>


Snake::Snake()
{

}

void Snake::init(int width,int height,int inter) {
    up = true;
    down = false;
    left = false;
    right = false;
    length = 3;

    interval = inter;
    x_max = width;
    y_max = height;

    head_x = x_max/2;
    head_y = y_max/2;

    qDebug() << "Head =" << head_x << "," << head_y;

    for(int i=0;i<length-1;i++) {
        x_body[i] = head_x;
        y_body[i] = head_y + (i+1)*interval;

        qDebug() << "Body =" << x_body[i] << "," << y_body[i];
    }



//    qDebug() << "Up = " << up;
//    qDebug() << "Down = " << down;
//    qDebug() << "Left = " << left;
//    qDebug() << "Right = " << right;
//    qDebug() << "X Max = " << x_max;
//    qDebug() << "Y Max = " << y_max;
//    qDebug() << "head_x = " << head_x;
//    qDebug() << "head_y = " << head_y;

}

bool Snake::checkEatApple()
{
    return false;
}

bool Snake::checkBodyCollision()
{
    return false;
}

bool Snake::checkWallCollision()
{
    return false;
}

void Snake::redrawSnake(QPainter *snakeImage)
{
    snakeImage->setBrush(QBrush(Qt::black));
    snakeImage->drawEllipse(QRect(head_x,head_y,interval,interval));

    snakeImage->setBrush(QBrush(Qt::green));
    for(int i=0;i<length-1;i++) {
        snakeImage->drawEllipse(QRect(x_body[i],y_body[i],interval,interval));
    }
}

void Snake::updatePosition()
{
//    qDebug() << "Update Position";
}
