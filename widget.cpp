#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsPixmapItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget), scene(new Scene(this))
{
    ui->setupUi(this);

    //    scene->setSceneRect(-144, -256, 288, 512);
    scene->setSceneRect(0, 0, 600, 600);
    QGraphicsPixmapItem *pixItem = new QGraphicsPixmapItem(QPixmap(":/image/background.jpg"));
    pixItem->setPos(0, 0);
    scene->addItem(pixItem);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(600, 600);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

Widget::~Widget()
{
    delete ui;
}

