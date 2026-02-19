/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef MYFRAME__H
#define MYFRAME__H

#include "wxTestBase.h"
#include "base_types.h"

#include <wx/wx.h>

class MyFrame : public wxTestForm
{
public:
    MyFrame(const CBFunc& func);
    ~MyFrame();

private:
    void Btn1_Click( wxCommandEvent& event ) override;
    void Btn2_Click( wxCommandEvent& event ) override;
    void OnClose(wxCloseEvent& event);
    void OnItemActivated(wxDataViewEvent& event);

    wxBitmap load_file(std::string file_name, int w, int h);
    CBFunc mCBFunc;

    bool mSwitch{true};
};

#endif // MYFRAME__H
