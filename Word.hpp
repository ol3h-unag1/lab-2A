#pragma once

#include <string>
#include <memory>

class Dictionary;

class Word
{ 
public:
    explicit Word( std::string str, double rating );

public:
    std::string GetStr() const { return _str; }
    double GetRating() const { return _rating; }
    
    void AdjustRating( std::size_t userScore );

private:   
    std::string const _str;
    double _rating;
};