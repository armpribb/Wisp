#ifndef PID_H
#define PID_H

#include <QObject>
#include <QTimer>
#include <QDebug>

class PID : public QObject
{
    Q_OBJECT

public:
    explicit PID(int timestep, double error);
    ~PID();

    void update();

public slots:
    void reset();
    void setError(double x, double y);
    void startControlLoop();

signals:
    void pidControlUpdate(double ux, double uy);

private:
    double errorX = 0;
    double errorY = 0;
    double previousErrorX = 0;
    double previousErrorY = 0;

    double integralX = 0;
    double integralY = 0;
    const double dt;

    double Kp = 0.1; // proportional gain
    double Ti = 0.1; // integration time => Ki = Kp/Ti (integral gain)
    double Td = 0.01; // derivative time => Kd = Kp*Td (derivative gain)

    const double allowedError;

    QTimer* timer = nullptr;
};

#endif // PID_H
