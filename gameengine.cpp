#include "gameengine.h"

#include <QQuickItem>
#include <QDebug>

#include "background.h"
#include "wisp.h"

GameEngine::GameEngine(QQmlApplicationEngine *engine, QObject *parent) : QObject(parent), qmlEngine(engine)
{
    background = new Background(this);
    background->registerAsQmlGameObject(engine);
    gameObjects.append(background);

    wisp = new Wisp(this);
    wisp->registerAsQmlGameObject(engine);
    gameObjects.append(wisp);

    QObject::connect(background->getQmlComponent(), SIGNAL(mouseLeftButtonClicked(int,int)),
                     this, SLOT(handleMouseLeftButtonClicked(int,int)));
    QObject::connect(background->getQmlComponent(), SIGNAL(mouseRightButtonClicked(int,int)),
                     this, SLOT(handleMouseRightButtonClicked(int,int)));
    QObject::connect(background->getQmlComponent(), SIGNAL(mouseHoverPositionChanged(int,int)),
                     this, SLOT(handleMouseHoverPositionChanged(int,int)));
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

void GameEngine::handleMouseLeftButtonClicked(int posX, int posY)
{
    wisp->setTargetPosition(posX, posY);
}

void GameEngine::handleMouseRightButtonClicked(int posX, int posY)
{
    qDebug() << "Right mouse button clicked, x:" << posX << ", y: " << posY;
}


void GameEngine::handleMouseHoverPositionChanged(int posX, int posY)
{
    wisp->setOrientation(posX, posY);
}
