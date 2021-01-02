#pragma once

#include <vector>
#include <string>

#include "Choice.hpp"

class Menu
{
public:
    explicit Menu( std::string prompt );

public:
    void Show();
    void AddChoice( Choice choice ) { _choices.push_back( choice ); }

private:
    std::string _prompt;
    std::vector< Choice > _choices;
};