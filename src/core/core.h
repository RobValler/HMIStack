/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef CORE__H
#define CORE__H

#include "base_types.h"

#include <memory>

// forward declaration
struct SPImpl;
class CoreParms;
class CStateHndl;

enum class ECoreStatus : unsigned int {
    ENone =0,
    EActive,
    EShutdown,
    EShutdownRequest,
    EUnknown
};

class CCore {
public:
    CCore(const CoreParms& parm);
    ~CCore();

    int Start();
    ECoreStatus Status();
    int Stop();

private:

    void StatusCallback(const SCBFuncParms& data);
    ECoreStatus mCurrentCoreStatus{ECoreStatus::EUnknown};
    CoreParms mParm;
    std::unique_ptr<SPImpl> mpPImpl;
    std::unique_ptr<CStateHndl> mpStateMachine;
};

#endif // CORE__H
