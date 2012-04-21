/////////////////////////////////////////////////////////////////////////////////
// map.cpp - Multicopter Simulator Widgets - Map
// Roy Cole
// This is the class definition for the simulator Map. The map will display the
// location of the multicopter and the obstacle that it has to avoid. The map is
// interactive so that if you click it, it sends new destination coordiates back
// to the simulator
/////////////////////////////////////////////////////////////////////////////////
#include <QtGui>
#include <QMouseEvent>
#include <QDebug>
#include <QPoint>

#include "map.h"

MulticopterMap::MulticopterMap(QWidget *parent)
    : QWidget(parent)
{

    QTimer *timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

    timer->start(10);

    this->setMouseTracking(true);

    setWindowTitle(tr("Multicopter Map"));
    resize(650, 650);


    //m_width = 2;
    //m_color = Qt::red;
    //m_style = Qt::SolidLine;
    pos_copter_x = 250;
    pos_copter_y = 250;
}

void MulticopterMap::clear()
{
    m_points.clear();
    this->repaint();
}
void MulticopterMap::mousePressEvent(QMouseEvent * e)
{
    if (e->buttons() & Qt::LeftButton)
      {
        click_x = e->pos().x();
        click_y = e->pos().y();
          m_points.push_back(std::vector< QPoint >());
        m_points.back().push_back(e->pos());
        m_points.back().push_back(e->pos());
      }
    qDebug() << e->pos();
}

void MulticopterMap::paintEvent(QPaintEvent *)
{
    emit updateDestination(click_x, click_y);

    QPainter painter(this);
       {
          QPen pen = painter.pen();
          pen.setCapStyle(Qt::RoundCap);
          pen.setColor(Qt::black);
          pen.setWidth(20);
          pen.setStyle(m_style);
          painter.drawRect(25,25,600,600);
         // painter.rotate(45);
          painter.drawEllipse(point_eng1, 5, 5);
          painter.drawEllipse(point_eng2, 5, 5);
          painter.drawEllipse(point_eng3, 5, 5);
          painter.drawEllipse(point_eng4, 5, 5);
          painter.drawEllipse(point_eng1, 1, 1);
          painter.drawEllipse(point_eng2, 1, 1);
          painter.drawEllipse(point_eng3, 1, 1);
          painter.drawEllipse(point_eng4, 1, 1);


          pen.setStyle(Qt::SolidLine);
          pen.setWidth(2);
          pen.setColor(Qt::red);
          painter.setPen(pen);

          //This will draw the obstacle
          painter.drawEllipse(obstacle, obstacle_size_x, obstacle_size_y);


       }


}

void MulticopterMap::updatePosition(int x, int y)
{
    pos_copter_x = x;
    pos_copter_y = y;
    point_copter.setX(pos_copter_x);
    point_copter.setY(pos_copter_y);
    point_eng1.setX(pos_copter_x + 10);
    point_eng1.setY(pos_copter_y + 10);
    point_eng2.setX(pos_copter_x - 10);
    point_eng2.setY(pos_copter_y + 10);
    point_eng3.setX(pos_copter_x + 10);
    point_eng3.setY(pos_copter_y - 10);
    point_eng4.setX(pos_copter_x - 10);
    point_eng4.setY(pos_copter_y - 10);
}

void MulticopterMap::updateObstacles(int obSizeX, int obSizeY, int obCorX, int obCorY)
{
    obstacle_size_x = obSizeX;
    obstacle_size_y = obSizeY;
    obstacle_cor_x = obCorX; //Cors are not necessary for private var, only the size is
    obstacle_cor_y = obCorY; //Cors are not necessary for private var, only the size is

    obstacle.setX(obCorX);
    obstacle.setY(obCorY);
}
