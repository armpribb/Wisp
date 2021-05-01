#include "wisp.h"

#include <QQuickItem>
#include <QDebug>

#include <cmath>

#include "pid.h"

const double pi = atan(1)*4;

double convertRadToDeg(double angle)
{
    return angle * 180 / pi;
}

Wisp::Wisp(QObject *parent): GameObject(parent, GameObject::Type::Wisp, QUrl(QStringLiteral("qrc:/Wisp.qml")))
{
    PID* pidController = new PID(10, 0.001);
    pidController->moveToThread(&pidControlThread);
    connect(&pidControlThread, &QThread::finished, pidController, &QObject::deleteLater);
    connect(this, SIGNAL(errorUpdated(double,double)), pidController, SLOT(setError(double,double)));
    connect(pidController, SIGNAL(pidControlUpdate(double,double)), this, SLOT(updatePosition(double,double)));
    connect(&pidControlThread, &QThread::started, pidController, &PID::startControlLoop);
    pidControlThread.start();
}

Wisp::~Wisp()
{
    pidControlThread.quit();
    pidControlThread.wait();
    delete qmlComponent;
    qDebug() << "Wisp destroyed!";
}

void Wisp::update()
{
//    rotPhi = atan2(lastMouseY - currentY, lastMouseX - currentX);

    qmlComponent->setProperty("x", currentX);
    qmlComponent->setProperty("y", currentY);
    qmlComponent->setProperty("rotation", convertRadToDeg(rotPhi));
}

void Wisp::setTargetPosition(double x, double y)
{
    targetX = x;
    targetY = y;

    emit errorUpdated(targetX - currentX, targetY - currentY);
}

void Wisp::setOrientation(double x, double y)
{
//    lastMouseX = x;
//    lastMouseY = y;

    double xDiff = x - currentX;
    double yDiff = y - currentY;

    rotPhi = atan2(yDiff, xDiff);
}

void Wisp::updatePosition(double ux, double uy)
{
    currentX += ux;
    currentY += uy;

    emit errorUpdated(targetX - currentX, targetY - currentY);
}
