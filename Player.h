#ifndef PLAYER_H
#define PLAYER_H

//#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

class Player : public QGraphicsPixmapItem
{
public:
    Player(QPixmap pixmap);
};

#endif // PLAYER_H
