#ifndef SNAKE_H
#define SNAKE_H

#include <QPainter>
#define MAX_LEN 100
class Snake
{
public:
    Snake();
    void init(int width,int height,int interval);
    bool checkEatApple(int a_x,int a_y);
    bool checkBodyCollision();
    bool checkWallCollision();
    void redrawSnake(QPainter *snakeImage);
    void updatePosition();
    int length,head_x,head_y;
    int x_body[MAX_LEN],y_body[MAX_LEN];
    bool up,down,left,right;
private:
    int x_max,y_max,interval;

};

#endif // SNAKE_H
