/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "hmibridge.h"

#include <QFileDialog>
#include <QWebChannel>

#include <string>

Q_DECLARE_METATYPE(std::string)

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qRegisterMetaType<std::string>("std::string");

    mGuiUpdateConnection = connect( this, SIGNAL(GuiUpdateSignal(std::string, std::string)),
                                    this, SLOT(GuiUpdateSlot(std::string, std::string)),
                                    Qt::QueuedConnection);

    mGuiCommandConnection =connect( this, SIGNAL(GuiCommandSignal(std::string, std::string)),
                                    this, SLOT(GuiCommandSlot(std::string, std::string)),
                                    Qt::QueuedConnection);

    QWebChannel *local_channel = new QWebChannel(this);
    mHmiBridge = std::make_unique<CHmiBridge>(([this](const SCBData& data) { this->HtmlCBFunc(data); }), this);
    local_channel->registerObject("hmi2app", mHmiBridge.get());
    local_channel->registerObject("app2hmi", mHmiBridge.get());
    ui->webEngineView->page()->setWebChannel(local_channel);

    // temporary
    std::string filename = "/home/rob/WORK/C_CPP/HMIStack/src/gui/Html/index.html";
    ui->webEngineView->load(QUrl::fromLocalFile(filename.c_str()));
    ui->HTMLAddressData->setText(filename.c_str());
}

MainWindow::~MainWindow() {

    disconnect(mGuiUpdateConnection);
    disconnect(mGuiCommandConnection);
    delete ui;
}

// ## PUBLIC ##
void MainWindow::SetCallback(const std::function<void(std::string, std::string)>& CBFunc) {

    mCBFunc = CBFunc;
}

void MainWindow::GuiUpdate(std::string gui_operator, std::string gui_operand) {

    emit GuiUpdateSignal(gui_operator,gui_operand);
}

void MainWindow::HtmlCBFunc(const SCBData& data) {

    ui->OperatorData->setText(QString::fromStdString(data.opcode));
    ui->OperandData->setText(QString::fromStdString(data.operand));
}

// ## SLOTS ##
void MainWindow::GuiUpdateSlot(std::string gui_operator, std::string gui_operand) {

    ui->OperatorData->setText(QString::fromStdString(gui_operator));
    ui->OperandData->setText(QString::fromStdString(gui_operand));
}

void MainWindow::GuiCommandSlot(std::string gui_operator, std::string gui_operand) {

    mCBFunc(gui_operator, gui_operand);
}

void MainWindow::on_LoadWebsiteButton_clicked() {

    connect(ui->webEngineView,
            &QWebEngineView::loadFinished,
            this, [](bool ok){
        qDebug() << "HTML load:" << ok;
    });

    QString filename = QFileDialog::getOpenFileName(
        this,
        tr("Open web page"),
        QDir::currentPath(),
        //"",
        //tr("All files (*.*);; Document files (*.txt *.rtf);; Executable files (*.exe)")
        tr("All files (*.*);; Html files (*.html)")
        //tr("Html file (*.html)")
    );

    if (!filename.isEmpty()) {
        //emit GuiCommandSignal("file_transfer", filename.toStdString());
        //std::cout << "Filename = " << filename.toStdString() << std::endl;
        ui->webEngineView->load(QUrl::fromLocalFile(filename));
        ui->HTMLAddressData->setText(filename);
    }
}

void MainWindow::on_MessageToHtml_clicked() {

    QJsonObject payload;
    std::string local_text = "Hello from Qt! " + std::to_string(mMsgIndex++);
    payload["text"] = local_text.c_str();
    payload["msg"] = "fluffy ";
    emit mHmiBridge->messageAppToHMI(payload);
}
