/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef GUI_HNDL_QT__H
#define GUI_HNDL_QT__H

#include "base_types.h"

#include "i_gui_hndl.h"

#include <string>
#include <thread>
#include <atomic>
#include <memory>
#include <mutex>

class QApplication;
class MainWindow;

class CGuiHndlQt : public IGuiHndl
{
public:
    CGuiHndlQt(const SCmdLineParm& parm) : mParm(parm){};
    ~CGuiHndlQt() override =default;
    void Start() override;
    void Stop() override;
    void Update(std::string gui_operator, std::string gui_operand) override;
    void SetCommand(const std::string& gui_operator, const std::string& gui_operand) override;
    void GetCommand(std::string& gui_operator, std::string& gui_operand) override;

private:
    SCmdLineParm mParm;
    std::shared_ptr<QApplication> mpQApp;
    std::shared_ptr<MainWindow> mpUI;
    std::atomic<bool> mIsExistRequest{false};
    std::thread mtGuiHandler;
    void ThreadFuncServer();

    std::string mCommandGUIoperator;
    std::string mCommandGUIoperand;
    std::mutex mCommandAccessMutex;

    std::atomic<bool> mCommandChange{false};
};

#endif // GUI_HNDL_QT__H
