/////////////////////////////////////////////////////////////////////////////////
// avionicstelemetry.cpp - Multicopter Simulator Widgets - Avionics Telemetry
// Roy Cole
// This is the class definition of avionics telemetry. This is the "main" widget,
// it controls all shared data between the gui and the simulator. It will update
// its own values and send signals to update the other widgets. It will be sent data
// from the map whenever a new point is clicked
/////////////////////////////////////////////////////////////////////////////////
#include <cmath>
#include <time.h>
#include <QTimer>
#include <QDebug>
#include "avionicstelemetry.h"
#include "ui_avionicstelemetry.h"




AvionicsTelemetry::AvionicsTelemetry(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AvionicsTelemetry),
    sharedMem("PUBLIC_SHARED_MEM")
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);

    //connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(timer,SIGNAL(timeout()),this,SLOT(readWriteMemory()));

    timer->start(10);

    //Hide Memory Warning
    ui->label_MemWarn->hide();

}

AvionicsTelemetry::~AvionicsTelemetry()
{
    delete ui;
}

void AvionicsTelemetry::readWriteMemory()
{
    float heading;
    //Check to see if the value has changed, if not do nothing, if it has run the else statement
    if(destination_x == destination_old_x && destination_y == destination_old_y)
    {
        //nop
    }
    else
    {
        //Format X and Y before sending to main
        formatted_x = destination_x - 25;
        formatted_y = destination_y - 25;
        //Check to see if the click is in range
        if(formatted_x < 0 || formatted_y < 0 || formatted_x > 600 || formatted_y > 600)
        {
            //nop
        }
        else
        {
            destination_old_x = destination_x; //Set this for the condition check in the top if else statement
            destination_old_y = destination_y; //Set this for the condition check in the top if else statement
            qDebug() << "The destination is: (" << formatted_x << "," << formatted_y <<")";
            /////////////////////////////////////////////////////////////////////////////////
            //This is where the write needs to occur
            //If it cannot be written right here then you need
            //to move the whole nested if statement to wherever you write it
            //Either that or change the code to have a flag so it isn't always writing
            /////////////////////////////////////////////////////////////////////////////////
            ui->label_Dest_x->setText(QString::number(formatted_x,10));
            ui->label_Dest_y->setText(QString::number(formatted_y,10));
        }
    }

    if(!sharedMem.isAttached()) {
        if(!sharedMem.attach()){
        //    qDebug() << sharedMem.errorString();
        //    qDebug() << sharedMem.key();
            ui->label_MemWarn->show(); //This is the red text that will appear on "Avionics Telemetry" if the memory connection is lost
            return;
        }
    }
    ui->label_MemWarn->hide();

    dataStruct theData;
    dataStruct* ptr;
    sharedMem.lock();
    ptr = (dataStruct*)sharedMem.data();
    theData.v_x = ptr->v_x;
    theData.v_y = ptr->v_y;
    theData.v_z = ptr->v_z;
    heading = atan(theData.v_y/theData.v_x) * (180/PI);
    theData.altitude = ptr->altitude;
//    theData.dimX = ptr->dimX;
//    theData.dimY = ptr->dimY;
//    theData.dimZ = ptr->dimZ;
    theData.cur_x = ptr->cur_x;
    theData.cur_y = ptr->cur_y;
    theData.t0 = ptr->t0;
    theData.t1 = ptr->t1;
    theData.t2 = ptr->t2;
    theData.t3 = ptr->t3;
//    theData.obstacle_size_x = ptr->obstacle_size_x;
//    theData.obstacle_size_y = ptr->obstacle_size_y;
//    theData.obstacle_cor_x = ptr->obstacle_cor_x;
//    theData.obstacle_cor_y = ptr->obstacle_cor_y;

//    ptr->destination_x = formatted_x;//THIS IS WHERE I AM CURRENTLY TRYING TO WRITE BUT IT IS NOT WORKING
//    ptr->destination_y = formatted_y;//THIS IS WHERE I AM CURRENTLY TRYING TO WRITE BUT IT IS NOT WORKING
    sharedMem.unlock();

    ui->label_velx->setText(QString::number(theData.v_x, 'f', 2));
    ui->label_vely->setText(QString::number(theData.v_y, 'f', 2));
    ui->label_velz->setText(QString::number(theData.v_z, 'f', 2));
    ui->label_aclx->setText(QString::number(theData.v_x, 'f' ,2));
    ui->label_acly->setText(QString::number(theData.v_y, 'f' ,2));
    ui->label_heading->setText(QString::number(heading,'f', 1));
    ui->label_altitude->setText(QString::number(theData.altitude, 'f', 2));
    //The following have been removed because the code does not account for changes in room sizes
    //ui->label_DimX->setText(QString::number(theData.dimX,10));
    //ui->label_DimY->setText(QString::number(theData.dimY,10));
    //ui->label_DimZ->setText(QString::number(theData.dimZ,10));
    //These are the placeholders:
    ui->label_DimX->setText("600");
    ui->label_DimY->setText("600");
    ui->label_DimZ->setText("600");
    //End placeholders
    ui->label_CorX->setText(QString::number(theData.cur_x,10));
    ui->label_CorY->setText(QString::number(theData.cur_y,10));

    ui->label_ENG1->setText(QString::number(theData.t0,10));
    ui->label_ENG2->setText(QString::number(theData.t1,10));
    ui->label_ENG3->setText(QString::number(theData.t2,10));
    ui->label_ENG4->setText(QString::number(theData.t3,10));

    sharedMem.detach();


    //Send emit signals to change all of the widgets
    emit updateAltimeter(theData.altitude);
    emit updateThrustBar(theData.t0,theData.t1,theData.t2,theData.t3);
    emit updateHeadingIndicator(heading);
    emit updatePosition(theData.cur_x, theData.cur_y);
//    emit updateObstacles(theData.obstacle_size_x, theData.obstacle_size_y, theData.obstacle_cor_x, theData.obstacle_cor_y);
}

void AvionicsTelemetry::updateDestination(int x, int y)
{
    //ui->label_DEStINATION x
    //ui->label_Destination y

    //update some private variables
    destination_x = x;
    destination_y = y;
}

