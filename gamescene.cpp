#include "gamescene.h"
#include <QGraphicsSceneMouseEvent>
#include <QRandomGenerator>
#include <QGraphicsView>
#include <QDebug>
//#include <QKeyEvent>

GameScene::GameScene(QObject *parent)
    :  QGraphicsScene(parent)
    , m_playerFish(nullptr)
    , m_score(0)
    , m_playerSize(2)
    , m_exp(0)
    , m_nextExp(1)

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
    m_playerSize = 2;
    m_exp = 0;
    m_nextExp = 1;
    updateUI();

    for (FishItem *fish : m_fishList) {
        removeItem(fish);
        delete fish;
    }
    m_fishList.clear();

    // 关键：清除玩家鱼的引用，但不删除（因为下次重新创建）
    if (m_playerFish) {
        removeItem(m_playerFish);
        m_playerFish = nullptr;
    }
}

void GameScene::startGame()
{
    for (FishItem *fish : m_fishList) {
        removeItem(fish);
        delete fish;
    }
    m_fishList.clear();

    QPixmap greenPixmap(":/images/build\\Desktop_Qt_6_10_2_MinGW_64_bit-Debug/GreenFish.png");
    for (int i = 0; i < 6; i++) {
        int size = QRandomGenerator::global()->bounded(1, 3);
        qreal x = -50 - i * 20;  // 从屏幕左边外面
        qreal y = QRandomGenerator::global()->bounded(80, 520);
        qreal vx = QRandomGenerator::global()->bounded(2, 4);

        FishItem *fish = new FishItem(greenPixmap, 1);
        fish->setPos(x, y);
        fish->setSize(size);
        fish->setVelocity(vx, 0);
        addItem(fish);
        m_fishList.append(fish);
    }

    for (int i = 0; i < 6; i++) {
        int size = QRandomGenerator::global()->bounded(1, 3);
        qreal x = 850 + i * 20;  // 从屏幕右边外面
        qreal y = QRandomGenerator::global()->bounded(80, 520);
        qreal vx = -QRandomGenerator::global()->bounded(2, 4);

        FishItem *fish = new FishItem(greenPixmap, 1);
        fish->setPos(x, y);
        fish->setSize(size);
        fish->setVelocity(vx, 0);
        addItem(fish);
        m_fishList.append(fish);
    }

    QPixmap yellowPixmap(":/images/build\\Desktop_Qt_6_10_2_MinGW_64_bit-Debug/YellowFish.png");
    for (int i = 0; i < 2; i++) {
        int size = QRandomGenerator::global()->bounded(3, 5);
        // 左侧一条
        FishItem *fishLeft = new FishItem(yellowPixmap, 1);
        fishLeft->setPos(-80, QRandomGenerator::global()->bounded(150, 450));
        fishLeft->setSize(size);
        fishLeft->setVelocity(2, 0);
        addItem(fishLeft);
        m_fishList.append(fishLeft);

        // 右侧一条
        FishItem *fishRight = new FishItem(yellowPixmap, 1);
        fishRight->setPos(880, QRandomGenerator::global()->bounded(150, 450));
        fishRight->setSize(size);
        fishRight->setVelocity(-2, 0);
        addItem(fishRight);
        m_fishList.append(fishRight);
    }

    qDebug() << "startGame: 已生成" << m_fishList.size() << "条鱼";

    // 启动定时器
    m_timer->start(16);
    m_spawnTimer->start(3000);
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
    if (m_playerFish) {
        removeItem(m_playerFish);
        delete m_playerFish;
    }
    m_playerFish = fish;
    m_playerFish->setSize(m_playerSize);
    addItem(m_playerFish);
}


void GameScene::updateFrame()
{
    if (!m_playerFish) return;

    qreal sceneWidth = sceneRect().width();
    qreal sceneHeight = sceneRect().height();

    // ===== 更新其他鱼的位置 =====
    for (FishItem *fish : std::as_const(m_fishList)) {
        fish->updatePosition();
        QPointF pos = fish->pos();

        if (pos.x() > sceneWidth + 100) {
            fish->setPos(-50, QRandomGenerator::global()->bounded(50, 550));
        } else if (pos.x() < -100) {
            fish->setPos(sceneWidth + 50, QRandomGenerator::global()->bounded(50, 550));
        }

        if (pos.y() < 0) fish->setPos(pos.x(), 0);
        if (pos.y() > sceneHeight) fish->setPos(pos.x(), sceneHeight);
    }

    // 更新玩家鱼位置（鼠标控制）
    m_playerFish->updatePosition();

    // 玩家鱼边界限制
    QPointF playerPos = m_playerFish->pos();
    playerPos.setX(qBound(0.0, playerPos.x(), sceneWidth));
    playerPos.setY(qBound(0.0, playerPos.y(), sceneHeight));
    m_playerFish->setPos(playerPos);

    checkCollisions();
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

void GameScene::checkCollisions()
{
    QList<FishItem*> toEat;
    FishItem* toKill = nullptr;

    for (FishItem *fish : m_fishList) {
        if (m_playerFish->collidesWithItem(fish)) {
            int fishSize = fish->getSize();

            if (fishSize < m_playerSize) {
                // 玩家更大 → 吃掉
                toEat.append(fish);
            }
            else if (fishSize >= m_playerSize) {
                // 鱼更大 → 游戏结束
                toKill = fish;
                break;
            }
            // else {
            //     // 体型相等 → 玩家吃掉鱼（为了游戏体验）
            //     toEat.append(fish);
            // }
        }
    }

    if (toKill != nullptr) {
        emit gameOver();
        m_timer->stop();
        m_spawnTimer->stop();
        return;
    }

    for (FishItem *fish : toEat) {
        int fishSize = fish->getSize();
        m_score += fishSize;

        // 吃一条鱼，经验+1
        m_exp++;

        // 检查是否可以升级
        if (m_exp >= m_nextExp) {
            m_playerSize++;
            m_playerFish->setSize(m_playerSize);

            // 更新下一级需要的经验值（每次+1）
            m_nextExp++;

            // 重置经验值，保留超出部分
            m_exp = 0;

            qDebug() << "升级！当前体型:" << m_playerSize << "下级需要:" << m_nextExp << "条鱼";
        }

        qDebug() << "吃鱼，经验:" << m_exp << "/" << m_nextExp << "体型:" << m_playerSize;

        removeItem(fish);
        m_fishList.removeOne(fish);
        delete fish;

        updateUI();
    }
}

void GameScene::spawnFish()
{
    int r = QRandomGenerator::global()->bounded(100);
    int size;
    QPixmap pixmap;

    if (r < 40) {
        size = QRandomGenerator::global()->bounded(1, 3);
        pixmap = QPixmap(":/images/build\\Desktop_Qt_6_10_2_MinGW_64_bit-Debug/GreenFish.png");
    }else if (r < 65){
        size = QRandomGenerator::global()->bounded(3, 5);
        pixmap = QPixmap(":/images/build\\Desktop_Qt_6_10_2_MinGW_64_bit-Debug/RedFish.png");
    }else if (r < 85) {
        size = QRandomGenerator::global()->bounded(5, 7);
        pixmap = QPixmap(":/images/build\\Desktop_Qt_6_10_2_MinGW_64_bit-Debug/YellowFish.png");
    }else if (r < 95) {
        size = QRandomGenerator::global()->bounded(7, 9);
        pixmap = QPixmap(":/images/build\\Desktop_Qt_6_10_2_MinGW_64_bit-Debug/BlueFish.png");
    }else {
        size = QRandomGenerator::global()->bounded(9, 11);
        pixmap = QPixmap(":/images/build\\Desktop_Qt_6_10_2_MinGW_64_bit-Debug/PurpleFish.png");
    }

    // 随机选择从左侧还是右侧进入
    int side = QRandomGenerator::global()->bounded(2);
    qreal x, y, vx;

    if (side == 0) {
        // 从左侧进入，向右游
        x = -50;
        y = QRandomGenerator::global()->bounded(50, 550);
        vx = QRandomGenerator::global()->bounded(2, 4);
    } else {
        // 从右侧进入，向左游
        x = 850;
        y = QRandomGenerator::global()->bounded(50, 550);
        vx = -QRandomGenerator::global()->bounded(2, 4);
    }

    FishItem *fish = new FishItem(pixmap, 1);
    fish->setPos(x, y);
    fish->setSize(size);
    fish->setVelocity(vx, 0);
    addItem(fish);
    m_fishList.append(fish);
}

void GameScene::updateUI()
{
    emit scoreChanged(m_score);
}
