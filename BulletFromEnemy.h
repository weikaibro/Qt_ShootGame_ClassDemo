#ifndef BULLETFROMENEMY_H
#define BULLETFROMENEMY_H

#include "Player.h"
#include "Eagle.h"
#include <QTimer>
#include <QObject>
#include <QGraphicsPixmapItem>

class BulletFromEnemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    BulletFromEnemy();
    ~BulletFromEnemy();

//    void collideWithPlayer();
    bool collideWithMyBaseEagle();

    qreal direction() const;
    void setDirection(qreal newDirection);
    void shoot();


public slots:
    void collideWithPlayer();

signals:
    void collideFail();
    void bulletHitsPlayer(BulletFromEnemy *bullet, Player *player);
    void bulletHitsMyBaseEagle(BulletFromEnemy *bullet, Eagle *eagle);


private:
    QTimer *timer;
    Player *player;
    Eagle *eagle;
    BulletFromEnemy *bulletFromEnemy;
};

#endif // BULLET_H
