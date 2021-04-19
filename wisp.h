#ifndef WISP_H
#define WISP_H

#include "gameobject.h"

class Wisp : public GameObject
{
public:
    explicit Wisp(QObject *parent = nullptr);
    virtual ~Wisp();

public slots:
    virtual void update() override;

    void setTargetPosition(int x, int y);
    void setOrientation(int x, int y);

signals:
    void positionChanged();

private:
    double velocity = 0;
    double acceleration = 0;
    double posX = 0;
    double posY = 0;
    double rotPhi = 0;

    double targPosX = 0;
    double targPosY = 0;
};

#endif // WISP_H
