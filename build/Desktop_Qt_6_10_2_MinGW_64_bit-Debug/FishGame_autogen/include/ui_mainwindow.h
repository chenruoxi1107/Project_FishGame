/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *p0;
    QPushButton *introduction;
    QPushButton *start;
    QWidget *p1;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 549);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget #centralwidget{\n"
"    border-image: url(:/images/build/Desktop_Qt_6_10_2_MinGW_64_bit-Debug/ocean_bj.jpg);\n"
"    padding: 0px;\n"
"    margin: 0px;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(-101, -91, 1261, 871));
        stackedWidget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"url(:/images/build/Desktop_Qt_6_10_2_MinGW_64_bit-Debug/ocean_bj_2.jpg)\n"
"}"));
        p0 = new QWidget();
        p0->setObjectName("p0");
        p0->setMaximumSize(QSize(1000, 650));
        p0->setStyleSheet(QString::fromUtf8("QWidget#p0 {\n"
"    border-image: url(:/images/build/Desktop_Qt_6_10_2_MinGW_64_bit-Debug/ocean_bj.jpg);\n"
"\n"
"}"));
        introduction = new QPushButton(p0);
        introduction->setObjectName("introduction");
        introduction->setGeometry(QRect(460, 530, 82, 36));
        introduction->setAutoFillBackground(false);
        introduction->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #ffff7f;        /* \350\203\214\346\231\257\350\211\262 */\n"
"    color: black;                      /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none;                      /* \350\276\271\346\241\206 */\n"
"    border-radius: 8px;               /* \345\234\206\350\247\222 */\n"
"    font-size: 12px;                  /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    font-weight: bold;                /* \345\255\227\344\275\223\347\262\227\347\273\206 */\n"
"    padding: 8px 16px;                /* \345\206\205\350\276\271\350\267\235 */\n"
"    min-width: 50px;                 /* \346\234\200\345\260\217\345\256\275\345\272\246 */\n"
"    min-height: 20px;                 /* \346\234\200\345\260\217\351\253\230\345\272\246 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #a2a251;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"background-color:#cfcf4f;\n"
"}"));
        start = new QPushButton(p0);
        start->setObjectName("start");
        start->setGeometry(QRect(420, 440, 171, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setBold(true);
        start->setFont(font);
        start->setAutoFillBackground(false);
        start->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #ffff7f;        /* \350\203\214\346\231\257\350\211\262 */\n"
"    color: black;                      /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none;                      /* \350\276\271\346\241\206 */\n"
"    border-radius: 8px;               /* \345\234\206\350\247\222 */\n"
"    font-size: 24px;                  /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    font-weight: bold;                /* \345\255\227\344\275\223\347\262\227\347\273\206 */\n"
"    padding: 8px 16px;                /* \345\206\205\350\276\271\350\267\235 */\n"
"    min-width: 100px;                 /* \346\234\200\345\260\217\345\256\275\345\272\246 */\n"
"    min-height: 35px;                 /* \346\234\200\345\260\217\351\253\230\345\272\246 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #a2a251;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"background-color:#cfcf4f;\n"
"}"));
        start->setIconSize(QSize(24, 24));
        stackedWidget->addWidget(p0);
        p1 = new QWidget();
        p1->setObjectName("p1");
        p1->setMaximumSize(QSize(1000, 650));
        p1->setStyleSheet(QString::fromUtf8("QWidget#p1 {\n"
"    border-image: url(:/images/build/Desktop_Qt_6_10_2_MinGW_64_bit-Debug/ocean_bj_2.jpg);\n"
"}"));
        graphicsView = new QGraphicsView(p1);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(-60, -10, 1061, 671));
        graphicsView->setStyleSheet(QString::fromUtf8("QGraphicsView {\n"
"    background: transparent;\n"
"    border: none;\n"
"}"));
        stackedWidget->addWidget(p1);
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
        introduction->setText(QCoreApplication::translate("MainWindow", "\346\270\270\346\210\217\347\256\200\344\273\213", nullptr));
        start->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
