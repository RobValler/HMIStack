
#include "myapp.h"

wxIMPLEMENT_APP_NO_MAIN(MyApp);



enum
{
    ID_Hello = 1
};

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame();
    frame->Show(true);
    return true;
}

MyFrame::MyFrame()
    : wxTestForm(nullptr, wxID_ANY, "Hello World")
{

}

void CHandler::Start(SCmdLineParm parm) {
    wxEntry(parm.m_argc, parm.m_argv);
}
