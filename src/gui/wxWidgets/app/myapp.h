/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef MYAPP__H
#define MYAPP__H

#include "base_types.h"

#include <wx/wx.h>

#include <memory>


class MyFrame;

class MyApp : public wxApp
{
public:
    bool OnInit() override;
    //int OnExit() override;
    void AddCallBack(const CBFunc& func) {
        mCBFunc = func;
    }
private:
    CBFunc mCBFunc;
    MyFrame* mpFrame = nullptr;

};

#endif // MYAPP__H
