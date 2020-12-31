#pragma once

#include <vector>

#include <memory>
#include <utility>

#include "Dictionary.hpp"
#include "Menu.hpp"

class App
{
public:
    void Start();
    void Finish();

private:
    bool Init();
    void ShowMainMenu();

private:
    std::unique_ptr< Dictionary > _dict{ std::make_unique< Dictionary >() };   

    Menu _mainMenu;
    Menu _trainingMenu;
    Menu _addingMenu;
    Menu _settingsMenu;
};