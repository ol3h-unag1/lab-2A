#pragma once

#include <vector>

#include "Word.hpp"

class Dictionary
{
public:
    bool Init();
    std::size_t SetExercizePortionSize( std::size_t size ) { _portionSize = size; }

    std::vector< Word* > GetExersizePortion();

private:
    bool ReadLibrary();

private:
    std::size_t _portionSize = 15;

    std::vector< Word > _words;
};
