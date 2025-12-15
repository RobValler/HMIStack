/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "state_hndl.h"

#include "base_types.h"
#include <chrono>


void CStateHndl::Start() {

    mtProcess = std::thread(&CStateHndl::ProcessThreadFunc, this);
}

void CStateHndl::Stop() {

    mExitCalled = true;
    mtProcess.join();
}

void CStateHndl::ProcessThreadFunc() {

    SBaseDataTypes localBaseTypesFromMsg;
    SBaseDataTypes localBaseTypesFromGUI;

    while(!mExitCalled) {



        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
