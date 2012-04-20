#ifndef ALTIMETER_H
#define ALTIMETER_H

#include <QWidget>


class Altimeter : public QWidget
{
    Q_OBJECT

public:
    Altimeter(QWidget *parent = 0);
public slots:
    void updateAltitude(int value);

protected:
    void paintEvent(QPaintEvent *event);
private:
    int counter;
    int altitude;
};


#endif
