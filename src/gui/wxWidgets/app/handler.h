/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef HANDLER__H
#define HANDLER__H

#include "gui_hndl_types.h"

#include <memory>

class MyApp;

class CHandler
{
public:
    CHandler(const SGuiHndlTypes& parms);
    ~CHandler() =default;

    void Start();
    void Stop();

private:
    SGuiHndlTypes mParm;
    std::shared_ptr<MyApp> mpMyApp;
};

#endif // HANDLER__H

