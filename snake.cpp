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

//    qDebug() << "Head =" << head_x << "," << head_y;

    for(int i=0;i<length-1;i++) {
        x_body[i] = head_x;
        y_body[i] = head_y + (i+1)*interval;

//        qDebug() << "Body =" << x_body[i] << "," << y_body[i];
    }



}

bool Snake::checkEatApple(int a_x,int a_y)
{
    if(head_x == a_x && head_y == a_y) {
//        qDebug() << "Eat Apple!";
        length++;
        return true;
    }
    return false;
}

bool Snake::checkBodyCollision()
{
    for(int i=0;i<length-1;i++) {
        if(head_x == x_body[i] && head_y == y_body[i]) {
            return true;
        }
    }
    return false;
}

bool Snake::checkWallCollision()
{

//    qDebug() << "Head X =" << head_x;
//    qDebug() << "Head Y =" << head_y;
//    qDebug() << "X Max: =" << x_max;
//    qDebug() << "Y Max: =" << y_max;

    if(head_x>=x_max) {
        return true;
    } else if(head_x<0) {
        return true;
    } else if(head_y>=y_max) {
        return true;
    } else if(head_y<0) {
        return true;
    }
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
    for(int i=length-1;i>0;i--) {
        x_body[i] = x_body[i-1];
        y_body[i] = y_body[i-1];
    }

    x_body[0] = head_x;
    y_body[0] = head_y;

    if(up) {
        head_y -= interval;
    } else if(down) {
         head_y += interval;
    } else if(left) {
        head_x -= interval;
    } else if(right) {
        head_x += interval;
    }


}
