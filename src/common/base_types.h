/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef PROJECTNAME_BASE_TYPES__H
#define PROJECTNAME_BASE_TYPES__H

#include <string>
#include <cstdint>
#include <vector>
#include <functional>

struct SBaseDataTypes {
    int ID;
    int ClientID;
    std::string name;
    std::vector<char> data;
};

enum class EHMI_FW: std::uint8_t {
    ENone,
    EQt,
    EImGui,
    EwxWidget,
    EDummy
};

struct SCmdLineParm {
    int m_argc;
    char **m_argv;
    EHMI_FW hmi_framework{EHMI_FW::ENone};
};

struct SCBFuncParms {
    std::string cb_operator{""};
    std::string cb_operand{""};
    // etc ...
};

//std::function<int(int, int)> func)
using CBFunc = std::function<void(SCBFuncParms)>;

#endif // PROJECTNAME_BASE_TYPES__H
