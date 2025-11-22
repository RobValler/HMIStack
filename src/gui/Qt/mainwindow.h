/*****************************************************************
 * Copyright (C) 2017 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <functional>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // ## PUBLIC ##
    void SetCallback(const std::function<void(std::string, std::string)>& CBFunc);
    void GuiUpdate(std::string gui_operator, std::string gui_operand);

signals:
    // ## SIGNALS ##
    void GuiUpdateSignal(std::string gui_operator, std::string gui_operand);
    void GuiCommandSignal(std::string gui_operator, std::string gui_operand);

private slots:
    // ## SLOTS ##
    void GuiUpdateSlot(std::string gui_operator, std::string gui_operand);
    void GuiCommandSlot(std::string gui_operator, std::string gui_operand);
    void on_testButton_clicked();
    void on_FileTransferpushButton_clicked();

private:
    Ui::MainWindow *ui;
    QMetaObject::Connection mGuiUpdateConnection;
    QMetaObject::Connection mGuiCommandConnection;
    std::function<void(std::string, std::string)> mCBFunc;
};
#endif // MAINWINDOW_H
