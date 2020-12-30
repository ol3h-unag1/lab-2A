#pragma once

#include <memory>
#include <utility>

#include "Dictionary.hpp"

class App
{
public:
    void Start();
    void Finish();

private:
    bool Init();
    void ShowFirstMenu();

private:
    std::unique_ptr< Dictionary > _dict;
};