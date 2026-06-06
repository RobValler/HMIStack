/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "operation_hndl.h"

#include "event_id.h"

#include "sig_slot.h"
#include "logger.h"


void COperationHndl::Start() {

    auto test_slot = [](const SSlotData& data) {

        CLogger::Log("---> Button Pressed : " + data.string_data);
    };

    CSigSlot::Connect(static_cast<std::uint16_t>(EEventID::EBtnPress), test_slot);
}

void COperationHndl::Stop() {

}
