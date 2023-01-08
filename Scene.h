#ifndef SCENE_H
#define SCENE_H

#include "BulletFromEnemy.h"
#include "BulletFromPlayer.h"
#include "Enemy.h"
#include "Player.h"
#include "Eagle.h"
#include "Score.h"
#include "Health.h"
#include <QTimer>

#include <QMediaPlayer>    // decode mp3
#include <QAudioOutput>    // 播放、暫停、調音量 mp3

#include <QGraphicsScene>
//#include <QPropertyAnimation>

class Scene : public QGraphicsScene
{
    Q_OBJECT
//    Q_PROPERTY(qreal direction READ direction WRITE setDirection)
public:
    explicit Scene(QObject *parent = nullptr);
    virtual ~Scene();

    qreal direction() const;
    void setDirection(qreal newDirection);
    void setupEnemyBulletTimer();
//    void decreaseHealth(Player *player, BulletFromEnemy *bulletFromEnemy);


public slots:   // slot func. 內會放入接受 signal 以後要處理的事情 (在該 class 內對接)
    void spawnEnemy();
    void increaseScore(BulletFromPlayer *bulletFromPlayer, Enemy *enemy);
    void decreaseHealth(Player *player, BulletFromEnemy *bulletFromEnemy);
    void enemyShoot();
    void gameOver(BulletFromEnemy *bulletFromEnemy, Eagle *eagle, Player *player);

private:
    Player *player;
    Enemy *enemy;
    Eagle *eagle;
    QTimer *timer;
    QTimer *enemyBulletTimer;
    Score *score;
    Health *health;
    BulletFromEnemy *bulletFromEnemy;
//    BulletFromPlayer *bulletFromPlayer;
    QMediaPlayer *musicPlayer;
    QAudioOutput *musicOutput;
//    QMediaPlayer *bulletPlayer;
//    QAudioOutput *bulletOutput;

    // QGraphicsScene interface
//    qreal m_direction;
//    QPropertyAnimation *dirAnimation;

protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // SCENE_H
