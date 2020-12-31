#include <iostream>

#include "Menu.hpp"

void Menu::Show()
{
    std::cout << _prompt << std::endl;
    
    for( std::size_t index = 0; index < _choices.size(); ++index )
    {
        std::cout << "\t[" << index << "] " << _choices[ index ]->GetTitle() << std::endl;
    }
}
