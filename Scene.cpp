#include "Scene.h"
#include "Enemy.h"
#include "Eagle.h"
#include "Player.h"
#include "BulletFromEnemy.h"
#include "BulletFromPlayer.h"
#include <QKeyEvent>

Scene::Scene(QObject *parent)
    : QGraphicsScene{parent}
{
    setupEnemyBulletTimer();

    player = new Player(QPixmap(":/image/player.png"));
    addItem(player);
    player->setZValue(1);

    eagle = new Eagle(QPixmap(":/image/Eagle_base.png"));
    addItem(eagle);
    eagle->setZValue(1);


    spawnEnemy();



    health = new Health();
    addItem(health);
    health->setZValue(1);

    score = new Score();
    health->setPos(score->x(), score->y() + 40);
    addItem(score);
    score->setZValue(1);

//    bulletFromEnemy = new BulletFromEnemy();
//    addItem(bulletFromEnemy);
//    bulletFromEnemy->setZValue(1);
    musicOutput= new QAudioOutput();
    musicOutput->setVolume(50);
    musicPlayer=new QMediaPlayer();
    musicPlayer->setAudioOutput(musicOutput);
    musicPlayer->setSource(QUrl("qrc:/sound/victory.mp3"));
    musicPlayer->play();

}

Scene::~Scene()
{
    delete timer;
}

void Scene::spawnEnemy()
{
    enemy = new Enemy(QPixmap(":/image/tank.png"));
    addItem(enemy);
    enemy->setZValue(1);

}

void Scene::increaseScore(BulletFromPlayer *bulletFromPlayer, Enemy *enemy)
{
    removeItem(bulletFromPlayer);
    removeItem(enemy);
    delete bulletFromPlayer;
    delete enemy;
    score->increase();
    enemyBulletTimer->stop();
}

void Scene::setupEnemyBulletTimer()
{
    enemyBulletTimer = new QTimer(this);
    connect(enemyBulletTimer, &QTimer::timeout, this, &Scene::enemyShoot);
//    connect(enemyBulletTimer, &QTimer::timeout, [=]() {
//        BulletFromEnemy *bulletFromEnemy = new BulletFromEnemy();
//        connect(bulletFromEnemy, &BulletFromEnemy::collideFail, [=]() {
//            enemyBulletTimer->stop();
//            decreaseHealth(player, bulletFromEnemy);
//        });
//        addItem(bulletFromEnemy);
//    });
    enemyBulletTimer->start(1000);
}

void Scene::enemyShoot()
{
    BulletFromEnemy *bulletFromEnemy = new BulletFromEnemy();

    bulletFromEnemy->setPos(enemy->pos());
    addItem(bulletFromEnemy);
//    bulletFromEnemy->setPos(bulletFromEnemy->x(), bulletFromEnemy->y() + 10);
}

void Scene::decreaseHealth(Player *player, BulletFromEnemy *bulletFromEnemy)
{
    removeItem(bulletFromEnemy);
    removeItem(player);
    delete player;
    delete bulletFromEnemy;
    health->decrease();
}


void Scene::gameOver(BulletFromEnemy *bulletFromEnemy, Eagle *eagle, Player *player)
{
    removeItem(enemy);
    removeItem(bulletFromEnemy);
    delete enemy;
    delete bulletFromEnemy;

    removeItem(eagle);
    delete eagle;
    removeItem(player);
    delete player;

}


void Scene::keyPressEvent(QKeyEvent *event)
{
    QPointF pos = player->pos();

    if (event->key() == Qt::Key_Left && pos.x() > 0) {
        player->setPos(pos + QPoint(-10, 0));
    } else if (event->key() == Qt::Key_Right && pos.x() < 500) {
        player->setPos(pos + QPoint(10, 0));
    } else if (event->key() == Qt::Key_Up && pos.y() > 0) {
        player->setPos(pos + QPoint(0, -10));
    } else if (event->key() == Qt::Key_Down && pos.y() < 500) {
        player->setPos(pos + QPoint(0, 10));
    } else if (event->key() == Qt::Key_Space) {
//        bulletFromPlayer->setPos(player->pos());
//        addItem(bulletFromPlayer);

        BulletFromPlayer *bulletFromPlayer = new BulletFromPlayer();
        BulletFromEnemy *bulletFromEnemy = new BulletFromEnemy();

//        connect(bulletFromEnemy, &BulletFromEnemy::bulletHitsPlayer, this, &Scene::decreaseHealth);
        connect(bulletFromPlayer, &BulletFromPlayer::bulletHitsEnemy, this, &Scene::increaseScore);
//        connect(bulletFromPlayer, &BulletFromPlayer::bulletHitsEnemy, this, &Scene::spawnEnemy);
//        bulletFromPlayer->setZValue(1);
        bulletFromPlayer->setPos(player->pos());

        addItem(bulletFromPlayer);

//        dirAnimation = new QPropertyAnimation(this, "direction", this);
//        dirAnimation->setStartValue(player->pos().y());
//        dirAnimation->setEndValue(0);
//        dirAnimation->setEasingCurve(QEasingCurve::Linear);
//        dirAnimation->setDuration(1000);

//        connect(dirAnimation, &QPropertyAnimation::finished, [=]() {
//            removeItem(bulletFromPlayer);
//            delete bulletFromPlayer;
//        });
//        dirAnimation->start();

    }
}

//qreal Scene::direction() const
//{
//    return m_direction;
//}

//void Scene::setDirection(qreal newDirection)
//{
//    m_direction = newDirection;
//    // 攻擊到敵人: 敵人重生(spawnEnemy) + 玩家增加分數(increaseScore)
//    connect(bulletFromPlayer, &BulletFromPlayer::bulletHitsEnemy, this, &Scene::increaseScore);
//    connect(bulletFromPlayer, &BulletFromPlayer::bulletHitsEnemy, this, &Scene::spawnEnemy);
//    bulletFromPlayer->setPos(QPointF(bulletFromPlayer->pos().x(), newDirection));
//}

