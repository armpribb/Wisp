#include "wisp.h"

#include <QQuickItem>
#include <QDebug>

#include <cmath>

const double pi = atan(1)*4;

double convertRadToDeg(double angle)
{
    return angle * 180 / pi;
}

Wisp::Wisp(QObject *parent): GameObject(parent, GameObject::Type::Wisp, QUrl(QStringLiteral("qrc:/Wisp.qml")))
{

}

Wisp::~Wisp()
{
    delete qmlComponent;
    qDebug() << "Wisp destroyed!";
}

void Wisp::update()
{
    posX = targPosX;
    posY = targPosY;

    qmlComponent->setProperty("x", static_cast<int>(round(posX)));
    qmlComponent->setProperty("y", static_cast<int>(round(posY)));
    qmlComponent->setProperty("rotation", static_cast<int>(round(convertRadToDeg(rotPhi))));
}

void Wisp::setTargetPosition(int x, int y)
{
    targPosX = x;
    targPosY = y;
}

void Wisp::setOrientation(int x, int y)
{
    double xDiff = x - posX;
    double yDiff = y - posY;

    rotPhi = atan2(yDiff, xDiff);
}
