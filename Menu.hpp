#pragma once

#include <vector>
#include <string>
#include <functional>

#include "Choice.hpp"

class Menu
{
public:
    //explicit Menu( std::function< std::string( void ) > description );
    explicit Menu( std::string descriptionMsg );

public:
    void Show();

    //void SetDescription( std::function< std::string( void ) > description );
    void SetDescription( std::string descriptionMsg );

    void SetOnEnterHandler( std::function< void( void ) > handler );

private:
    //std::function< std::string( void ) > _description;
    std::string _description;
    
    std::function< void( void ) > _onEnter;
};