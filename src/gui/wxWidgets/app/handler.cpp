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

#include <iostream>

CHandler::CHandler(const SGuiHndlTypes& parms)
    : mParm(parms)
{}

void CHandler::Start() {

    mpMyApp = new MyApp();

    if(!mpMyApp) {
        return;
    }
    mpMyApp->AddCallBack(mParm.cb_func);

    if (!wxEntryStart(mParm.cmd_line_parm.m_argc, mParm.cmd_line_parm.m_argv)) {
        return;
    }

    wxApp::SetInstance(mpMyApp);
    wxTheApp->CallOnInit();
    wxTheApp->OnRun();
    wxTheApp->OnExit();

    wxEntryCleanup();

}

void CHandler::Stop() {

    std::cout << "ExitMainLoop" << std::endl;
    wxTheApp->ExitMainLoop();
}
