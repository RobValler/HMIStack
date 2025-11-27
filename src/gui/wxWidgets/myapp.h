

#pragma once

#include "base_types.h"

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
    MyFrame();

private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};

class CHandler
{
public:
    CHandler() =default;
    ~CHandler() =default;

    void Start(SCmdLineParm parm);
};
