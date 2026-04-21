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
}

void FishItem::setSize(int size)
{
    m_size = size;
    qreal scale = 0.02 + size * 0.01;
    setScale(scale);
}
