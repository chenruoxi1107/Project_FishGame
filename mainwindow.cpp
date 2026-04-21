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
    //connect(m_gameScene, &GameScene::scoreChanged, this, &MainWindow::on_scoreChanged);
    //connect(m_gameScene, &GameScene::gameOver, this, &MainWindow::on_gameOver);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_clicked()
{
    m_gameScene->initGame();


    // 玩家鱼（红色/橙色）
    QPixmap playerPixmap(":/images/build\\Desktop_Qt_6_10_2_MinGW_64_bit-Debug/RedFish.png");
    FishItem *playerFish = new FishItem(playerPixmap, 0);
    playerFish->setPos(400, 300);
    playerFish->setSize(2);  // 初始体型设为 2
    m_gameScene->setPlayerFish(playerFish);

    // 添加绿色小鱼（体型1-2）
    QPixmap greenPixmap(":/images/build\\Desktop_Qt_6_10_2_MinGW_64_bit-Debug/GreenFish.png");
    for (int i = 0; i < 5; i++) {
        qreal x = QRandomGenerator::global()->bounded(800);
        qreal y = QRandomGenerator::global()->bounded(600);
        int size = QRandomGenerator::global()->bounded(1, 3);
        m_gameScene->addFish(greenPixmap, x, y, 1, size);
    }

    // 添加黄色中鱼（体型3-4）
    QPixmap yellowPixmap(":/images/build\\Desktop_Qt_6_10_2_MinGW_64_bit-Debug/YellowFish.png");
    for (int i = 0; i < 3; i++) {
        qreal x = QRandomGenerator::global()->bounded(800);
        qreal y = QRandomGenerator::global()->bounded(600);
        int size = QRandomGenerator::global()->bounded(3, 5);
        m_gameScene->addFish(yellowPixmap, x, y, 1, size);
    }

    // 添加蓝色大鱼（体型5-6）
    QPixmap bluePixmap(":/images/build\\Desktop_Qt_6_10_2_MinGW_64_bit-Debug/BlueFish.png");
    for (int i = 0; i < 2; i++) {
        qreal x = QRandomGenerator::global()->bounded(800);
        qreal y = QRandomGenerator::global()->bounded(600);
        int size = QRandomGenerator::global()->bounded(5, 7);
        m_gameScene->addFish(bluePixmap, x, y, 1, size);
    }

    // 添加紫色巨鱼（体型7-8）
    QPixmap purplePixmap(":/images/build\\Desktop_Qt_6_10_2_MinGW_64_bit-Debug/PurpleFish.png");
    for (int i = 0; i < 1; i++) {
        qreal x = QRandomGenerator::global()->bounded(800);
        qreal y = QRandomGenerator::global()->bounded(600);
        int size = QRandomGenerator::global()->bounded(7, 9);
        m_gameScene->addFish(purplePixmap, x, y, 1, size);
    }

    m_gameScene->startGame();
    ui->stackedWidget->setCurrentIndex(1);
    //qDebug() << QDir(":/images").entryList();

    //m_gameScene = new GameScene(this);
    //ui->graphicsView->setScene(m_gameScene);
}



void MainWindow::on_introduction_clicked()
{
    IntroDialog *dialog = new IntroDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);  // 关闭时自动删除
    dialog->exec();
}


