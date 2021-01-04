#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <limits>

#include "ErrorMsg.hpp"

#include "App.hpp"
#include "Dictionary.hpp"

enum class MAIN_MENU_CHOICES : std::size_t
{
    EXE = 1,
    SETT = 2,
    ADDW = 3
};

enum class SETTINGS_MENU_CHOICES : std::size_t
{
    EXE_SIZE = 1,
    MAIN = 2
};

enum class ADDW_MENU_CHOICES : std::size_t
{
    MAN = 1,
    FILE = 2,
    MAIN = 3
};

void ClearStdCin()
{
    std::cin.ignore( std::numeric_limits< std::streamsize >::max() );
    std::cin.clear();
}

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

    _notificationMenu = std::make_shared< Menu >( "Welcome to LEngX - app for memorizing English words!" ); // description used on app start
    auto notificationMenuOnEnterHandler = [this]()
    {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for( 2s );
        _pendingMenu->Show();
    };
    _notificationMenu->SetOnEnterHandler( notificationMenuOnEnterHandler );

    _mainMenu = std::make_shared< Menu >( "Make you choice:\n\t1. Exercise\n\t2. Add word( s )\n\t3. Settings" );
    _pendingMenu = _mainMenu;
    auto mainMenuInputHandler = [this]() 
    {
        std::size_t choice = 0;
        std::string str;
        std::cin >> str;
        try 
        {
            choice = std::stoul( str );
        }
        catch( ... )
        {

        }
        ClearStdCin();
        
        if( choice == 0 )
        {
            _pendingMenu = _mainMenu;
            _notificationMenu->SetDescription( "Enter number between 1 and 3!" );
            _notificationMenu->Show();
            return;
        }

        if( static_cast< MAIN_MENU_CHOICES >( choice ) == MAIN_MENU_CHOICES::EXE )
        {
            _trainingMenu->Show();
            return;
        }

        if( static_cast< MAIN_MENU_CHOICES >( choice ) == MAIN_MENU_CHOICES::SETT )
        {
            _settingsMenu->Show();
            return;
        }

        if( static_cast< MAIN_MENU_CHOICES >( choice ) == MAIN_MENU_CHOICES::ADDW )
        {
            _addWordMenu->Show();
            return;
        }

    };
    _mainMenu->SetInputHandler( mainMenuInputHandler );

    _trainingMenu = std::make_shared< Menu >( "Try to remember translation. Enter a number between 0 and 10 indicating how hard ( or easy ) it was to remember it.\n0 - very easy, 10 - can't remember." );
    auto trainingMenuInputHandler = [this]() 
    {
        // constant
        static std::string const prompt = "Try to remember word / phrase: ";

        // all those statics below used to be able to restore menu state, console output of menu, between error transitions
        static std::vector< Word* > wordsBuffer;
        static std::vector< std::size_t > ratingsBuffer;
        static std::size_t bufferIndex = _dict->GetExercizeSize();

        if( bufferIndex < _dict->GetExercizeSize() ) // continue exersize after showing error notification transition
        {
            // restoring console output
            for( std::size_t i = 0; i < bufferIndex; ++i )
            {
                std::cout << prompt << std::endl;
                std::cout << wordsBuffer[ i ] << ": " << ratingsBuffer[ i ]; 
                std::cout << " " << wordsBuffer.size() - bufferIndex << " items left to recall!" << std::endl;
            }
    };
    _trainingMenu->SetInputHandler( trainingMenuInputHandler );

    bool const menusInited = _pendingMenu && _notificationMenu && _mainMenu && _trainingMenu && _settingsMenu && _addWordMenu;
    inited = menusInited && _dict->Init();

    return inited;
}