/////////////////////////////////////////////////////////////////////////////////
// headingindicator.cpp - Multicopter Simulator Widgets - Heading Indicator
// Roy Cole
// This is the class definition for the heading indicator. It is modeled after
// real aircraft heading indicators and will function the same way. It is an
// analoge representation of the digital readout
/////////////////////////////////////////////////////////////////////////////////

#include <QtGui>

#include "headingindicator.h"


HeadingIndicator::HeadingIndicator(QWidget *parent)

    : QWidget(parent)

{

    QTimer *timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

    timer->start(10);
    counter = 0;


    setWindowTitle(tr("Heading Indicator"));
    //setAttribute( Qt::WA_OpaquePaintEvent, true );
    QPalette pal(palette());
    pal.setColor(QPalette::Background,Qt::blue);
    setPalette(pal);

    resize(200, 200);
    heading = 0;

}

void HeadingIndicator::paintEvent(QPaintEvent *)
{
    static const QPoint hourHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -40)
    };
    static const QPoint minuteHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -70)
    };
    //(3,8), (-3,8), (-3,-40),  (-7,-40), (0,-70),  (7,-40),(3,-40)
    static const QPoint pointer[4] ={
        QPoint(3,8),
        QPoint(-3,8),
        QPoint(-3,-90),
        //QPoint(-7,-40),
        //QPoint(0,-70),
        //QPoint(7,-40),
        QPoint(3,-90)
    };
    static const QPoint heightValues[12] ={
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
    QColor c_yellow(255,215,0);
    QColor c_red(255,0,0);
    //QColor c_white(0, 127, 127, 191);
    int side = qMin(width(), height());
    QTime time = QTime::currentTime();

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing);

    painter.translate(width() / 2, height() / 2);

    painter.scale(side / 200.0, side / 200.0);



    painter.setPen(Qt::NoPen);

    painter.setBrush(c_white);
    painter.drawRect(20,8,40,16);

    painter.save();
    counter++;

    //painter.rotate(18);
    //painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    //painter.drawConvexPolygon(hourHand, 3);
    painter.restore();



    painter.setPen(c_yellow);
    QStringList cardinals;
    cardinals << "90" << "135" << "180" << "225" << "270" << "315" << "0" << "45";
    for (int i = 0; i < 8; ++i) {
        painter.drawLine(84, 0, 96, 0);
        painter.drawText(QPoint(70,0), cardinals[i]);
        painter.rotate(45.0);
    }

    painter.setPen(Qt::NoPen);

    painter.setBrush(c_red);


    painter.save();
    //painter.rotate( (time.msec() * 360 / 999 ));
    painter.rotate(heading);
    painter.drawConvexPolygon(pointer, 4);
    painter.restore();



    painter.setPen(c_yellow);



    for (int j = 0; j < 60; ++j) {
        if ((j % 5) != 0){
            painter.drawLine(92, 0, 96, 0);

        }
        painter.rotate(6.0);
    }



    //QPoint height[] = QPoint(0, 60);
    painter.drawText(QPoint(-30,-35),"Heading");
    painter.setPen(c_white);
    painter.drawEllipse(-90,-90,10,10);
    painter.drawEllipse(90,90,10,10);
    painter.drawEllipse(-90,90,10,10);
    painter.drawEllipse(90,-90,10,10);
    painter.drawArc(-100,-100,200,200,0,360*16);

    painter.setPen(c_black);
    painter.drawText(QPoint(20,20),QString::number(heading,10));

}

void HeadingIndicator::updateHeading(int value)
{
    heading = value;
}
