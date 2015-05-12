
#include "helper.h"

#include <QPainter>
#include <QPaintEvent>
#include <QWidget>
#include <QtCore/qmath.h>

//! [0]

int ttime = 0;

Helper::Helper()
{
    QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(1.0, QColor(0xa6, 0xce, 0x39));

    background = QBrush(QColor(164, 32, 64));
    circleBrush = QBrush(gradient);
    circlePen = QPen(Qt::black);
    circlePen.setWidth(1);
    textPen = QPen(Qt::white);
    textFont.setPixelSize(50);
}
//! [0]

int R = 100;
int cx = 250;
int cy = 250;
double x = 300;
double y = R;
double al = 0.05;
double xzz=300;
double yzz=300;
//! [1]
void Helper::paint(QPainter *painter, QPaintEvent *event, int &tt,int maxx,int maxy)
{
    ttime++;
    tt = ttime;


    painter->fillRect(event->rect(), background);

    double x1 = x+1;
    double y1 = x+1;
    x = x1; y = y1;
    xzz  =maxx/2;
    yzz =maxy/2;


    painter->save();
    painter->setBrush(circleBrush);
    painter->setPen(circlePen);

    painter->drawEllipse(QRectF(23+x, 23+y, 10 * 2, 10 * 2));
    painter->drawEllipse(QRectF(xzz, yzz, 20 * 2, 20 * 2));
    painter->restore();


//! [2]
 }
//! [3]
