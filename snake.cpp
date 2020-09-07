#include "snake.h"
#include <QDebug>


Snake::Snake()
{

}

void Snake::init() {
    up = true;
    down = false;
    left = false;
    right = false;
    length = 3;

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

void Snake::redrawSnake()
{

}

void Snake::updatePosition()
{
//    qDebug() << "Update Position";
}
