

#ifndef MYAPP__H
#define MYAPP__H

// #include "gui_hndl_types.h"
#include "base_types.h"
//#include "wxTestBase.h"

#include <wx/wx.h>

#include <memory>

class MyFrame;

class MyApp : public wxApp
{
public:
    bool OnInit() override;
    int OnExit() override;
    void AddCallBack(const CBFunc& func) {
        mCBFunc = func;
    }
private:
    CBFunc mCBFunc;
    std::shared_ptr<MyFrame> mpFrame;

};

#endif // MYAPP__H
