#include "Enemy.h"
#include <stdlib.h>
#include <QGraphicsScene>
#include <QRandomGenerator>

Enemy::Enemy(QPixmap pixmap)
{
    enemy = new QGraphicsPixmapItem(QPixmap(":/image/tank.png"));
    enemy->setPos(QPointF(300, 300));
    setPixmap(pixmap);

//    move();
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Enemy::move);
    timer->start(300);
}

Enemy::~Enemy()
{
    delete timer;
}

void Enemy::move()
{
    // 敵人移動路徑，隨機往上下左右移動
    int mov = QRandomGenerator::global()->bounded(0, 4);
    if (mov == 0) {
//        moveEasing("x", 50);  //right
        setPos(x() + 30, y());
    } else if (mov == 1) {
//        moveEasing("x", -30);  //left
        setPos(x() - 30, y());
    } else if  (mov == 2) {
//        moveEasing("y", 30);  //down
        setPos(x(), y() + 30);
    } else if (mov == 3) {
//        moveEasing("y", -30); //up
        setPos(x(), y() - 30);
    }

    // 敵人撞到牆壁往反方向走，避免走出視窗
    if (x() <= 0) {
//      moveEasing("x", 10);
        setPos(x() + 30, y());
    } else if (x() >= 500) {
//        moveEasing("x", -30);
        setPos(x() - 30, y());
    } else if (y() <= 0) {
//        moveEasing("y", 30);
        setPos(x(), y() + 30);
    } else if (y() >= 500) {
//        moveEasing("y", 30);
        setPos(x(), y() - 30);
    }

}

//void Enemy::moveEasing(std::string direction, int dist)
//{
//    if (direction == "x") {
//        xAnimation = new QPropertyAnimation(this, "x", this);
//        xAnimation->setStartValue(0);
//        xAnimation->setEndValue(dist);
//        xAnimation->setEasingCurve(QEasingCurve::Linear);
//        xAnimation->setDuration(800);
//        connect(xAnimation, &QPropertyAnimation::finished, [=]() {
//            xAnimation->stop();
//            move();
//        });
//        xAnimation->start();
//    } else {
//        yAnimation = new QPropertyAnimation(this, "y", this);
//        yAnimation->setStartValue(0);
//        yAnimation->setEndValue(dist);
//        yAnimation->setEasingCurve(QEasingCurve::Linear);
//        yAnimation->setDuration(800);
//        connect(yAnimation, &QPropertyAnimation::finished, [=]() {
//            yAnimation->stop();
//            move();
//        });
//        yAnimation->start();
//    }
//}

//qreal Enemy::x() const
//{
//    return m_x;
//}

//void Enemy::setX(qreal newX)
//{
//    m_x = newX;
//    setPos(QPointF(newX, pos().y()));
//}

//qreal Enemy::y() const
//{
//    return m_y;
//}

//void Enemy::setY(qreal newY)
//{
//    m_y = newY;
//    setPos(QPointF(pos().x(), newY));
//}
