#include "Health.h"
#include <QFont>

Health::Health()
{
    health = 3;

    setPlainText("生命值: " + QString::number(health));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times", 20));
}

void Health::decrease()
{
    health--;
    setPlainText("health: " + QString::number(health));
}

int Health::getHealth()
{
    return health;
}
