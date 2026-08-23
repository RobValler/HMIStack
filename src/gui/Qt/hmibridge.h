
#ifndef HMI_BRIDGE__H
#define HMI_BRIDGE__H

#include <QObject>
//#include <QDebug>
#include <QJsonValue>
#include <QJsonObject>

#include <iostream>

class CHmiBridge : public QObject
{
    Q_OBJECT

public:
    explicit CHmiBridge(QObject *parent = nullptr)
        : QObject(parent)
    {}

public slots:
    void messageHMIToApp(const QJsonObject& data) {

        std::string foo = data["text"].toString().toStdString();
        std::string moo = data["msg"].toString().toStdString();
        std::cout << "CPP based function says = " << foo << ", " << moo << std::endl;
    }

    std::string messageAppToHMI() {
        return "test moo moo";
    }

signals:
    void CB(double value);
};

#endif // HMI_BRIDGE__H
