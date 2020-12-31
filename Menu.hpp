#pragma once

#include <vector>
#include <string>

#include "Choice.hpp"

class Menu
{
public:
    void Show();

private:
    std::string _prompt;
    std::vector< std::unique_ptr< Choice > > _choices;
};