/*****************************************************************
 * Copyright (C) 2017 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef OPERATION_HNDL_TYPES__H
#define OPERATION_HNDL_TYPES__H

#include <memory>

class CMsgHndl;
class CNetworkHndl;
class CAgentHndl;
class IGuiHndl;
class COperationHndl;

struct SOperationHndlParm {
    std::shared_ptr<CMsgHndl> mpMsgHndl;
    std::shared_ptr<CNetworkHndl> mpNetWorkHndl;
    std::shared_ptr<CAgentHndl> mpAgentHndl;
    std::shared_ptr<IGuiHndl> mpGuiHndl;
    std::shared_ptr<COperationHndl> mpOperationHndl;
};

#endif // OPERATION_HNDL_TYPES__H
