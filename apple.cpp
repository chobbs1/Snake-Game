#include "apple.h"
#include <QPaintEvent>
#include <QPainter>

Apple::Apple()
{

}

void Apple::init(int width,int height,int inter) {
    interval = inter;
    x_max = width;
    y_max = height;

    updatePosition();
}


void Apple::redrawApple(QPainter *appleImage) {
    appleImage->setBrush(QBrush(Qt::red));
    appleImage->drawEllipse(QRect(400,400,interval,interval));
}

void Apple::updatePosition() {
    x = rand() % x_max;
    y = rand() % y_max;

//    qDebug() << "X Max = " << x_max;
//    qDebug() << "Y Max = " << y_max;
//    qDebug() << "X = " << x;
//    qDebug() << "Y = " << y;
}

