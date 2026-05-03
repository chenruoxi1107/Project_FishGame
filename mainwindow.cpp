#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fishitem.h"
#include "introdialog.h"
#include <QRandomGenerator>
#include <QMessageBox>
#include "gameresult.h"
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

    connect(m_gameScene, &GameScene::gameOver, this, &MainWindow::on_gameOver);
    connect(m_gameScene, &GameScene::gameWin, this, &MainWindow::on_gameWin);

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

void MainWindow::on_gameOver(int finalSize, int finalScore, int finalExp, int neededExp)
{
    GameResult *dialog = new GameResult(false, finalSize, finalScore, finalExp, neededExp, this);
    connect(dialog, &GameResult::restartGame, this, &MainWindow::on_restartGame);
    connect(dialog, &GameResult::backToMenu, this, &MainWindow::on_backToMenu);
    dialog->exec();
}

void MainWindow::on_gameWin(int finalSize, int finalScore)
{
    GameResult *dialog = new GameResult(true, finalSize, finalScore, 0, 0, this);
    connect(dialog, &GameResult::restartGame, this, &MainWindow::on_restartGame);
    connect(dialog, &GameResult::backToMenu, this, &MainWindow::on_backToMenu);
    dialog->exec();
}

void MainWindow::on_restartGame()
{
    on_start_clicked();
}

void MainWindow::on_backToMenu()
{
    ui->stackedWidget->setCurrentIndex(0);
}
