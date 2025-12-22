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

    std::cout << "----> MyFrame ctor called" << std::endl;

    // configuration
    Bind(wxEVT_CLOSE_WINDOW, &MyFrame::OnClose, this);



    // Set-ups
    int width = 24;
    int height = 24;

    wxImage img;
    img.LoadFile("notepad_icon.png", wxBITMAP_TYPE_PNG);
    wxBitmap bmp1(img.Scale(width, height, wxIMAGE_QUALITY_HIGH));
    img.LoadFile("web_icon.png", wxBITMAP_TYPE_PNG);
    wxBitmap bmp2(img.Scale(width, height, wxIMAGE_QUALITY_HIGH));
    wxImageList* imageList = new wxImageList(width, height, true);
    int icon1 = imageList->Add(bmp1);
    int icon2 = imageList->Add(bmp2);

    // Assign image list to notebook
    m_notebook_main->AssignImageList(imageList);
    m_notebook_main->SetPageImage(0, icon1);
    m_notebook_main->SetPageImage(1, icon2);



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

