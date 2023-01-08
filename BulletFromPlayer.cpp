#include "BulletFromPlayer.h"
#include "Enemy.h"
#include <QList>
#include <QGraphicsScene>

BulletFromPlayer::BulletFromPlayer()
{
    setPixmap(QPixmap(":/image/playerBullet .png"));

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &BulletFromPlayer::playerShoot);    // connect(監聽的物件, 監聽的事件, 事件接收者, 事件的處理函數);
    timer->start(50);
}

BulletFromPlayer::~BulletFromPlayer()
{
    delete timer;
}

void BulletFromPlayer::collideWithEnemy()
{
//    QList<QGraphicsItem *> colliding_items = enemy->collidingItems();
//    foreach (QGraphicsItem *item, colliding_items) {
//        BulletFromPlayer *bulletFromPlayer = dynamic_cast<BulletFromPlayer*> (item);
//        if (bulletFromPlayer) {
//            emit bulletHitsEnemy(this, enemy);
//        };
//    }
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0; i < colliding_items.size(); i++) {
        if (typeid(*colliding_items[i]) == typeid(Enemy)) {
            emit bulletHitsEnemy(this, (Enemy*) colliding_items[i]);     // 發送 signal 給 scene
            return;
        }
    }
}

void BulletFromPlayer::collideWithMyBaseEagle()
{
    QList<QGraphicsItem *> colliding_items = eagle->collidingItems();
    foreach (QGraphicsItem *item, colliding_items) {
        BulletFromPlayer *bulletFromPlayer = dynamic_cast<BulletFromPlayer*> (item);
        if (bulletFromPlayer) {
            emit bulletHitsMyBaseEagle(this, eagle);
        };
    }
}

void BulletFromPlayer::playerShoot()
{
    setPos(x(), y() - 10);
    collideWithEnemy();
}
