#include "BulletFromEnemy.h"
//#include "Enemy.h"
#include "Player.h"
#include "Eagle.h"
#include <QList>
#include <QGraphicsScene>

BulletFromEnemy::BulletFromEnemy()
{
    setPixmap(QPixmap(":/image/enemyBullet.png"));
    shoot();

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &BulletFromEnemy::shoot);
    timer->start(50);
}

BulletFromEnemy::~BulletFromEnemy()
{
    delete timer;
}

void BulletFromEnemy::collideWithPlayer()
{
//    QList<QGraphicsItem *> colliding_items = player->collidingItems();
//    foreach (QGraphicsItem *item, colliding_items) {
//        BulletFromEnemy *bulletFromEnemy = dynamic_cast<BulletFromEnemy*> (item);
//        if (bulletFromEnemy) return true;
//    }
//    return false;

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0; i < colliding_items.size(); i++) {
        if (typeid(*colliding_items[i]) == typeid(Player)) {
            emit bulletHitsPlayer(this, (Player*) colliding_items[i]);     // 發送 signal 給 scene
            return;
        }
    }
}


bool BulletFromEnemy::collideWithMyBaseEagle()
{
    QList<QGraphicsItem *> colliding_items = eagle->collidingItems();
    foreach (QGraphicsItem *item, colliding_items) {
        BulletFromEnemy *bulletFromEnemy = dynamic_cast<BulletFromEnemy*> (item);
        if (bulletFromEnemy) return true;
    }
    return false;
}



void BulletFromEnemy::shoot()
{
//    BulletFromEnemy *bulletFromEnemy = new BulletFromEnemy();
//    Enemy *enemy = new Enemy(QPixmap(":/image/tank.png"));
//    bulletFromEnemy->setPos(enemy->pos());

    setPos(x(), y() + 10);
    collideWithPlayer();

//    if (collideWithPlayer()) {
//        emit collideFail();
//    }
}
