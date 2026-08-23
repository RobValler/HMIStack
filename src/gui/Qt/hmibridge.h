
#ifndef HMI_BRIDGE__H
#define HMI_BRIDGE__H

#include "logger.h"

#include <QObject>
#include <QJsonObject>

struct SCBData {
    std::string opcode;
    std::string operand;
};

using cb_type = std::function<void(const SCBData&)>;

class CHmiBridge : public QObject
{
    Q_OBJECT

public:
    explicit CHmiBridge(cb_type cb, QObject *parent = nullptr)
        : QObject(parent)
        , mCB(cb)
    {}

public slots:
    void messageHMIToApp(const QJsonObject& data) {

        if(mCB) {
            SCBData payload;
            payload.opcode = data["text"].toString().toStdString();
            payload.operand = data["msg"].toString().toStdString();
            mCB(payload);
        }
    }

    std::string messageAppToHMI() {
        return "test moo moo";
    }

signals:
    void messageAppToHMI(const QJsonObject& data);

private:
    QObject* mParent;
    cb_type mCB;
};

#endif // HMI_BRIDGE__H
