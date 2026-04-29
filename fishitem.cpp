#include "fishitem.h"

FishItem::FishItem(const QPixmap &pixmap, int type)
    : QGraphicsPixmapItem(pixmap)
    , m_vx(0), m_vy(0)
    , m_size(1)
    , m_type(type)
{
    if (type == 0) {
        setCursor(QCursor(Qt::PointingHandCursor));
    }
}

void FishItem::setVelocity(qreal vx, qreal vy)
{
    m_vx = vx;
    m_vy = vy;
}

void FishItem::updatePosition()
{
    setPos(x() + m_vx, y() + m_vy);

    // 根据速度方向自动翻转鱼头
    if (m_vx > 0) {
        // 向右游 → 需要翻转（因为原始图片朝左）
        setTransform(QTransform::fromScale(-1, 1));
    } else if (m_vx < 0) {
        // 向左游 → 不需要翻转（原始图片已经朝左）
        setTransform(QTransform::fromScale(1, 1));
    }
}

void FishItem::setSize(int size)
{
    m_size = size;
    qreal scale = 0.02 + size * 0.01;
    setScale(scale);
}

void FishItem::setFlipped(bool flipped)
{
    if (flipped) {
        setTransform(QTransform::fromScale(-1, 1));
    } else {
        setTransform(QTransform::fromScale(1, 1));
    }
}
