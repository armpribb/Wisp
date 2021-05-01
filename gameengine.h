#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QObject>
#include <QVector>

#include "gameobject.h"

class Background;
class Wisp;

class QQmlApplicationEngine;

class GameEngine : public QObject
{
    Q_OBJECT
public:
    explicit GameEngine(QQmlApplicationEngine *engine, QObject *parent = nullptr);

signals:
//    void allUpdated();

public slots:
    void updateAll();
    void handleMouseLeftButtonClicked(double mousePosX, double mousePosY);
    void handleMouseRightButtonClicked(double mousePosX, double mousePosY);
    void handleMouseHoverPositionChanged(double mousePosX, double mousePosY);

public:
    void spawnGameObject(GameObject::Type objType);

private:
    QVector<GameObject*> gameObjects;
    QQmlApplicationEngine *qmlEngine;

    Background *background;
    Wisp *wisp;
};

#endif // GAMEENGINE_H
