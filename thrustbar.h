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
    void updateThrust(int e1, int e2, int e3, int e4);
private:
    Ui::MainWindow *ui;
    int eng1;
    int eng2;
    int eng3;
    int eng4;
};

#endif // ThrustBar_H
