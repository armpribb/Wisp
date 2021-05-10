#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QObject>
#include <QUrl>

class QQmlApplicationEngine;
class QQuickItem;
class QUrl;

class GameObject : public QObject
{
    Q_OBJECT

public:
    enum class Type : int {
        Background = 0,
        Wisp,
        Obstruction,
        UI,
        Invalid
    };
    Q_ENUM(Type)

    explicit GameObject(QObject *parent, Type objType, const QUrl &qmlFileUrl);
    virtual ~GameObject() = default;

signals:
//    void updated();

public slots:
    virtual void update() = 0;

public:
    void registerAsQmlGameObject(QQmlApplicationEngine *engine);
    QQuickItem *getQmlComponent() const {   return qmlComponent;    }

protected:
    QQuickItem *qmlComponent = nullptr;
    const Type type = Type::Invalid;
    const QUrl qmlFilename;

    double posX = 0;
    double posY = 0;
    double rotPhi = 0;

    bool rotatable = false;
};

#endif // GAMEOBJECT_H
