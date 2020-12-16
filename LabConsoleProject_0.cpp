#include <algorithm>

#include <string>
#include <vector>
#include <map>

#include <iostream>
#include <fstream>
#include <sstream>


// load words: read file (user inputs file name) or make user to type new word (user inputs word manually)
//      check if new words are already in the library, if new words are in library check their Hard-To-Remember-Rating (HRR, or Rating)

// suggest 15 words for repeating and recalling
// prompt to value how hard was to remember a word ( 0 - easy to remember, 10 - can't remember at all)
//      adjust words Rating index accordingly to result

// TYPES DEFINITIONS
using RatingType = double;
using RatingWordPair = std::pair< RatingType, std::string >;
using WordRatingPair = std::pair< std::string, RatingType >;

// check if Rating is in range, if not move it to the closest boundary
RatingType PutInBoundories( RatingType Rating )
{
    RatingType const lowest = 0.0;
    RatingType const highest = 10.0;
    
    if( Rating < lowest )
    {
        return lowest;
    }

    if( Rating > highest )
    {
        return highest;
    }

    return Rating;
}

void ReadLibrary( std::vector< RatingWordPair >& output )
{
    std::string const libraryFileName = "library.txt";
    std::ifstream libraryFileInput( libraryFileName );
    if( libraryFileInput.is_open() == false )
    {
        std::cout << "CAN'T OPEN LIBRARY FILE: " << libraryFileName << std::endl;
        return;
    }
    std::cout << "READING LIBRARY FILE: " << libraryFileName << std::endl;

    while( libraryFileInput && !libraryFileInput.eof() )
    {
        output.emplace_back( std::pair( 0.0, "") );
        
        auto& rating = output.back().first;
        libraryFileInput >> rating;
        rating = PutInBoundories( rating );        
        if( !libraryFileInput.eof() && !libraryFileInput.good() )
        {
            std::cout << "Error reading rating at line: " << output.size() << std::endl;
            output.clear();
            return;
        }

        auto& word = output.back().second;
        std::getline( libraryFileInput, word );
        if( !libraryFileInput.eof() && !libraryFileInput.good() )
        {
            std::cout << "Error reading word at line: " << output.size()  << std::endl;
            output.clear();
            return;
        }

        std::cout << "Read line #" << output.size() << ": " << rating << " " << word << std::endl;
    }

   
}

int main()
{
    std::vector< RatingWordPair > libraryRatingWord;
    ReadLibrary( libraryRatingWord );

    if( libraryRatingWord.empty() )
    {
        std::cout << "Exiting app..." << std::endl;
        return 1;
    }

    libraryRatingWord.clear();
    return 0;
}