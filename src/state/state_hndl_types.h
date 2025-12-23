/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef STATE_HNDL_TYPES__H
#define STATE_HNDL_TYPES__H

#include "base_types.h"

#include <memory>

class CMsgHndl;
class CAgentHndl;
class IGuiHndl;
class COperationHndl;

struct SStateHndlParm {
    std::shared_ptr<CMsgHndl> mpMsgHndl;
    std::shared_ptr<CAgentHndl> mpAgentHndl;
    std::shared_ptr<IGuiHndl> mpGuiHndl;
    std::shared_ptr<COperationHndl> mpOperationHndl;
    CBFunc mCBFunc;
};

#endif // STATE_HNDL_TYPES__H
