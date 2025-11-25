/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "gui_hndl_dmy.h"

#include <iostream>

void CGuiHndlDmy::Start() {
    std::cout << "GUI Dummy Start!" << std::endl;
}

void CGuiHndlDmy::Stop() {
    std::cout << "GUI Dummy Stop!" << std::endl;
}

void CGuiHndlDmy::Update(std::string gui_operator, std::string gui_operand) {
    std::cout << "GUI Dummy Update: operator = " << gui_operator
              << ", operand = " << gui_operand
              << std::endl;
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
