/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef STATE_HNDL__H
#define STATE_HNDL__H

#include "state_hndl_types.h"

#include <thread>
#include <atomic>
#include <functional>


// forwarding
class SMsgHndlParm;

class CStateHndl
{
public:
    CStateHndl(const SStateHndlParm& parm)
        : mParm(parm)
    {/**/}
    ~CStateHndl() =default;
    void Start();
    void Stop();

private:
    SStateHndlParm mParm;
    std::atomic<bool> mExitCalled{false};
    std::thread mtProcess;
    void ProcessThreadFunc();

};

#endif // STATE_HNDL__H
