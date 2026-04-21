#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamescene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_start_clicked();
    void on_introduction_clicked();
    //void on_backToMenu_clicked();
    //void on_scoreChanged(int score);
    //void on_gameOver();
    //void on_gameWin();

private:
    Ui::MainWindow *ui;
    GameScene *m_gameScene;  // ← 确保这一行存在！
};

#endif
