#include "gameresult.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

GameResult::GameResult(bool isWin, int size, int score, int exp, int neededExp, QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(isWin ? "胜利" : "游戏结束");
    setModal(true);
    setFixedSize(350, 250);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // 标题
    QLabel *titleLabel = new QLabel(this);
    if (isWin) {
        titleLabel->setText("<h1 style='color: green;'>🎉 胜利！ 🎉</h1>");
    } else {
        titleLabel->setText("<h1 style='color: red;'>💀 游戏失败 💀</h1>");
    }
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel);

    // 信息文字
    QLabel *infoLabel = new QLabel(this);
    if (isWin) {
        infoLabel->setText(QString("<p style='font-size: 14px;'>你是这片海洋的霸主！<br>"
                                   "最终体型: <b>%1</b><br>"
                                   "最终得分: <b>%2</b></p>")
                               .arg(size).arg(score));
    } else {
        int progress = neededExp > 0 ? (exp * 100) / neededExp : 0;
        infoLabel->setText(QString("<p style='font-size: 14px;'>你被大鱼吃掉了...<br>"
                                   "最终体型: <b>%1</b><br>"
                                   "最终得分: <b>%2</b><br>"
                                   "当前等级进度: <b>%3/%4</b> (" + QString::number(progress) + "%)</p>")
                               .arg(size).arg(score).arg(exp).arg(neededExp).arg(progress));
    }
    infoLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(infoLabel);

    // 按钮区域
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    m_restartBtn = new QPushButton("🔄 再来一次", this);
    m_backBtn = new QPushButton("🏠 返回首页", this);

    m_restartBtn->setFixedSize(120, 40);
    m_backBtn->setFixedSize(120, 40);

    buttonLayout->addWidget(m_restartBtn);
    buttonLayout->addWidget(m_backBtn);
    mainLayout->addLayout(buttonLayout);

    // 连接按钮
    connect(m_restartBtn, &QPushButton::clicked, this, &GameResult::onRestartClicked);
    connect(m_backBtn, &QPushButton::clicked, this, &GameResult::onBackClicked);
}

void GameResult::onRestartClicked()
{
    emit restartGame();
    accept();
}

void GameResult::onBackClicked()
{
    emit backToMenu();
    accept();
}
