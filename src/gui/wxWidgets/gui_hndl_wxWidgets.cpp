/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "gui_hndl_wxWidgets.h"

// #include "base_types.h"
#include "handler.h"

#include <iostream>

CGuiHndlWxWidgets::CGuiHndlWxWidgets(const SGuiHndlTypes& parm)
    : mParm(parm)
    , mpHandler(std::make_shared<CHandler>(mParm))
{   }

CGuiHndlWxWidgets::~CGuiHndlWxWidgets()
{   }

void CGuiHndlWxWidgets::Start() {

    mtGuiHandler = std::thread(&CGuiHndlWxWidgets::ThreadFuncServer, this);
}

void CGuiHndlWxWidgets::Stop() {

    mpHandler->Stop();
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

    std::cout << "Starting wxWidget example" << std::endl;
    std::cout << "Now you see me ..." << std::endl;
    mpHandler->Start(); // should be blocking
    std::cout << "... now you don't!!" << std::endl;

}
