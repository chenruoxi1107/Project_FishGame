#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include "fishitem.h"
#define MAX_PLAYER_SIZE 12

class GameScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit GameScene(QObject *parent = nullptr);
    ~GameScene();

    void startGame();
    void initGame();
    void addFish(const QPixmap &pixmap, qreal x, qreal y, int type, int size);
    void setPlayerFish(FishItem *fish);
    int getScore() const { return m_score; }

signals:
    // void scoreChanged(int score);
    // void gameOver();
    void scoreChanged(int score);
    void gameOver(int finalSize, int finalScore, int finalExp, int neededExp);
    void gameWin(int finalSize, int finalScore);


protected:
     void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

private slots:
    void updateFrame();
    void spawnFish();

private:
    void checkCollisions();
    void updateUI();

    FishItem *m_playerFish;
    QTimer *m_timer;
    QTimer *m_spawnTimer;
    QList<FishItem*> m_fishList;
    int m_score;
    int m_playerSize;
public:
    void addExistingFish(FishItem *fish) {
        addItem(fish);
        m_fishList.append(fish);
    }
private:
    int m_exp;           // 当前经验值（吃了几条鱼）
    int m_nextExp;       // 升到下一级需要的经验值
public:
    int getExp() const { return m_exp; }
    int getNextExp() const { return m_nextExp; }
 };


#endif
