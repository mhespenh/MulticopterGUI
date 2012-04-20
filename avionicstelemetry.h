#ifndef AVIONICSTELEMETRY_H
#define AVIONICSTELEMETRY_H

#include <QMainWindow>
#include <QSharedMemory>

struct dataStruct{
    int velX;
    int velY;
    int velZ;
    int aclX;
    int aclY;
    int aclZ;
    int heading;
    int altitude;
    int dimX;
    int dimY;
    int dimZ;
    int corX;
    int corY;
    int corZ;
    int eng1;
    int eng2;
    int eng3;
    int eng4;
    int obstacle_size_x;
    int obstacle_size_y;
    int obstacle_cor_x;
    int obstacle_cor_y;

    //this is data for sending back to the simulator
    int destination_x;
    int destination_y;
};

namespace Ui {
class AvionicsTelemetry;
}

class AvionicsTelemetry : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit AvionicsTelemetry(QWidget *parent = 0);
    ~AvionicsTelemetry();
public slots:
    void readWriteMemory();
    void updateDestination(int x, int y);

signals:
    void updateAltimeter(int value);
    void updateThrustBar(int e1, int e2, int e3, int e4);
    void updateHeadingIndicator(int value);
    void closeAllWidgets();
    void updatePosition(int x, int y);
    void updateObstacles(int sizeX, int sizeY, int corX, int corY);
    
private:
    Ui::AvionicsTelemetry *ui;
    QSharedMemory sharedMem;
    int destination_x;
    int destination_y;
    int destination_old_x;
    int destination_old_y;
    int formatted_x;
    int formatted_y;
};

#endif // AVIONICSTELEMETRY_H
