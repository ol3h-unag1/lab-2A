#pragma once

#include <vector>

#include "Word.hpp"

class Dictionary
{
public:
    bool Init();
    std::vector< Word* > GetExersizePortion();
    void UpdateLibrary();

private:
    // bool ReadLibraryTest();
    bool ReadLibrary();

private:
    inline static std::string const libraryFileName = "library.txt";

    std::size_t const _portionSize = 15;

    std::vector< Word > _words;
};
