

#include "custom.h"

MyText::MyText(wxWindow* parent, std::string label, int x, int y)
    : wxStaticText(parent, wxID_ANY, label, wxPoint(x, y))
    , mLabel(label)
{
    this->SetForegroundColour(*wxWHITE);
    auto font = this->GetFont();
    font.SetPointSize(24);
    this->SetFont(font);
    this->SetSize(x, y);
    Bind(wxEVT_PAINT, &MyText::OnPaint, this);
}

void MyText::OnPaint(wxPaintEvent&) {
    wxPaintDC dc(this);
    dc.DrawText(mLabel, 10, 10);
}
