#ifndef FISHITEM_H
#define FISHITEM_H

#include <QGraphicsPixmapItem>
#include <QCursor>

class FishItem : public QGraphicsPixmapItem
{
public:
    FishItem(const QPixmap &pixmap, int type = 0);

    void setVelocity(qreal vx, qreal vy);
    void updatePosition();
    void setSize(int size);
    int getSize() const { return m_size; }
    int getType() const { return m_type; }
    void setFlipped(bool flipped);

private:
    qreal m_vx, m_vy;
    int m_size;
    int m_type;
};

#endif
