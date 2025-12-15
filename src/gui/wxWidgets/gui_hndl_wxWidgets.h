/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef GUI_HNDL_WXWIDGETS__H
#define GUI_HNDL_WXWIDGETS__H

#include "gui_hndl_types.h"

#include "i_gui_hndl.h"

#include <string>
#include <thread>
#include <atomic>
#include <mutex>
#include <memory>

class CHandler;

class CGuiHndlWxWidgets : public IGuiHndl
{
public:
    CGuiHndlWxWidgets(const SGuiHndlTypes& parm);
    ~CGuiHndlWxWidgets();
    void Start() override;
    void Stop() override;
    void Update(std::string gui_operator, std::string gui_operand) override;
    void SetCommand(const std::string& gui_operator, const std::string& gui_operand) override;
    void GetCommand(std::string& gui_operator, std::string& gui_operand) override;

private:
    void ThreadFuncServer();
    SGuiHndlTypes mParm;
    std::atomic<bool> mIsExistRequest{false};
    std::thread mtGuiHandler;

    std::shared_ptr<CHandler> mpHandler;

    std::string mCommandGUIoperator;
    std::string mCommandGUIoperand;
    std::mutex mCommandAccessMutex;

    std::atomic<bool> mCommandChange{false};
};


#endif // GUI_HNDL_WXWIDGETS__H
