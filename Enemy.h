#ifndef ENEMY_H
#define ENEMY_H

#include <QTimer>
#include <QObject>
//#include <QPropertyAnimation>
#include <QGraphicsPixmapItem>

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
//    Q_PROPERTY(qreal x READ x WRITE setX)
//    Q_PROPERTY(qreal y READ y WRITE setY)
public:
    Enemy(QPixmap pixmap);
    ~Enemy();

signals:
//    void enemyHitsTheGround(Enemy *enemy);

public:
    void move();
//    void moveEasing(std::string direction, int dist);

//    qreal x() const;
//    void setX(qreal newX);

//    qreal y() const;
//    void setY(qreal newY);

private:
    QGraphicsPixmapItem *enemy;
//    QPropertyAnimation *xAnimation, *yAnimation;
    QTimer *timer;
//    qreal m_x;
//    qreal m_y;
};

#endif // ENEMY_H
