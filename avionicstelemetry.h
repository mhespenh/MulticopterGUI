#ifndef AVIONICSTELEMETRY_H
#define AVIONICSTELEMETRY_H

#include <QMainWindow>
#include <QSharedMemory>

#define PI 3.1415926535897932384626433832795028841971693993751058209

struct dataStruct{
/*    int velX;
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
*/
    double t0, t1, t2, t3, t4, t5, t6, t7;
    int numMotors;
    int cur_x, cur_y, target_x, target_y;
    double pitch, roll, cur_alt, target_alt, v_x, v_y, v_z, heading, armLength;
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
    void updateThrustBar(int e1, int e2, int e3, int e4, int e5, int e6, int e7, int e8, int numMotors);
    void updateHeadingIndicator(int value);
    void closeAllWidgets();
    void updatePosition(int x, int y);
    void updateObstacles(int array[600][600]);
    
private:
    Ui::AvionicsTelemetry *ui;
    QSharedMemory sharedMem;
    int destination_x;
    int destination_y;
    int destination_old_x;
    int destination_old_y;
    int formatted_x;
    int formatted_y;
    double armLength;
    int target_altitude;
};

#endif // AVIONICSTELEMETRY_H
