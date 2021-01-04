#pragma once

#include <string>

class Word
{  
    explicit Word( std::string str, double rating );

private: 
    std::string const _str;
    double _rating;
};