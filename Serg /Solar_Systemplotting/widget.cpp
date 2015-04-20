#include "widget.h"
#include "helper.h"

#include <QPainter>
#include <QTimer>

//! [0]
Widget::Widget(Helper *helper, QWidget *parent, QLabel *_label)
    : QWidget(parent), helper(helper), label(_label)
{
    elapsed = 0;

    setFixedSize(parent->width()-120, parent->height());
}
//! [0]

//! [1]
void Widget::animate()
{
    update();
}
//! [1]

QString toString(double x, int cnt = 0) {
    QString tmp;
    tmp.setNum(x, 'F', cnt);
    return tmp;
}

//! [2]
void Widget::paintEvent(QPaintEvent *event)
{

    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    int tt;
    helper->paint(&painter, event, tt,this->width(),this->height());

    label->setText("Time = " + toString(tt/10));
    painter.end();
}
//! [2]
