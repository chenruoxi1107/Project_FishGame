#include "introdialog.h"
#include "ui_introdialog.h"

IntroDialog::IntroDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::IntroDialog)
{
    ui->setupUi(this);

    setWindowTitle("游戏简介");

    // 如果有关闭按钮，连接它
    //connect(ui->closeButton, &QPushButton::clicked, this, &QDialog::close);
}

IntroDialog::~IntroDialog()
{
    delete ui;
}

void IntroDialog::on_closeButton_clicked()
{
    this->close();
}

