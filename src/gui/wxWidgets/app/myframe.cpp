/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "myframe.h"

#include <iostream>

MyFrame::MyFrame(const CBFunc& func)
    : wxTestForm(nullptr, wxID_ANY, "Hello World")
    , mCBFunc(func)
{
    // wxPanel* panel = new wxPanel(this);

    // wxBoxSizer* sizer = new wxBoxSizer(wxBOTH);
    // sizer->Add(m_notebook1, 1, wxEXPAND | wxALL, 5);

    // panel->SetSizer(sizer);



    std::cout << "----> MyFrame ctor called" << std::endl;
}

MyFrame::~MyFrame() {

    std::cout << "----> MyFrame dtor called" << std::endl;
}
