/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "core.h"

#include <csignal>
#include <thread>
#include <chrono>
#include <atomic>
#include <iostream>

namespace
{
    std::atomic<bool> gExitRequest{false};
}
 
void signal_handler(int signal)
{
    std::cout << "Terminate signal (" << std::to_string(signal) << ") recieved!" << std::endl;
    gExitRequest = true;
}

int main(int argc, char *argv[])
{
    // POSIIX signal handling
    std::signal(SIGINT, signal_handler);   // CTRL+C

    SCmdLineParm parm;
    parm.m_argc = argc;
    parm.m_argv = argv;
    parm.hmi_framework = EHMI_FW::EwxWidget;

    CCore test(parm);
    test.Start();
    while(!gExitRequest) {

        if(ECoreStatus::EShutdown == test.Status()) {
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    test.Stop();
}
