#ifndef WISP_H
#define WISP_H

#include <QThread>

#include "gameobject.h"

class Wisp : public GameObject
{
    Q_OBJECT

public:
    explicit Wisp(QObject *parent = nullptr);
    virtual ~Wisp();

public slots:
    virtual void update() override;

    void setTargetPosition(double x, double y);
    void setOrientation(double x, double y);

    void updatePosition(double ux, double uy);

signals:
    void errorUpdated(double x, double y);

private:
    double currentX = 0;
    double currentY = 0;
    double targetX = 0;
    double targetY = 0;
    double rotPhi = 0;

    double lastMouseX = 0;
    double lastMouseY = 0;

    QThread pidControlThread;
};

#endif // WISP_H
