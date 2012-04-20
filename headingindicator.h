#ifndef HEADINGINDICATOR_H
#define HEADINGINDICATOR_H

#include <QWidget>

//! [0]
class HeadingIndicator : public QWidget
{
    Q_OBJECT

public:
    HeadingIndicator(QWidget *parent = 0);
public slots:
    void updateHeading(int value);

protected:
    void paintEvent(QPaintEvent *event);
private:
    int counter;
    int heading;
};
//! [0]

#endif
