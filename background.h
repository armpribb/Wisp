#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "gameobject.h"

class Background : public GameObject
{
public:
    explicit Background(QObject *parent = nullptr);
    virtual ~Background();

public slots:
    virtual void update() override;
};

#endif // BACKGROUND_H
