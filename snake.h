#ifndef SNAKE_H
#define SNAKE_H

#define MAX_LEN 100
class Snake
{
public:
    Snake();
    void init();
    bool checkEatApple();
    bool checkBodyCollision();
    bool checkWallCollision();
    void redrawSnake();
    void updatePosition();
    int length,head_x,head_y;
    int x_body[MAX_LEN],y_body[MAX_LEN];
    bool up,down,left,right;


};

#endif // SNAKE_H
