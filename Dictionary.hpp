#pragma once

#include <vector>

#include "Word.hpp"

class Dictionary
{
public:
    bool Init();
//    std::size_t SetExercizePortionSize( std::size_t size ) { _portionSize = size; }

    std::vector< Word* > GetExersizePortion();

private:
    // bool ReadLibraryTest();
    bool ReadLibrary();

private:
    std::size_t const _portionSize = 15;

    std::vector< Word > _words;
};
