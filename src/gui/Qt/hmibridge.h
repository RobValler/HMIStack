
#ifndef HMI_BRIDGE__H
#define HMI_BRIDGE__H

#include <QObject>
#include <QDebug>

class HmiBridge : public QObject
{
    Q_OBJECT

public:
    explicit HmiBridge(QObject *parent = nullptr)
        : QObject(parent)
    {}

public slots:
    void setLed(bool on)
    {
        qDebug() << "CPP based function says = LED:" << on;

        // Do something in your C++ application
    }

signals:
    void temperatureChanged(double temperature);
};

#endif // HMI_BRIDGE__H
