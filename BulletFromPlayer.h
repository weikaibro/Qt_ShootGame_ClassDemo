#ifndef BULLETFROMPLAYER_H
#define BULLETFROMPLAYER_H

#include "Enemy.h"
#include "Eagle.h"
#include <QTimer>
#include <QObject>
#include <QGraphicsPixmapItem>

class BulletFromPlayer : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    BulletFromPlayer();
    ~BulletFromPlayer();

public slots:
    void collideWithEnemy();
    void collideWithMyBaseEagle();
    void playerShoot();

signals:
    void bulletHitsEnemy(BulletFromPlayer *bullet, Enemy *enemy);
    void bulletHitsMyBaseEagle(BulletFromPlayer *bullet, Eagle *eagle);
private:
    Enemy *enemy;
    QTimer *timer;
    Eagle *eagle;
};

#endif // BULLETFROMPLAYER_H
