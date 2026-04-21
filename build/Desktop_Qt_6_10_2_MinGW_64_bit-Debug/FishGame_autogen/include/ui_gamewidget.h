/********************************************************************************
** Form generated from reading UI file 'gamewidget.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWIDGET_H
#define UI_GAMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWidget
{
public:
    QTextEdit *textEdit;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *GameWidget)
    {
        if (GameWidget->objectName().isEmpty())
            GameWidget->setObjectName("GameWidget");
        GameWidget->resize(425, 379);
        GameWidget->setAutoFillBackground(true);
        GameWidget->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e74c3c;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 5px;\n"
"    padding: 8px 20px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #c0392b;\n"
"}"));
        textEdit = new QTextEdit(GameWidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(53, 70, 321, 211));
        label = new QLabel(GameWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 30, 181, 21));
        pushButton = new QPushButton(GameWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(170, 320, 91, 31));

        retranslateUi(GameWidget);

        QMetaObject::connectSlotsByName(GameWidget);
    } // setupUi

    void retranslateUi(QWidget *GameWidget)
    {
        GameWidget->setWindowTitle(QCoreApplication::translate("GameWidget", "Form", nullptr));
        textEdit->setHtml(QCoreApplication::translate("GameWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">\346\270\270\346\210\217\350\247\204\345\210\231\357\274\232</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-ri"
                        "ght:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">1.\345\220\203\346\216\211\346\257\224\350\207\252\345\267\261\345\260\217\347\232\204\351\261\274</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">2.\345\260\275\351\207\217\351\201\277\345\205\215\350\242\253\346\257\224\350\207\252\345\267\261\345\244\247\347\232\204\351\261\274\345\220\203\346\216\211</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">3.\345\220\203\347\232\204\351\261\274\350\266\212\345\244\232\357\274\214\344\275\240\347\232\204\344\275\223\345\236\213\345\260\261\344\274\232\350\266\212\345\244\247</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-"
                        "block-indent:0; text-indent:0px; font-size:10pt;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">\346\223\215\344\275\234\346\226\271\345\274\217\357\274\232</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">1.\351\274\240\346\240\207\347\247\273\345\212\250\357\274\232\346\216\247\345\210\266\345\260\217\351\261\274\347\232\204\346\226\271\345\220\221</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">2.\347\251\272\346\240\274\351\224\256\357\274\232\347\273\231\345\260\217\351\261\274\345\212\240\351\200\237</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("GameWidget", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\342\200\234\345\244\247\351\261\274\345\220\203\345\260\217\351\261\274\342\200\235\346\270\270\346\210\217\350\247\204\345\210\231</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("GameWidget", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWidget: public Ui_GameWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWIDGET_H
