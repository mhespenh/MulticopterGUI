/////////////////////////////////////////////////////////////////////////////////
// altimeter.cpp - Multicopter Simulator Widgets - Altimeter
// Roy Cole
// This is the class definition for the altimeter. It is modeled after
// real aircraft heading indicators and will function the same way. It is an
// analoge representation of the digital readout
/////////////////////////////////////////////////////////////////////////////////
#include <QtGui>

#include "altimeter.h"


Altimeter::Altimeter(QWidget *parent)

    : QWidget(parent)

{

    QTimer *timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

    timer->start(10);


    setWindowTitle(tr("Altimeter"));

    QPalette pal(palette());
    pal.setColor(QPalette::Background,Qt::black);
    setPalette(pal);

    resize(200, 200);
    altitude = 0;

}

void Altimeter::paintEvent(QPaintEvent *)
{
    static const QPoint pointer[7] ={
        QPoint(3,8),
        QPoint(-3,8),
        QPoint(-3,-40),
        QPoint(-7,-40),
        QPoint(0,-70),
        QPoint(7,-40),
        QPoint(3,-40)
    };


    QColor c_black(0, 0, 0);
    QColor c_white(255, 255, 255, 255);
    //QColor c_white(0, 127, 127, 191);
    int side = qMin(width(), height());

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);

    painter.translate(width() / 2, height() / 2);

    painter.scale(side / 200.0, side / 200.0);



    painter.setPen(Qt::NoPen);

    painter.setBrush(c_white);
    painter.drawRect(20,8,40,16);

    painter.save();

    //painter.rotate(18);
    //painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    //painter.drawConvexPolygon(hourHand, 3);
    painter.restore();



    painter.setPen(c_white);

    for (int i = 0; i < 12; ++i) {
        painter.drawLine(84, 0, 96, 0);
        painter.drawText(QPoint(70,0), QString::number(i*2,10));
        painter.rotate(30.0);
    }

    painter.setPen(Qt::NoPen);

    painter.setBrush(c_white);


    painter.save();
    //painter.rotate( (time.msec() * 360 / 999 ));
    painter.rotate(altitude*360/24);
    painter.drawConvexPolygon(pointer, 7);
    painter.restore();



    painter.setPen(c_white);



    for (int j = 0; j < 60; ++j) {
        if ((j % 5) != 0){
            painter.drawLine(92, 0, 96, 0);

        }
        painter.rotate(6.0);
    }



    //QPoint height[] = QPoint(0, 60);
    painter.drawText(QPoint(-30,-35),"Altimeter");

    painter.drawEllipse(-90,-90,10,10);
    painter.drawEllipse(90,90,10,10);
    painter.drawEllipse(-90,90,10,10);
    painter.drawEllipse(90,-90,10,10);
    painter.drawArc(-100,-100,200,200,0,360*16);

    painter.setPen(c_black);
    painter.drawText(QPoint(20,20),QString::number(altitude,10));

}

void Altimeter::updateAltitude(int value)
{
    altitude = value;
}

