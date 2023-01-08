#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include <QList>
#include <QGraphicsScene>

Bullet::Bullet()
{
    setPixmap(QPixmap(":/image/playerBullet.png"));  // 包成 QPixmap 物件即可實作圖片
    setPixmap(QPixmap(":/image/enemyBullet.png"));

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Bullet::move);
    timer->start(50);
}

Bullet::~Bullet()
{
    delete timer;
}

void Bullet::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0; i < colliding_items.size(); i++) {
        if (typeid(colliding_items[i]) == typeid(Enemy)) {   // 敵人被攻擊
            emit bulletHitsEnemy(this, (Enemy*) colliding_items[i]);
            return;
        }
        if (typeid(colliding_items[i]) == typeid(Player)) {  // 玩家被攻擊
            emit bulletHitsPlayer(this, (Player*) colliding_items[i]);
            return;
        }
    }
    setPos(x(), y() - 10);
    if (y() + boundingRect().height() < 0) {    // 子彈射出視窗就 delete bullet
        scene()->removeItem(this);
        delete this;
    }


}
