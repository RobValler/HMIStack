/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef GUI_HNDL_DMY__H
#define GUI_HNDL_DMY__H

#include "base_types.h"

#include "i_gui_hndl.h"

#include <string>
#include <atomic>
#include <mutex>

class QApplication;
class MainWindow;

class CGuiHndlDmy : public IGuiHndl
{
public:
    CGuiHndlDmy(const SCmdLineParm& parm) : mParm(parm){};
    ~CGuiHndlDmy() override =default;
    void Start() override;
    void Stop() override;
    void Update(std::string gui_operator, std::string gui_operand) override;
    void SetCommand(const std::string& gui_operator, const std::string& gui_operand) override;
    void GetCommand(std::string& gui_operator, std::string& gui_operand) override;

private:
    SCmdLineParm mParm;

    std::string mCommandGUIoperator;
    std::string mCommandGUIoperand;
    std::mutex mCommandAccessMutex;
    std::atomic<bool> mCommandChange{false};
};

#endif // GUI_HNDL_DMY__H
