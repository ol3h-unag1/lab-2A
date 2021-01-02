#pragma once

#include <string>

#include "ErrorMsg.hpp"

#include "App.hpp"
#include "Dictionary.hpp"

void App::Start()
{
    if( Init() )
    {
        ShowMainMenu();
    }
    else
    {
        Error( ERR_MSG( "Initialization failed" ) );
        Finish();  
    }
}

void App::Finish()
{
}

bool App::Init()
{
    static bool inited = false;
    if( !inited )
    {
        bool inited = _dict->Init();
    }

    return inited;
}

void App::ShowMainMenu()
{
    _mainMenu->Show();
}
