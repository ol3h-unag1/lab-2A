#pragma once

#include <vector>

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
};
