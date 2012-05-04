#ifndef THRUSTBAR_H
#define THRUSTBAR_H

#include <QMainWindow>
#include <QWidget>


namespace Ui {
class MainWindow;
}

class ThrustBar : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ThrustBar(QWidget *parent = 0);
    ~ThrustBar();
public slots:
    void updateBarGraph();
    void updateThrust(int e1, int e2, int e3, int e4, int e5, int e6, int e7, int e8, int m_numMotors);
private:
    Ui::MainWindow *ui;
    int eng1;
    int eng2;
    int eng3;
    int eng4;
    int eng5;
    int eng6;
    int eng7;
    int eng8;
    int numMotors;
};

#endif // ThrustBar_H
