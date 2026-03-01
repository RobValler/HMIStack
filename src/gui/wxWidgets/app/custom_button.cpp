/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "custom_button.h"

namespace {
    const wxColour gBtnBackGrnColourInactive = {0xFF, 0xFF, 0xFF};
    const wxColour gBtnBackGrnColourActive = {0x00, 0xCE, 0xFF};
    const wxColour gBtnBorderColourActive = {0x00, 0xFF, 0x00};
    const wxColour gBtnBorderColourInactive = {0xFF, 0xFF, 0xFF};
}

CCustomBtn::CCustomBtn(wxWindow* parent, wxSize size, wxPoint pos, std::string label)
    : wxPanel(parent)
    , mLabel(label)
{
    SetSize(pos.x, pos.y, size.x, size.y);
    SetBackgroundColour(*gBtnBorderColourInactive);
    wxRect rect = GetClientRect();
    rect.Deflate(5);

    mBtn = new wxButton(this,
            wxID_ANY,
            mLabel,
            rect.GetPosition(),
            rect.GetSize(),
            wxBORDER);

    mBtn->SetBackgroundColour(*gBtnBackGrnColourInactive);
    mBtn->Bind(wxEVT_PAINT, &CCustomBtn::OnPaint, this);
    mBtn->Bind(wxEVT_LEFT_DOWN, &CCustomBtn::OnMouseClick, this);
    mBtn->Bind(wxEVT_RIGHT_DOWN, &CCustomBtn::OnMouseClick, this);

}

CCustomBtn::~CCustomBtn() {

    delete mBtn;
}

void CCustomBtn::OnPaint(wxPaintEvent& event) {

    // wxPaintDC dc(this);

    // wxRect rect = GetClientRect();

    // // Background
    // dc.SetBrush(wxBrush(GetBackgroundColour()));
    // dc.SetPen(*wxTRANSPARENT_PEN);
    // dc.DrawRectangle(rect);

    // // Draw label centered
    // dc.DrawText(GetLabel(),
    //             (rect.width - dc.GetTextExtent(GetLabel()).GetWidth()) / 2,
    //             (rect.height - dc.GetTextExtent(GetLabel()).GetHeight()) / 2);

    // // Draw green border if selected
    // if (GetValue())
    // {
    //     dc.SetBrush(*wxTRANSPARENT_BRUSH);
    //     dc.SetPen(wxPen(*wxGREEN, 3));
    //     dc.DrawRectangle(rect.Deflate(1));
    // }

    //event.Skip(true);
}

void CCustomBtn::SetLabel(std::string label) {

    mLabel = label;
}

void CCustomBtn::OnMouseClick(wxMouseEvent& event) {

    if(event.LeftDown()) {
        if(GetFocus()) {
            mBtn->SetBackgroundColour(*gBtnBackGrnColourInactive);
            SetFocus(false);
        } else {
            mBtn->SetBackgroundColour(*gBtnBackGrnColourActive);
            SetFocus(true);
        }
    }

    if(event.RightDown()) {
        if(GetSelect()) {
            SetSelect(false);
            SetBackgroundColour(*gBtnBorderColourInactive);
        } else {
            SetSelect(true);
            SetBackgroundColour(*gBtnBorderColourActive);
        }
    }
    event.Skip();
}

