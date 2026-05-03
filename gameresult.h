#ifndef GAMERESULT_H
#define GAMERESULT_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class GameResult : public QDialog
{
    Q_OBJECT

public:
    explicit GameResult(bool isWin, int size, int score, int exp = 0, int neededExp = 0, QWidget *parent = nullptr);

signals:
    void restartGame();
    void backToMenu();

private slots:
    void onRestartClicked();
    void onBackClicked();

private:
    QPushButton *m_restartBtn;
    QPushButton *m_backBtn;
};

#endif
