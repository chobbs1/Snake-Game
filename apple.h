#ifndef APPLE_H
#define APPLE_H

#include <cstdlib>
#include <QtDebug>
#include <QPaintEvent>
#include <QPainter>

class Apple
{
public:
    Apple();
    void init(int width,int height,int interval);
    int x,y;
    void updatePosition();
    void redrawApple(QPainter *appleImage);
private:
    int x_max,y_max;
    int interval;
};

#endif // APPLE_H
