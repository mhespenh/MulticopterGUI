/////////////////////////////////////////////////////////////////////////////////
// main.cpp - Multicopter Simulator Widgets
// Roy Cole
// This will instantiate all the widgets for the simulator (Telemetry Data, Altimeter
// Thrust Graphs, Heading Indicator, and an interactive map
/////////////////////////////////////////////////////////////////////////////////
#include <QtGui/QApplication>
#include "avionicstelemetry.h"
#include "altimeter.h"
#include "thrustbar.h"
#include "headingindicator.h"
#include "map.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AvionicsTelemetry telemetry;
    Altimeter altimeter;
    ThrustBar thrust;
    HeadingIndicator heading;
    MulticopterMap map;
    telemetry.show();
    altimeter.show();
    thrust.show();
    heading.show();
    map.show();

    //Signals from Telemetry -> Widgets
    QObject::connect(&telemetry,SIGNAL(updateAltimeter(double)),&altimeter,SLOT(updateAltitude(double)));
    QObject::connect(&telemetry,SIGNAL(updateThrustBar(int,int,int,int,int,int,int,int,int)),&thrust,SLOT(updateThrust(int,int,int,int,int,int,int,int,int)));
    QObject::connect(&telemetry,SIGNAL(updateHeadingIndicator(int)),&heading,SLOT(updateHeading(int)));
    QObject::connect(&telemetry,SIGNAL(updatePosition(int,int)),&map,SLOT(updatePosition(int,int)));
    QObject::connect(&telemetry,SIGNAL(updateObstacles(int[600][600])),&map, SLOT(updateObstacles(int[600][600])));

    QObject::connect(&map,SIGNAL(updateDestination(int,int)),&telemetry, SLOT(updateDestination(int,int)));

    //This will close all of the widgets if the avionics telemetry is closed
    //QObject::connect(&w,SIGNAL(closeAllWidgets()),&y,SLOT(closeWidget()));
    //QObject::connect(qApp,SIGNAL(lastWindowClosed()),qApp,SLOT(quit()));
    //QApplication::setQuitOnLastWindowClosed(true);


    return a.exec();
}
