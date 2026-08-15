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

#include <QFileDialog>
#include <QWebChannel>

#include "hmibridge.h"

#include <string>
#include <iostream>


Q_DECLARE_METATYPE(std::string)

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qRegisterMetaType<std::string>("std::string");

    mGuiUpdateConnection = connect(this, SIGNAL(GuiUpdateSignal(std::string, std::string)),
                                this, SLOT(GuiUpdateSlot(std::string, std::string)),
                                Qt::QueuedConnection);

    mGuiCommandConnection = connect(this, SIGNAL(GuiCommandSignal(std::string, std::string)),
                                this, SLOT(GuiCommandSlot(std::string, std::string)),
                                Qt::QueuedConnection);



    HmiBridge *bridge = new HmiBridge(this);
    QWebChannel *channel = new QWebChannel(this);
    channel->registerObject("hmi", bridge);
    ui->webEngineView->page()->setWebChannel(channel);

}

MainWindow::~MainWindow()
{
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

// ## SLOTS ##
void MainWindow::GuiUpdateSlot(std::string gui_operator, std::string gui_operand) {

    ui->OperatorLabel->setText(QString::fromStdString(gui_operator));
    ui->OperandLabel->setText(QString::fromStdString(gui_operand));
}

void MainWindow::GuiCommandSlot(std::string gui_operator, std::string gui_operand) {

    mCBFunc(gui_operator, gui_operand);
}

void MainWindow::on_testButton_clicked()
{
    emit GuiCommandSignal("test_send", "moose");
}

void MainWindow::on_FileTransferpushButton_clicked()
{
    connect(ui->webEngineView, &QWebEngineView::loadFinished,
            this, [](bool ok) {
                qDebug() << "HTML load:" << ok;
    });

    QString filename = QFileDialog::getOpenFileName(
        this,
        tr("Open Document"),
        QDir::currentPath(),
        tr("All files (*.*);; Document files (*.txt *.rtf);; Executable files (*.exe)"));

    if (!filename.isEmpty()) {
        //emit GuiCommandSignal("file_transfer", filename.toStdString());
        std::cout << "Filename = " << filename.toStdString() << std::endl;

        ui->webEngineView->load(QUrl::fromLocalFile(filename));
    }
}
