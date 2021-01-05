#pragma once

#include <iostream>
#include <sstream>

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

bool ReadUnsignedLong( std::size_t& out, std::size_t lowest, std::size_t highest )
{
    bool convertedToUL = true;
    std::string inputStr;
    std::cin >> inputStr;
    try
    {
        out = std::stoul( inputStr );
    }
    catch( ... )
    {
        convertedToUL = false;
    }
    ClearStdCin();
    
    return convertedToUL && ( lowest <= out ) && ( out <= highest );
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

    /////////////////////////////
    _notificationMenu = std::make_shared< Menu >( "Welcome to LEngX - app for memorizing English words!" ); // description used on app start
    auto notificationMenuOnEnterHandler = [this]()
    {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for( 2s );
        _pendingMenu->Show();
    };
    _notificationMenu->SetOnEnterHandler( notificationMenuOnEnterHandler );

    /////////////////////////////
    _mainMenu = std::make_shared< Menu >( "Make you choice:\n\t1. Exercise\n\t2. Add word( s )\n\t3. Settings" );
    _pendingMenu = _mainMenu;
    auto mainMenuInputHandler = [this]() 
    {
        bool validInput = true;
        std::size_t choice = 0;
        std::string inputStr;
        std::cin >> inputStr;
        try 
        {
            choice = std::stoul( inputStr );
        }
        catch( ... )
        {
            validInput = false;
        }
        ClearStdCin();
        
        if( ! validInput )
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

        PRNT_ERR( "Unexpected choice: " + std::to_string( choice ) );

    };
    _mainMenu->SetInputHandler( mainMenuInputHandler );

    /////////////////////////////
    _trainingMenu = std::make_shared< Menu >( "Try to remember translation. Enter a number between 0 and 10 indicating how hard ( or easy ) it was to remember it.\n0 - very easy, 10 - can't remember." );
    auto trainingMenuInputHandler = [this]() 
    {
        // cache is needed for saving training state between showing notification menu on input errors
        static std::stringstream consoleOutputCache;        
        static std::vector< Word* > exercizePortionCache;
        static std::size_t cacheIndex = 0;

        if( cacheIndex == 0 )
        {
            std::vector< Word* > exercizePortion = _dict->GetExersizePortion();
            exercizePortionCache = exercizePortion;

            for( std::size_t i = 0; i < exercizePortion.size(); ++i, cacheIndex = i )
            {
                std::cout << "Try to remember a word/phrase: " << exercizePortion[ i ];
                
                std::size_t userRating = 0u;
                std::cin >> 
            }
        }


        
    };
    _trainingMenu->SetInputHandler( trainingMenuInputHandler );
    
    /////////////////////////////
    _settingsMenu = std::make_shared< Menu >( "SETTINGS MENU WIP" );

    /////////////////////////////
    _addWordMenu = std::make_shared< Menu >( "ADD MENU WIP" );

    /////////////////////////////
    bool const menusInited = _pendingMenu && _notificationMenu && _mainMenu && _trainingMenu && _settingsMenu && _addWordMenu;
    inited = menusInited && _dict->Init();

    return inited;
}