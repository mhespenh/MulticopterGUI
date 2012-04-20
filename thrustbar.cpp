/////////////////////////////////////////////////////////////////////////////////
// thrustbar.cpp - Multicopter Simulator - Thrust Indicator
// Roy Cole
// This is the class declaration for the thrust indicator. The purpose of this widget
// is to show in a graphical format exactly how much thrust each engine is producing
/////////////////////////////////////////////////////////////////////////////////
#include <QtGui>
#include <cmath>
#include <time.h>
#include "thrustbar.h"
#include "ui_thrustbar.h"

ThrustBar::ThrustBar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(timer,SIGNAL(timeout()),this,SLOT(updateBarGraph()));

    timer->start(10);
    //updateBarGraph();
    eng1 =0;
    eng2 =0;
    eng3 =0;
    eng4 =0;

    setWindowTitle(tr("Thrust Graphs"));
}

ThrustBar::~ThrustBar()
{
    delete ui;
}

void ThrustBar::updateBarGraph()
{


    ui->progressBar->setValue(eng1);
    ui->progressBar_2->setValue(eng2);
    ui->progressBar_3->setValue(eng3);
    ui->progressBar_4->setValue(eng4);


}

void ThrustBar::updateThrust(int e1, int e2, int e3, int e4)
{
    eng1 = e1;
    eng2 = e2;
    eng3 = e3;
    eng4 = e4;
}

