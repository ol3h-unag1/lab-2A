#include <iostream>
#include <sstream>

#include <chrono>

#include <algorithm>

#include "App.hpp"

int main()
{
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto seconds = std::chrono::duration_cast< std::chrono::seconds >( duration ).count();
    std::cout << seconds << std::endl;

// App app;
//    app.Start();
 
    return 0;
}