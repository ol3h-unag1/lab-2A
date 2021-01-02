#pragma once

#include <memory>
#include <string>

class Menu;

class Choice
{
public:
    explicit Choice( std::string title, std::shared_ptr< Menu > const targetMenu );

public:
    std::string GetTitle() const { return _title; }
    void Apply();

private:
    std::string _title;
    std::weak_ptr< Menu > const _targetMenu;
};