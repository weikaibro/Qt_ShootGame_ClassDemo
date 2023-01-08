#include "Score.h"
#include <QFont>

Score::Score()
{
    score = 0;
    setPlainText("分數: " + QString::number(score));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times", 20));
}

void Score::increase()
{
    score += 1000;
    setPlainText("Score: " + QString::number(score));
}

int Score::getScore()
{
    return score;
}
