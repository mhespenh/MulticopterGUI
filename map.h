#ifndef MAP_H
#define MAP_H

#include <vector>

#include <QWidget>


class MulticopterMap : public QWidget
{
    Q_OBJECT

public:
    MulticopterMap(QWidget *parent = 0);
    void clear();

public slots:
    void updatePosition(int x, int y);
    void updateObstacles(int obSizeX, int obSizeY, int obCorX, int obCorY);

signals:
    void updateDestination(int x, int y); //This will send the coordinates back to Avionics Telemetry, which will send it back to the Simulator

protected:
    void mousePressEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *event);

private:
    std::vector< std::vector< QPoint > > m_points;
    int m_width;
    QColor m_color;
    Qt::PenStyle m_style;
    int click_x; //this will be used to determine the destination
    int click_y; //this will be used to determine the destination
    int pos_copter_x;
    int pos_copter_y;
    QPoint point_copter;
    QPoint point_eng1;
    QPoint point_eng2;
    QPoint point_eng3;
    QPoint point_eng4;
    int obstacle_size_x;
    int obstacle_size_y;
    int obstacle_cor_x;
    int obstacle_cor_y;
    QPoint obstacle;
};

#endif
