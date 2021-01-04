#pragma once

#include <vector>
#include <string>
#include <functional>

#include "Choice.hpp"

class Menu
{
public:
    explicit Menu( std::string descriptionMsg );

public:
    void Show();
    void SetDescription( std::string descriptionMsg );
    void SetOnEnterHandler( std::function< void( void ) > handler );

private:
    std::string _description;
    
    std::function< void( void ) > _onEnter;
};