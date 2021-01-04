#include <iostream>

#include "Menu.hpp"

#include "ErrorMsg.hpp"

Menu::Menu( std::function< std::string( void ) > description )
    : _description( description )
{
}

Menu::Menu( std::string descriptionMsg )
    : _description( nullptr)
{
    _description = [descriptionMsg]() { return descriptionMsg; };
}

void Menu::Show()
{
    system( "cls" );
    
    if( _description )
    {
        std::cout << _description() << std::endl;
    }

    if( _onEnter )
    {
        _onEnter();
    }
}

void Menu::SetOnEnterHandler( std::function<void( void )> handler )
{
    _onEnter = handler;
}
