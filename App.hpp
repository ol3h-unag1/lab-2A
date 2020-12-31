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

    std::shared_ptr< Menu > _mainMenu;
    std::shared_ptr< Menu > _trainingMenu;
    std::shared_ptr< Menu > _addingMenu;
    std::shared_ptr< Menu > _settingsMenu;
};