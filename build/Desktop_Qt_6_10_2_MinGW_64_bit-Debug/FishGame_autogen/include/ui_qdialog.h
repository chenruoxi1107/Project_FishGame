/********************************************************************************
** Form generated from reading UI file 'qdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QDIALOG_H
#define UI_QDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_QDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QTextEdit *textEdit;

    void setupUi(QDialog *QDialog)
    {
        if (QDialog->objectName().isEmpty())
            QDialog->setObjectName("QDialog");
        QDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(QDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(QDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 20, 221, 51));
        textEdit = new QTextEdit(QDialog);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(53, 60, 301, 171));
        textEdit->setUndoRedoEnabled(true);

        retranslateUi(QDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, QDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, QDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(QDialog);
    } // setupUi

    void retranslateUi(QDialog *QDialog)
    {
        QDialog->setWindowTitle(QCoreApplication::translate("QDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("QDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">\342\200\234\345\244\247\351\261\274\345\220\203\345\260\217\351\261\274\342\200\235\346\270\270\346\210\217\350\247\204\345\210\231</span></p></body></html>", nullptr));
        textEdit->setHtml(QCoreApplication::translate("QDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\270\270\346\210\217\350\247\204\345\210\231\357\274\232</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1.\345\220\203\346\216\211\346\257\224\350\207\252\345\267\261\345\260\217\347\232\204\351\261\274</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px;"
                        " margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">2.\344\270\215\350\246\201\350\242\253\346\257\224\350\207\252\345\267\261\345\244\247\347\232\204\351\261\274\345\220\203\346\216\211</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">3.\345\220\203\347\232\204\351\261\274\350\266\212\345\244\232\357\274\214\344\275\240\347\232\204\344\275\223\345\236\213\345\260\261\344\274\232\350\266\212\345\244\247</p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\223\215\344\275\234\346\226\271\345\274\217\357\274\232</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-bl"
                        "ock-indent:0; text-indent:0px;\">1.\347\247\273\345\212\250\351\274\240\346\240\207\357\274\232\346\216\247\345\210\266\345\260\217\351\261\274\347\232\204\346\226\271\345\220\221</p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">2.\347\251\272\346\240\274\351\224\256\357\274\232\345\212\240\351\200\237</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QDialog: public Ui_QDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QDIALOG_H
