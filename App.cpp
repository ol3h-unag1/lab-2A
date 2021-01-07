#pragma once

#include <iostream>
#include <sstream>

#include <string>
#include <vector>

#include <chrono>
#include <thread>

#include <limits>
#include <type_traits>

#include <exception>

#include "ErrorMsg.hpp"

#include "App.hpp"
#include "Dictionary.hpp"
#include "Menu.hpp"



App* App::s_application = nullptr;

enum class MAIN_MENU_CHOICES : std::size_t
{
    EXE = 1,
    ADDW = 2,
    SETT = 3,

    MIN = EXE,
    MAX = SETT
};

enum class SETTINGS_MENU_CHOICES : std::size_t
{
    EXE_SIZE = 1,
    MAIN = 2,

    MIN = EXE_SIZE,
    MAX = MAIN
};

enum class ADDW_MENU_CHOICES : std::size_t
{
    MAN = 1,
    FILE = 2,
    MAIN = 3,

    MIN = MAN,
    MAX = MAIN
};

template< typename Enum >
std::size_t ToSizeT( Enum e )
{
    if( !std::is_enum_v< Enum > )
    {
        throw std::invalid_argument( ERR_MSG( "Argument passes is not an enum!" ) );
    }

    if( !std::is_same_v< std::size_t, std::underlying_type_t< Enum > > )
    {
        throw std::invalid_argument( ERR_MSG( "Enum's underlying type is not a std::size_t passes is not an enum!" ) );
    }

    return static_cast< std::size_t >( e );
}

template< typename Enum >
Enum EMin()
{
    return Enum::MIN;
}

template< typename Enum >
Enum EMax()
{
    return Enum::MAX;
}

void ClearStdCin()
{
    std::cin.ignore( std::numeric_limits< std::streamsize >::max(), '\n' );
    std::cin.clear();
}

template< typename Number >
bool ReadNumber( Number& out, Number lowest, Number highest )
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

void App::UpdateLibrary()
{
    if( s_application )
    {
        s_application->_dict->UpdateLibrary();
    }
}

bool App::Init()
{
    static bool inited = false;
    if( inited )
    {
        return true;
    }

    s_application = this;

    _dict = std::make_shared< Dictionary >();

    /////////////////////////////
    _notificationMenu = std::make_shared< Menu >( "Welcome to LEngX - app for memorizing English words!" ); // description used on app start
    auto notificationMenuOnEnterHandler = [this]()
    {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for( 1s );
        _pendingMenu->Show();
    };
    _notificationMenu->SetOnEnterHandler( notificationMenuOnEnterHandler );

    /////////////////////////////
    _mainMenu = std::make_shared< Menu >( "Make you choice:\n\t1. Exercise\n\t2. Add word( s )\n\t3. Settings" );
    _pendingMenu = _mainMenu;
    auto mainMenuInputHandler = [this]() 
    {
        // constants 
        static std::size_t minChoice = ToSizeT( EMin<MAIN_MENU_CHOICES>() );
        static std::size_t maxChoice = ToSizeT( EMax<MAIN_MENU_CHOICES>() );

        std::size_t choice = 0;       
        if( ReadNumber( choice, minChoice, maxChoice ) == false)
        {
            _pendingMenu = _mainMenu;
            _notificationMenu->SetDescription( "Enter number between " + std::to_string( minChoice ) + " and " + std::to_string( maxChoice ) );
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
        // constants
        static std::size_t const minRating = 0;
        static std::size_t const maxRating = 10;

        // cache is needed for saving training state between showing notification menu on input errors
        static std::stringstream consoleOutputCache;        
        static std::vector< Word* > exercizePortionCache;
        static std::size_t cacheIndex = 0;
        static bool newExercize = true;

        std::vector< Word* > exercizePortion;
        std::size_t index = 0;
        if( newExercize ) // new exercize
        {
            consoleOutputCache = std::stringstream();
            exercizePortion = _dict->GetExersizePortion();
            exercizePortionCache = exercizePortion;
        }
        else // continue exercize after showing input error notification
        {
            exercizePortion = exercizePortionCache;
            std::cout << consoleOutputCache.str();
            index = cacheIndex;
        }

        bool firstIterationAfterError = !newExercize;
        for( ; index < exercizePortion.size(); ++index, ++cacheIndex )
        {
            std::string const prompt = "Try to remember a <" + std::to_string( index + 1 ) + "> word/phrase: " + exercizePortion[ index ]->GetStr() + " ";

            if( firstIterationAfterError != true )
            {
                consoleOutputCache << prompt;
                std::cout << prompt;
            }
            firstIterationAfterError = false;

            std::size_t userRating = 0u;
            if( ReadNumber( userRating, minRating, maxRating ) )
            {
                exercizePortion[ index ]->AdjustRating( userRating );
                consoleOutputCache << userRating << std::endl;
            }
            else
            {
                newExercize = false;
                break;
            }
        }

        if( index >= exercizePortion.size() ) // finished exercize
        {
            cacheIndex = 0u;
            newExercize = true;

            _pendingMenu = _mainMenu;
            _notificationMenu->SetDescription( "You've trained " + std::to_string( exercizePortion.size() ) + " word(s)/phrase(s)!" );
            _notificationMenu->Show();
        }
        else // wrong rating: show notification menu and come back here to continue from where it was "paused"
        {
            _pendingMenu = _trainingMenu;
            _notificationMenu->SetDescription( "Enter number between " + std::to_string( minRating ) + " and " + std::to_string( maxRating ) );
            _notificationMenu->Show();
            return;
        }
        
    };
    _trainingMenu->SetInputHandler( trainingMenuInputHandler );
    
    /////////////////////////////
    _settingsMenu = std::make_shared< Menu >( "SETTINGS MENU WIP" );
    auto wipStub = [this]()
    {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for( 1s );
        _mainMenu->Show();
    };
    _settingsMenu->SetOnEnterHandler( wipStub );
    
    /////////////////////////////   
    _addWordMenu = std::make_shared< Menu >( "ADD MENU WIP" );
    _addWordMenu->SetOnEnterHandler( wipStub );

    /////////////////////////////
    bool const menusInited = _pendingMenu && _notificationMenu && _mainMenu && _trainingMenu && _settingsMenu && _addWordMenu;
    inited = menusInited && _dict->Init();

    return inited;
}