#include "gameengine.h"

#include <QQuickItem>
#include <QDebug>

#include "background.h"
#include "wisp.h"

GameEngine::GameEngine(QQmlApplicationEngine *engine, QObject *parent) : QObject(parent), qmlEngine(engine)
{
    background = createAndRegisterGameObject<Background>();
    wisp = createAndRegisterGameObject<Wisp>();

    QObject::connect(background->getQmlComponent(), SIGNAL(mouseLeftButtonClicked(double,double)),
                     this, SLOT(handleMouseLeftButtonClicked(double,double)));
    QObject::connect(background->getQmlComponent(), SIGNAL(mouseRightButtonClicked(double,double)),
                     this, SLOT(handleMouseRightButtonClicked(double,double)));
    QObject::connect(background->getQmlComponent(), SIGNAL(mouseHoverPositionChanged(double,double)),
                     this, SLOT(handleMouseHoverPositionChanged(double,double)));
}

void GameEngine::updateAll()
{
    for(auto& elem: gameObjects)
    {
        elem->update();
    }
//    qDebug() << "UpdateAll";
}

void GameEngine::spawnGameObject(GameObject::Type objType)
{
    switch(objType)
    {
    case GameObject::Type::Background:
        // do nothing, only one playboard allowed
        break;
    case GameObject::Type::Wisp:
        break;
    case GameObject::Type::Obstruction:
        break;
    case GameObject::Type::Invalid:
    default:
        break;
    }
}

void GameEngine::handleMouseLeftButtonClicked(double mousePosX, double mousePosY)
{
    wisp->setTargetPosition(mousePosX, mousePosY);
}

void GameEngine::handleMouseRightButtonClicked(double mousePosX, double mousePosY)
{
    qDebug() << "Right mouse button clicked, x:" << mousePosX << ", y: " << mousePosY;
}


void GameEngine::handleMouseHoverPositionChanged(double mousePosX, double mousePosY)
{
    wisp->setOrientation(mousePosX, mousePosY);
}
