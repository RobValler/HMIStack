/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "gui_hndl_Qt.h"

#include "mainwindow.h"

#include <QApplication>


void CGuiHndlQt::Start() {

    mtGuiHandler = std::thread(&CGuiHndlQt::ThreadFuncServer, this);
}

void CGuiHndlQt::Stop() {

    mtGuiHandler.join();
}

void CGuiHndlQt::Update(std::string gui_operator, std::string gui_operand) {
    
    mpUI->GuiUpdate(gui_operator, gui_operand);
}

void CGuiHndlQt::SetCommand(const std::string& gui_operator, const std::string& gui_operand) {

    const std::lock_guard<std::mutex> lock(mCommandAccessMutex);
    mCommandGUIoperator = gui_operator;
    mCommandGUIoperand = gui_operand;
    mCommandChange = true;
}

void CGuiHndlQt::GetCommand(std::string& gui_operator, std::string& gui_operand) {

    const std::lock_guard<std::mutex> lock(mCommandAccessMutex);
    if(mCommandChange) {
        gui_operator = mCommandGUIoperator;
        gui_operand = mCommandGUIoperand;
        mCommandChange = false;
    }
}

void CGuiHndlQt::ThreadFuncServer() {

    mpQApp = std::make_shared<QApplication>(mParm.m_argc, mParm.m_argv);
    mpUI = std::make_shared<MainWindow>();
    mpUI->SetCallback([this](std::string gui_operator, std::string gui_operand) { this->SetCommand(gui_operator, gui_operand); });
    mpUI->show();
    mpQApp->exec();

    // send the program stop command
    SetCommand("program_status", "stop");
}
