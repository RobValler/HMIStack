

#pragma once


// Start of wxWidgets "Hello World" Program
#include <wx/wx.h>

class MyApp : public wxApp
{
public:
    bool OnInit() override;
};


class MyFrame : public wxFrame
{
public:
    MyFrame(wxWindow *parent);

private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};
