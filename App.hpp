#pragma once

#include <vector>

#include <memory>
#include <utility>

class Dictionary;
class Menu;

class App
{
public:
    void Start();

public:
    static void UpdateLibrary();

private:
    bool Init();

private:
    static App* s_application;

    std::shared_ptr< Dictionary > _dict;

    std::shared_ptr< Menu > _pendingMenu; // activated after notification transition

    std::shared_ptr< Menu > _notificationMenu;
    std::shared_ptr< Menu > _mainMenu;
    std::shared_ptr< Menu > _trainingMenu;
    std::shared_ptr< Menu > _settingsMenu;
    std::shared_ptr< Menu > _addWordMenu;
};