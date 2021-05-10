#include "controlpanel.h"

#include <QQuickItem>
#include <QDebug>

ControlPanel::ControlPanel(QObject *parent) : GameObject(parent, GameObject::Type::UI, QUrl(QStringLiteral("qrc:/ControlPanel.qml")))
{

}

ControlPanel::~ControlPanel()
{
    delete qmlComponent;
    qDebug() << "ControlPanel destroyed!";
}
