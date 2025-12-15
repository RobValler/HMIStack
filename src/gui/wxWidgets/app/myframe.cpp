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
    , mCBFunc(func) {


    Bind(wxEVT_CLOSE_WINDOW, &MyFrame::OnClose, this);

    std::cout << "----> MyFrame ctor called" << std::endl;
}

MyFrame::~MyFrame() {

    std::cout << "----> MyFrame dtor called" << std::endl;
}

void MyFrame::OnClose(wxCloseEvent& event) {

    event.Veto();   // block close
    Unbind(wxEVT_CLOSE_WINDOW, &MyFrame::OnClose, this);

    SCBFuncParms p;
    p.cb_operator = "status";
    p.cb_operand = "stop";
    mCBFunc(p);
}

