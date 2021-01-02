#include <iostream>

#include "Menu.hpp"

#include "ErrorMsg.hpp"

Menu::Menu( std::string prompt )
    : _prompt( prompt )
{
    if( _prompt.empty() )
    {
        Error( ERR_MSG( "Empty prompt!" ) );
    }
}

void Menu::Show()
{
    system( "cls" );

    std::cout << _prompt << std::endl;
    
    for( std::size_t index = 0; index < _choices.size(); ++index )
    {
        std::cout << "\t[" << index << "] " << _choices[ index ].GetTitle() << std::endl;
    }
}
