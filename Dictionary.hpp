#pragma once

#include <vector>

#include "Word.hpp"

class Dictionary
{
public:
    bool Init();

    std::size_t GetExercizeSize() const { exerciseSize; }
    std::size_t SetExercizeSize( std::size_t size ) { exerciseSize = size; }

private:
    bool ReadLibrary();

private:
    std::size_t exerciseSize = 15;

    std::vector< Word > _words;
};
