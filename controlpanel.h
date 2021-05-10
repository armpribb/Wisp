#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include "gameobject.h"

class ControlPanel : public GameObject
{
    Q_OBJECT
public:
    explicit ControlPanel(QObject *parent = nullptr);
    virtual ~ControlPanel();

public slots:
    virtual void update() override {}
};

#endif // CONTROLPANEL_H
