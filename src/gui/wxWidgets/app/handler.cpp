/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "handler.h"

#include "myapp.h"


CHandler::CHandler(const SGuiHndlTypes& parms)
    : mParm(parms)
    , mpMyApp(std::make_shared<MyApp>())
{}

void CHandler::Start() {

    if(!mpMyApp) {
        return;
    }
    mpMyApp->AddCallBack(mParm.cb_func);

    if (!wxEntryStart(mParm.cmd_line_parm.m_argc, mParm.cmd_line_parm.m_argv)) {
        return;
    }

    wxApp::SetInstance(mpMyApp.get());
    wxTheApp->CallOnInit();
    wxTheApp->OnRun();
    wxTheApp->OnExit();

    wxEntryCleanup();

    SCBFuncParms p;
    p.cb_operator = "program_status";
    p.cb_operand = "stop";
    mParm.cb_func(p);

}

void CHandler::Stop() {
    wxTheApp->ExitMainLoop();
}
