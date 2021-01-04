#include <iostream>

#include "Menu.hpp"

Menu::Menu( std::string descriptionMsg )
    : _description( descriptionMsg )
{}

void Menu::Show()
{
    system( "cls" );
    
    if( _description.empty() == false )
    {
        std::cout << _description << std::endl;
    }

    if( _onEnter )
    {
        _onEnter();
    }

    if( _input )
    {
        _input();
    }
}

void Menu::SetDescription( std::string descriptionMsg )
{
    _description = descriptionMsg;
}

void Menu::SetOnEnterHandler( std::function<void( void )> handler )
{
    _onEnter = handler;
}

void Menu::SetInputHandler( std::function< void( void ) > handler )
{
    _input = handler;
}