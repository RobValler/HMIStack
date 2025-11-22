/*****************************************************************
 * Copyright (C) 2017 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "core.h"

#include "operation_hndl.h"
#include "operation_hndl_types.h"
#include "state_hndl.h"
#include "state_hndl_types.h"

#include "gui_hndl_Qt.h"
#include "gui_hndl_dearImGui.h"
#include "gui_hndl_dmy.h"

#include <iostream>


struct SPImpl {

    std::shared_ptr<IGuiHndl> mpGuiHndl;
    std::shared_ptr<COperationHndl> mpOperationHndl;
};

CCore::CCore(const SCmdLineParm& parm)
    : mParm(parm)
    , mpPImpl(std::make_unique<SPImpl>())
{

    // HMI / GUI
    switch(mParm.hmi_framework) {
        case EHMI_FW::ENone:
            break;
        break;
        case EHMI_FW::EQt:
            mpPImpl->mpGuiHndl = std::make_shared<CGuiHndlQt>(mParm);
            break;
        case EHMI_FW::EImGui:
            mpPImpl->mpGuiHndl = std::make_shared<CGuiHndlDearImGui>(mParm);
            break;
        case EHMI_FW::EwxWidget:
            mpPImpl->mpGuiHndl = std::make_shared<CGuiHndlDmy>(mParm);
            break;
        case EHMI_FW::EDummy:
            mpPImpl->mpGuiHndl = std::make_shared<CGuiHndlDmy>(mParm);
            break;
        default:
            break;
    } // switch

    SStateHndlParm LocalStateHndlParm;
    LocalStateHndlParm.mpGuiHndl = mpPImpl->mpGuiHndl;
    LocalStateHndlParm.mpOperationHndl = mpPImpl->mpOperationHndl;
    LocalStateHndlParm.mCBFunc = [this](std::string gui_operator,
                                        std::string gui_operand)
                                        { this->StatusCallback(gui_operator, gui_operand); };

    mpStateMachine = std::make_unique<CStateHndl>(LocalStateHndlParm);
}

CCore::~CCore()
{ /* nothing */ }

int CCore::Start() {

    std::cout << "Start " << std::endl;
    mpPImpl->mpGuiHndl->Start();
    mpPImpl->mpOperationHndl->Start();
    mpStateMachine->Start();
    return 0;
}

ECoreStatus CCore::Status() {

    return mCurrentCoreStatus;
}

int CCore::Stop() {

    std::cout << "Stop" << std::endl;
    mpPImpl->mpGuiHndl->Stop();
    mpPImpl->mpOperationHndl->Stop();
    mpStateMachine->Stop();
    return 0;
}

void CCore::StatusCallback(const std::string& gui_operator, const std::string& gui_operand) {

    if(gui_operator == "program_status") {

        if(gui_operand == "stop") {
            // shutdown request received
            Stop();
        }
    }
}
