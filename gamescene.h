#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include "fishitem.h"

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
    void scoreChanged(int score);
    void gameOver();

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
};

#endif
