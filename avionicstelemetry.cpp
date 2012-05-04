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

    timer->start(10); //10ms timer

    //Hide Memory Warning
    ui->label_MemWarn->hide();
    this->formatted_x = 0;
    this->formatted_y = 0;
    this->armLength = 1;
    this->target_altitude = 10;

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
        formatted_x = destination_x - armLength;
        formatted_y = destination_y - armLength;
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
    heading = ptr->heading;
    theData.cur_alt = ptr->cur_alt;
    theData.pitch = ptr->pitch;
    theData.roll  = ptr->roll;
    heading = ptr->heading;
    theData.cur_alt = ptr->cur_alt;
//    theData.dimX = ptr->dimX;
//    theData.dimY = ptr->dimY;
//    theData.dimZ = ptr->dimZ;
    theData.cur_x = ptr->cur_x;
    theData.cur_y = ptr->cur_y;
    this->armLength = ptr->armLength;
    theData.t0 = ptr->t0;
    theData.t1 = ptr->t1;
    theData.t2 = ptr->t2;
    theData.t3 = ptr->t3;
    theData.t4 = ptr->t4;
    theData.t5 = ptr->t5;
    theData.t6 = ptr->t6;
    theData.t7 = ptr->t7;
    //write to shared mem
    ptr->target_x = this->formatted_x;
    ptr->target_y = this->formatted_y;
    ptr->target_alt = this->target_altitude;
    sharedMem.unlock();

    ui->label_velx->setText(QString::number(theData.v_x, 'f', 2));
    ui->label_vely->setText(QString::number(theData.v_y, 'f', 2));
    ui->label_velz->setText(QString::number(theData.v_z, 'f', 2));
    ui->label_aclx->setText(QString::number(theData.roll, 'f' ,2));
    ui->label_acly->setText(QString::number(theData.pitch, 'f' ,2));
    ui->label_heading->setText(QString::number(heading,'f', 1));
    ui->label_altitude->setText(QString::number(theData.cur_alt, 'f', 2));
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

    sharedMem.detach();

    //Send emit signals to change all of the widgets
    emit updateAltimeter(theData.cur_alt);
    emit updateThrustBar(theData.t0,theData.t1,theData.t2,theData.t3, theData.t4, theData.t5, theData.t6, theData.t7, theData.numMotors);
    emit updateHeadingIndicator(heading);
    emit updatePosition(theData.cur_x, theData.cur_y);
    //Sample random array generation
    int array[600][600];
 /*   for(int i = 0; i < 600 ; i++)
    {
        for(int j = 0; j < 600 ; j++)
        {
            array[i][j] = rand() % 2 ;
        }
    }
*/
//    emit updateObstacles(array);
}

void AvionicsTelemetry::updateDestination(int x, int y)
{

    //update some private variables
    destination_x = x;
    destination_y = y;
}


void AvionicsTelemetry::on_horizontalSlider_sliderMoved(int position)
{
    this->target_altitude = position;
    ui->label_altitude_2 = position;
}
