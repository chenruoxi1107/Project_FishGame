#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamescene.h"
#include "gameresult.h"


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
    void on_gameOver(int finalSize, int finalScore, int finalExp, int neededExp);
    void on_gameWin(int finalSize, int finalScore);
    void on_restartGame();
    void on_backToMenu();

private:
    Ui::MainWindow *ui;
    GameScene *m_gameScene;

};

#endif
