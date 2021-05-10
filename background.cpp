#include "background.h"

#include <QQuickItem>
#include <QDebug>

Background::Background(QObject *parent): GameObject(parent, GameObject::Type::Background, QUrl(QStringLiteral("qrc:/Background.qml")))
{

}

Background::~Background()
{
    delete qmlComponent;
    qDebug() << "Background destroyed!";
}

void Background::update()
{
//    qDebug() << "Background updated!";
}
