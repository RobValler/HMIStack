/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
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
#include "gui_hndl_wxWidgets.h"
#include "gui_hndl_dmy.h"
#include "gui_hndl_types.h"

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
        case EHMI_FW::EwxWidget: {
            SGuiHndlTypes local_gui_parms;
            local_gui_parms.cmd_line_parm = mParm;
            local_gui_parms.cb_func = [this](const SCBFuncParms& p){ this->StatusCallback(p); };
            mpPImpl->mpGuiHndl = std::make_shared<CGuiHndlWxWidgets>(local_gui_parms);
            break;
        }
        case EHMI_FW::EDummy:
            mpPImpl->mpGuiHndl = std::make_shared<CGuiHndlDmy>(mParm);
            break;
        default:
            break;
    } // switch

    SStateHndlParm LocalStateHndlParm;
    LocalStateHndlParm.mpGuiHndl = mpPImpl->mpGuiHndl;
    LocalStateHndlParm.mpOperationHndl = mpPImpl->mpOperationHndl;
    LocalStateHndlParm.mCBFunc = [this](const SCBFuncParms& p){ this->StatusCallback(p); };
    mpStateMachine = std::make_unique<CStateHndl>(LocalStateHndlParm);
}

CCore::~CCore()
{ /* nothing */ }

int CCore::Start() {

    std::cout << "Start " << std::endl;
    mpStateMachine->Start();
    mpPImpl->mpOperationHndl->Start();
    mpPImpl->mpGuiHndl->Start();
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

    if(true) {
        mCurrentCoreStatus = ECoreStatus::EShutdown;
    }

    return 0;
}

void CCore::StatusCallback(const SCBFuncParms& data) {

    std::cout << "StatusCallback(...) called!\n"
              << "operator = " << data.cb_operator << "\n"
              << "operand = " << data.cb_operand << std::endl;

    if(data.cb_operator == "status") {

        if(data.cb_operand == "stop") {
            // set the shutdown request flag
            mCurrentCoreStatus = ECoreStatus::EShutdownRequest;
        }
    }
}
