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
    sharedMem("PRIVATE_TEST")
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


    if(!sharedMem.attach()){
        //qDebug() << "attach error";
        ui->label_MemWarn->show(); //This is the red text that will appear on "Avionics Telemetry" if the memory connection is lost
        return;
    }
    ui->label_MemWarn->hide();
    dataStruct theData;
    dataStruct* ptr;
    sharedMem.lock();
    ptr = (dataStruct*)sharedMem.data();
    theData.velX = ptr->velX;
    theData.velY = ptr->velY;
    theData.velZ = ptr->velZ;
    theData.aclX = ptr->aclX;
    theData.aclY = ptr->aclY;
    theData.aclZ = ptr->aclZ;
    theData.heading = ptr->heading;
    theData.altitude = ptr->altitude;
    theData.dimX = ptr->dimX;
    theData.dimY = ptr->dimY;
    theData.dimZ = ptr->dimZ;
    theData.corX = ptr->corX;
    theData.corY = ptr->corY;
    theData.corZ = ptr->corZ;
    theData.eng1 = ptr->eng1;
    theData.eng2 = ptr->eng2;
    theData.eng3 = ptr->eng3;
    theData.eng4 = ptr->eng4;
    theData.obstacle_size_x = ptr->obstacle_size_x;
    theData.obstacle_size_y = ptr->obstacle_size_y;
    theData.obstacle_cor_x = ptr->obstacle_cor_x;
    theData.obstacle_cor_y = ptr->obstacle_cor_y;

    ptr->destination_x = formatted_x;//THIS IS WHERE I AM CURRENTLY TRYING TO WRITE BUT IT IS NOT WORKING
    ptr->destination_y = formatted_y;//THIS IS WHERE I AM CURRENTLY TRYING TO WRITE BUT IT IS NOT WORKING
    sharedMem.unlock();

    ui->label_velx->setText(QString::number(theData.velX,10));
    ui->label_vely->setText(QString::number(theData.velY,10));
    ui->label_velz->setText(QString::number(theData.velZ,10));
    ui->label_aclx->setText(QString::number(theData.aclX,10));
    ui->label_acly->setText(QString::number(theData.aclY,10));
    ui->label_aclz->setText(QString::number(theData.aclZ,10));
    ui->label_heading->setText(QString::number(theData.heading,10));
    ui->label_altitude->setText(QString::number(theData.altitude,10));
    //The following have been removed because the code does not account for changes in room sizes
    //ui->label_DimX->setText(QString::number(theData.dimX,10));
    //ui->label_DimY->setText(QString::number(theData.dimY,10));
    //ui->label_DimZ->setText(QString::number(theData.dimZ,10));
    //These are the placeholders:
    ui->label_DimX->setText("6");
    ui->label_DimY->setText("6");
    ui->label_DimZ->setText("6");
    //End placeholders
    ui->label_CorX->setText(QString::number(theData.corX,10));
    ui->label_CorY->setText(QString::number(theData.corY,10));
    //This has been removed because the altitude is also the Z coordinate, DOH! (Z for the map, the simulator handles it differently)
    //ui->label_CorZ->setText(QString::number(theData.corZ,10));
    ui->label_ENG1->setText(QString::number(theData.eng1,10));
    ui->label_ENG2->setText(QString::number(theData.eng2,10));
    ui->label_ENG3->setText(QString::number(theData.eng3,10));
    ui->label_ENG4->setText(QString::number(theData.eng4,10));

    sharedMem.detach();


    //Send emit signals to change all of the widgets
    emit updateAltimeter(theData.altitude);
    emit updateThrustBar(theData.eng1,theData.eng2,theData.eng3,theData.eng4);
    emit updateHeadingIndicator(theData.heading);
    emit updatePosition(theData.corX, theData.corY);
    emit updateObstacles(theData.obstacle_size_x, theData.obstacle_size_y, theData.obstacle_cor_x, theData.obstacle_cor_y);
}

void AvionicsTelemetry::updateDestination(int x, int y)
{
    //ui->label_DEStINATION x
    //ui->label_Destination y

    //update some private variables
    destination_x = x;
    destination_y = y;
}

