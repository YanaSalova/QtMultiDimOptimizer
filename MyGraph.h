#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class MyGraph : public QGraphicsScene
{
    Q_OBJECT

signals:
    void mousePressed(const QPointF &pos);

public:
    explicit MyGraph(QObject *parent = nullptr) : QGraphicsScene(parent) {};
    ~MyGraph() override {};



protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // MYGRAPHICSSCENE_H
