#ifndef BULLET_H
#define BULLET_H

#include "Enemy.h"
#include "Player.h"
#include <QTimer>
#include <QObject>
//#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet();
    ~Bullet();

public slots:
    void move();

signals:
    void bulletHitsEnemy(Bullet *bullet, Enemy *enemy);
    void bulletHitsPlayer(Bullet *bullet, Player *player);

private:
    QTimer *timer;
};

#endif // BULLET_H
