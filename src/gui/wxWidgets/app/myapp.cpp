
#include "myapp.h"
#include "myframe.h"

wxIMPLEMENT_APP_NO_MAIN(MyApp);

bool MyApp::OnInit() {
    mpFrame = std::make_shared<MyFrame>(mCBFunc);
    mpFrame->Show(true);
    return true;
}

int MyApp::OnExit() {

    mpFrame->Show(false);
    return 0;
}
