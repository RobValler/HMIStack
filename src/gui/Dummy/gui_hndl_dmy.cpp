/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "gui_hndl_dmy.h"

#include "logger.h"

void CGuiHndlDmy::Start() {
    CLogger::Log("GUI Dummy Start!");
}

void CGuiHndlDmy::Stop() {
    CLogger::Log("GUI Dummy Stop!");
}

void CGuiHndlDmy::Update(std::string gui_operator, std::string gui_operand) {
    CLogger::Log("GUI Dummy Update: operator = " + gui_operator
                 + ", operand = " + gui_operand);
}

void CGuiHndlDmy::SetCommand(const std::string& gui_operator, const std::string& gui_operand) {
    std::cout << "GUI Dummy SetCommand: operator = " << gui_operator
              << ", operand = " << gui_operand
              << std::endl;
}

void CGuiHndlDmy::GetCommand(std::string& gui_operator, std::string& gui_operand) {
    std::cout << "GUI Dummy GetCommand: operator = " << gui_operator
              << ", operand = " << gui_operand
              << std::endl;
}
