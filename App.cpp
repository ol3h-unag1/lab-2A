#pragma once

#include <string>
#include <chrono>
#include <thread>

#include "ErrorMsg.hpp"

#include "App.hpp"
#include "Dictionary.hpp"

void App::Start()
{
    if( Init() )
    {
        _notificationMenu->Show();
    }
    else
    {
        PRNT_ERR( "Initialization failed" ) ;
    }
}

bool App::Init()
{
    static bool inited = false;
    if( inited )
    {
        return true;
    }
    
    _mainMenu = std::make_shared< Menu >( "Make you choice:\n\t1. Exercise\n\t2. Add word( s )\n\t3. Settings" );   

    _notificationMenu = std::make_shared< Menu >( "Welcome to LEngX - app for memorizing English words!" );
    auto notificationMenuOnEnterHandler = [ this ]() 
    {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for( 2s );
        _mainMenu->Show();
    };
    _notificationMenu->SetOnEnterHandler( notificationMenuOnEnterHandler );


    _trainingMenu = std::make_shared< Menu >( "Try to remember translation. Enter a number between 0 and 10 indicating how hard ( or easy ) it was to remember it.\n0 - very easy, 10 - can't remember." );

    inited = _mainMenu && _notificationMenu && _trainingMenu && _dict->Init();

    return inited;
}