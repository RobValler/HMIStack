/*****************************************************************
 * Copyright (C) 2025 Robert Valler - All rights reserved.
 *
 * This file is part of the project: <insert project name here>
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#ifndef I_GUI_HNDL__H
#define I_GUI_HNDL__H

#include <string>

class IGuiHndl
{
public:
    virtual ~IGuiHndl(){}
    virtual void Start() =0;
    virtual void Stop() =0;
    virtual void Update(std::string, std::string) =0;
    virtual void SetCommand(const std::string&, const std::string&) =0;
    virtual void GetCommand(std::string&, std::string&) =0;
};

#endif // I_GUI_HNDL__H
