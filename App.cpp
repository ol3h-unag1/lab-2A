#pragma once

#include "App.hpp"
#include "Dictionary.hpp"



void App::Start()
{
    if( Init() )
    {
        ShowFirstMenu();
    }
    else
    {
        Finish();
    }
}

void App::Finish()
{
}

bool App::Init()
{
    return false;
}

void App::ShowFirstMenu()
{
}
