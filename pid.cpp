#include "pid.h"

#include <QDebug>

double vectorNorm(double x, double y)
{
    return sqrt(x*x + y*y);
}

PID::PID(int timestep, double error) : dt(static_cast<double>(timestep)/1000), allowedError(error)
{
}

PID::~PID()
{
    qDebug() << "PID controller destroyed!";
}

void PID::update()
{
    if(vectorNorm(errorX, errorY) > allowedError)
    {
        double uX = 0;
        double uY = 0;

        auto proportionalTermX = Kp*errorX;
        auto proportionalTermY = Kp*errorY;

        integralX += errorX*dt;
        integralY += errorY*dt;

        auto integralTermX = Kp*integralX/Ti;
        auto integralTermY = Kp*integralY/Ti;

        auto derivativeTermX = Kp*Td*(errorX - previousErrorX)/dt;
        auto derivativeTermY = Kp*Td*(errorY - previousErrorY)/dt;

        uX = proportionalTermX + derivativeTermX + integralTermX;
        uY = proportionalTermY + derivativeTermY + integralTermY;

        previousErrorX = errorX;
        previousErrorY = errorY;

        emit pidControlUpdate(uX, uY);
    }
    else
    {
        reset();
    }
}

void PID::reset()
{
    integralX = 0;
    integralY = 0;
    previousErrorX = 0;
    previousErrorY = 0;
}

void PID::setError(double x, double y)
{
    errorX = x;
    errorY = y;
}

void PID::startControlLoop()
{
    if(timer == nullptr)
    {
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &PID::update);
        timer->start(static_cast<int>(dt*1000));
    }
}
