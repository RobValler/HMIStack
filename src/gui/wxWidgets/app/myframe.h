

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
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    CBFunc mCBFunc;
};

#endif // MYFRAME__H
