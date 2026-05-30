/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "operation_hndl.h"

#include "sig_slot.h"
#include "logger.h"

#include <string>

struct STest {
    int ID{0};
    std::string message{""};
};

void COperationHndl::Start() {

    STest data;

    auto test_slot = [](const STest& data) {

        CLogger::Log("---> Signal func called : " + data.message);
    };

    CSIGSLOT<STest>::GetInstance().CONNECT(1, test_slot);
}

void COperationHndl::Stop() {

}
