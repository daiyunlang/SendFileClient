/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *IPLineEdit;
    QLabel *label_2;
    QLineEdit *PortLineEdit;
    QPushButton *connectPushButton;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *FileLineEdit;
    QPushButton *ChoosePushButton;
    QProgressBar *progressBar;
    QPushButton *SendPushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(110, 60, 521, 291));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        IPLineEdit = new QLineEdit(widget);
        IPLineEdit->setObjectName("IPLineEdit");

        horizontalLayout->addWidget(IPLineEdit);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        PortLineEdit = new QLineEdit(widget);
        PortLineEdit->setObjectName("PortLineEdit");

        horizontalLayout->addWidget(PortLineEdit);

        connectPushButton = new QPushButton(widget);
        connectPushButton->setObjectName("connectPushButton");

        horizontalLayout->addWidget(connectPushButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        FileLineEdit = new QLineEdit(widget);
        FileLineEdit->setObjectName("FileLineEdit");

        horizontalLayout_2->addWidget(FileLineEdit);

        ChoosePushButton = new QPushButton(widget);
        ChoosePushButton->setObjectName("ChoosePushButton");

        horizontalLayout_2->addWidget(ChoosePushButton);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        progressBar = new QProgressBar(widget);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 2, 0, 1, 1);

        SendPushButton = new QPushButton(widget);
        SendPushButton->setObjectName("SendPushButton");

        gridLayout->addWidget(SendPushButton, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "IP", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        connectPushButton->setText(QCoreApplication::translate("MainWindow", "connect", nullptr));
        ChoosePushButton->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        SendPushButton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
