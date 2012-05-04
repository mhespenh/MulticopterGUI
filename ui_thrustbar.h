/********************************************************************************
** Form generated from reading UI file 'thrustbar.ui'
**
** Created: Fri May 4 17:18:05 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THRUSTBAR_H
#define UI_THRUSTBAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QProgressBar *progBarENG1;
    QProgressBar *progBarENG2;
    QProgressBar *progBarENG3;
    QProgressBar *progBarENG4;
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QProgressBar *progBarENG5;
    QProgressBar *progBarENG6;
    QProgressBar *progBarENG7;
    QProgressBar *progBarENG8;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(478, 348);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        progBarENG1 = new QProgressBar(centralWidget);
        progBarENG1->setObjectName(QString::fromUtf8("progBarENG1"));
        progBarENG1->setGeometry(QRect(100, 20, 351, 31));
        progBarENG1->setValue(24);
        progBarENG2 = new QProgressBar(centralWidget);
        progBarENG2->setObjectName(QString::fromUtf8("progBarENG2"));
        progBarENG2->setGeometry(QRect(100, 50, 351, 31));
        progBarENG2->setValue(24);
        progBarENG3 = new QProgressBar(centralWidget);
        progBarENG3->setObjectName(QString::fromUtf8("progBarENG3"));
        progBarENG3->setGeometry(QRect(100, 80, 351, 31));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(progBarENG3->sizePolicy().hasHeightForWidth());
        progBarENG3->setSizePolicy(sizePolicy);
        progBarENG3->setSizeIncrement(QSize(0, 0));
        progBarENG3->setValue(66);
        progBarENG4 = new QProgressBar(centralWidget);
        progBarENG4->setObjectName(QString::fromUtf8("progBarENG4"));
        progBarENG4->setGeometry(QRect(100, 110, 351, 31));
        progBarENG4->setValue(24);
        label_1 = new QLabel(centralWidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(30, 30, 67, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 60, 67, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 90, 67, 17));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 120, 67, 17));
        progBarENG5 = new QProgressBar(centralWidget);
        progBarENG5->setObjectName(QString::fromUtf8("progBarENG5"));
        progBarENG5->setGeometry(QRect(100, 140, 351, 31));
        progBarENG5->setValue(24);
        progBarENG6 = new QProgressBar(centralWidget);
        progBarENG6->setObjectName(QString::fromUtf8("progBarENG6"));
        progBarENG6->setGeometry(QRect(100, 170, 351, 31));
        progBarENG6->setValue(24);
        progBarENG7 = new QProgressBar(centralWidget);
        progBarENG7->setObjectName(QString::fromUtf8("progBarENG7"));
        progBarENG7->setGeometry(QRect(100, 200, 351, 31));
        progBarENG7->setValue(24);
        progBarENG8 = new QProgressBar(centralWidget);
        progBarENG8->setObjectName(QString::fromUtf8("progBarENG8"));
        progBarENG8->setGeometry(QRect(100, 230, 351, 31));
        progBarENG8->setValue(24);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 150, 67, 17));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 180, 67, 17));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 210, 67, 17));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 240, 67, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 478, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label_1->setText(QApplication::translate("MainWindow", "Engine 1", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Engine 2", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Engine 3", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Engine 4", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Engine 5", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Engine 6", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Engine 7", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Engine 8", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THRUSTBAR_H
