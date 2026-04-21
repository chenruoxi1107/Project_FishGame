#include "gamescene.h"
#include <QGraphicsSceneMouseEvent>
#include <QRandomGenerator>
#include <QGraphicsView>
#include <QDebug>

GameScene::GameScene(QObject *parent)
    : QGraphicsScene(parent)
    , m_playerFish(nullptr)
    , m_score(0)
    , m_playerSize(1)
{
    setSceneRect(0, 0, 800, 600);

    m_timer = new QTimer(this);
    // 关键：不要加括号，不要加参数
    connect(m_timer, &QTimer::timeout, this, &GameScene::updateFrame);

    m_spawnTimer = new QTimer(this);
    connect(m_spawnTimer, &QTimer::timeout, this, &GameScene::spawnFish);
}


GameScene::~GameScene()
{
    m_timer->stop();
    m_spawnTimer->stop();
}

void GameScene::initGame()
{
    m_score = 0;
    m_playerSize = 1;
    updateUI();

    for (FishItem *fish : std::as_const(m_fishList)) {
        removeItem(fish);
        delete fish;
    }
    m_fishList.clear();
}

void GameScene::startGame()
{
    m_timer->start(16);
    m_spawnTimer->start(2000);
}

void GameScene::addFish(const QPixmap &pixmap, qreal x, qreal y, int type, int size)
{
    FishItem *fish = new FishItem(pixmap, type);
    fish->setPos(x, y);
    fish->setSize(size);
    addItem(fish);
    m_fishList.append(fish);

    qreal vx = QRandomGenerator::global()->bounded(-3, 4);
    qreal vy = QRandomGenerator::global()->bounded(-3, 4);
    fish->setVelocity(vx, vy);
}

void GameScene::setPlayerFish(FishItem *fish)
{
    m_playerFish = fish;
    m_playerFish->setSize(m_playerSize);
    addItem(m_playerFish);
}

void GameScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (m_playerFish) {
        QPointF targetPos = event->scenePos();
        QPointF currentPos = m_playerFish->pos();
        QPointF delta = targetPos - currentPos;

        qreal maxSpeed = 8.0 / (m_playerSize * 0.3 + 1);
        qreal distance = delta.manhattanLength();

        if (distance > 0) {
            qreal speed = qMin(maxSpeed, distance / 10.0);
            delta = delta / distance * speed;
            m_playerFish->setVelocity(delta.x(), delta.y());
        }
    }
    QGraphicsScene::mouseMoveEvent(event);
}

void GameScene::updateFrame()
{
    // 获取场景尺寸（只获取一次）
    qreal sceneWidth = sceneRect().width();
    qreal sceneHeight = sceneRect().height();

    // 更新所有鱼的位置
    for (FishItem *fish : std::as_const(m_fishList)) {
        fish->updatePosition();

        QPointF pos = fish->pos();

        // 边界环绕
        if (pos.x() < 0) fish->setPos(sceneWidth, pos.y());
        if (pos.x() > sceneWidth) fish->setPos(0, pos.y());
        if (pos.y() < 0) fish->setPos(pos.x(), sceneHeight);
        if (pos.y() > sceneHeight) fish->setPos(pos.x(), 0);
    }

    // 更新玩家鱼位置
    m_playerFish->updatePosition();

    // 玩家鱼边界限制（不环绕，只限制在边界内）
    QPointF playerPos = m_playerFish->pos();
    playerPos.setX(qBound(0.0, playerPos.x(), sceneWidth));
    playerPos.setY(qBound(0.0, playerPos.y(), sceneHeight));
    m_playerFish->setPos(playerPos);

    // 碰撞检测
    checkCollisions();
}

void GameScene::checkCollisions()
{
    for (int i = 0; i < m_fishList.size(); i++) {
        FishItem *fish = m_fishList[i];

        if (m_playerFish->collidesWithItem(fish)) {
            int fishSize = fish->getSize();

            if (fishSize < m_playerSize) {
                // 玩家更大 → 吃掉
                m_score += fishSize;
                m_playerSize += fishSize / 2 + 1;
                m_playerFish->setSize(m_playerSize);

                removeItem(fish);
                m_fishList.removeAt(i);
                delete fish;
                i--;

                updateUI();
            }
            else if (fishSize > m_playerSize) {
                // 鱼更大 → 游戏结束
                emit gameOver();
                m_timer->stop();
                m_spawnTimer->stop();
                return;
            }
            else {
                // 体型相等，50%概率获胜
                int result = QRandomGenerator::global()->bounded(2);
                if (result == 0) {
                    m_score += fishSize;
                    m_playerSize += 1;
                    m_playerFish->setSize(m_playerSize);

                    removeItem(fish);
                    m_fishList.removeAt(i);
                    delete fish;
                    i--;

                    updateUI();
                } else {
                    emit gameOver();
                    m_timer->stop();
                    m_spawnTimer->stop();
                    return;
                }
            }
        }
    }
}

void GameScene::spawnFish()
{
    qreal x = QRandomGenerator::global()->bounded(800);
    qreal y = QRandomGenerator::global()->bounded(600);

    int r = QRandomGenerator::global()->bounded(100);
    int size;
    QPixmap pixmap;

    if (r < 35) {  // 35% 绿色小鱼（体型1-2）
        size = QRandomGenerator::global()->bounded(1, 3);
        pixmap = QPixmap(":/images/build\\Desktop_Qt_6_10_2_MinGW_64_bit-Debug/GreenFish.png");
    }
    else if (r < 60) {  // 25% 黄色中鱼（体型3-4）
        size = QRandomGenerator::global()->bounded(3, 5);
        pixmap = QPixmap(":/images/build\\Desktop_Qt_6_10_2_MinGW_64_bit-Debug/YellowFish.png");
    }
    else if (r < 80) {  // 20% 蓝色大鱼（体型5-6）
        size = QRandomGenerator::global()->bounded(5, 7);
        pixmap = QPixmap(":/images/build\\Desktop_Qt_6_10_2_MinGW_64_bit-Debug/BlueFish.png");
    }
    else {  // 20% 紫色巨鱼（体型7-8）
        size = QRandomGenerator::global()->bounded(7, 9);
        pixmap = QPixmap(":/images/build\\Desktop_Qt_6_10_2_MinGW_64_bit-Debug/PurpleFish.png");
    }

    addFish(pixmap, x, y, 1, size);  // type=1 表示野生鱼
}

void GameScene::updateUI()
{
    emit scoreChanged(m_score);
}
