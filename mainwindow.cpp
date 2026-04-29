#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fishitem.h"
#include "introdialog.h"
#include <QRandomGenerator>
#include <QMessageBox>
//#include<QDir>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 连接开始游戏按钮
    connect(ui->start, &QPushButton::clicked,
            this, &MainWindow::on_start_clicked);


    m_gameScene = new GameScene(this);
    ui->graphicsView->setScene(m_gameScene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    // 设置 GraphicsView 透明
    ui->graphicsView->setStyleSheet("background: transparent;");
    ui->graphicsView->setBackgroundBrush(Qt::NoBrush);
    ui->graphicsView->viewport()->setAutoFillBackground(false);
    ui->graphicsView->setMouseTracking(true);


    // 连接信号
    connect(ui->start, &QPushButton::clicked, this, &MainWindow::on_start_clicked);
    connect(ui->introduction, &QPushButton::clicked, this, &MainWindow::on_introduction_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_clicked()
{
    // 玩家鱼
    QPixmap playerPixmap(":/images/build\\Desktop_Qt_6_10_2_MinGW_64_bit-Debug/OrangeFish.png");
    FishItem *playerFish = new FishItem(playerPixmap, 0);
    playerFish->setPos(400, 300);  // 玩家在中间
    playerFish->setSize(3);
    m_gameScene->setPlayerFish(playerFish);

    // 开始游戏（会生成从两侧进入的鱼）
    m_gameScene->startGame();

    ui->stackedWidget->setCurrentIndex(1);
}



void MainWindow::on_introduction_clicked()
{
    IntroDialog *dialog = new IntroDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);  // 关闭时自动删除
    dialog->exec();
}


