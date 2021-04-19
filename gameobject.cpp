#include "gameobject.h"

#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQuickWindow>

GameObject::GameObject(QObject *parent, GameObject::Type objType, const QUrl &qmlFileUrl) : QObject(parent), type(objType), qmlFilename(qmlFileUrl)
{

}

void GameObject::registerAsQmlGameObject(QQmlApplicationEngine *engine)
{
    QQuickWindow *window = qobject_cast<QQuickWindow*>(engine->rootObjects().at(0));
    QQuickItem *root = window->contentItem();
    QQmlComponent component(engine, qmlFilename);
    qmlComponent = qobject_cast<QQuickItem*>(component.create());
    QQmlEngine::setObjectOwnership(qmlComponent, QQmlEngine::CppOwnership);
    qmlComponent->setParentItem(root);
    qmlComponent->setParent(engine);
}
