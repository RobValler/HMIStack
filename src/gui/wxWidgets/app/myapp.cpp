/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "myapp.h"
#include "myframe.h"

#include <iostream>

wxIMPLEMENT_APP_NO_MAIN(MyApp);

bool MyApp::OnInit() {

    std::cout << "OnInit called" << std::endl;
    mpFrame = new MyFrame(mCBFunc);

    mpFrame->Show(true);
    return true;
}

// int MyApp::OnExit() {

//     std::cout << "OnExit called" << std::endl;
//     // mpFrame->Show(false);
//     // mpFrame->Close();
//     return 0;
// }


