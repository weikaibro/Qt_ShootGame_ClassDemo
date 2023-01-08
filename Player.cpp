#include "Player.h"

Player::Player(QPixmap pixmap)
{
    setPos(QPointF(0, 500));
    setPixmap(pixmap);
}
