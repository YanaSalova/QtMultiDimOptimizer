#include "MyGraph.h"
#include <QDebug>

void MyGraph::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        QPointF clickPos = event->scenePos();
        emit mousePressed(clickPos);
   }
   QGraphicsScene::mousePressEvent(event);
}
