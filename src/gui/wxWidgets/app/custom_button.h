/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef CUSTOM_BUTTON__H
#define CUSTOM_BUTTON__H

#include <wx/wx.h>

#include <string>
#include <atomic>

class CCustomBtn : public wxPanel
{
public:
    CCustomBtn(wxWindow* parent, wxSize size, wxPoint pos, std::string label ="" );
    CCustomBtn() =delete;
    ~CCustomBtn();

    void SetButtonLabel(std::string label);
    bool GetSelect() { return mIsSelected; };
    bool GetFocus() { return mHasFocus; };

private:
    // Callbacks
    void OnPaint(wxPaintEvent& event);
    void OnMouseClick(wxMouseEvent& event);
    void SetSelect(bool select) { mIsSelected = select; };
    void SetFocus(bool focus) { mHasFocus = focus; };

    // variables
    std::atomic<bool> mIsSelected{false};
    std::atomic<bool> mHasFocus{false};
    wxButton* mBtn;
    wxStaticText* mBtnText;

    std::string mLabel{""};
};

#endif // CUSTOM_BUTTON__H
