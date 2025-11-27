/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "gui_hndl_wxWidgets.h"

#include "myapp.h"

#include <chrono>

void CGuiHndlWxWidgets::Start() {

    mtGuiHandler = std::thread(&CGuiHndlWxWidgets::ThreadFuncServer, this);
}

void CGuiHndlWxWidgets::Stop() {

    mtGuiHandler.join();
}

void CGuiHndlWxWidgets::Update(std::string gui_operator, std::string gui_operand) {
    

}

void CGuiHndlWxWidgets::SetCommand(const std::string& gui_operator, const std::string& gui_operand) {

    const std::lock_guard<std::mutex> lock(mCommandAccessMutex);
    mCommandGUIoperator = gui_operator;
    mCommandGUIoperand = gui_operand;
    mCommandChange = true;
}

void CGuiHndlWxWidgets::GetCommand(std::string& gui_operator, std::string& gui_operand) {

    const std::lock_guard<std::mutex> lock(mCommandAccessMutex);
    if(mCommandChange) {
        gui_operator = mCommandGUIoperator;
        gui_operand = mCommandGUIoperand;
        mCommandChange = false;
    }
}

void CGuiHndlWxWidgets::ThreadFuncServer() {

    MyApp app;

    app.OnInit();

    while(!mIsExistRequest) {



        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

}
