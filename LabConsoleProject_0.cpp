#include <algorithm>

#include <string>
#include <vector>
#include <map>

#include <iostream>
#include <fstream>
#include <sstream>

#include <cctype>

// load words: read file (user inputs file name) or make user to type new word (user inputs word manually)
//      check if new words are already in the library, if new words are in library check their Hard-To-Remember-Rating (HRR, or Rating)

// suggest 15 words for repeating and recalling
// prompt to value how hard was to remember a word ( 0 - easy to remember, 10 - can't remember at all)
//      adjust words Rating index accordingly to result

// TYPES DEFINITIONS
using RatingType = double;
using WordType = std::string;

// FREE FUNCTIONS
// check if Rating is in range, if not move it to the closest boundary
RatingType ClapRating( RatingType Rating )
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

void ReadLibrary( std::vector< RatingType >& ratings, std::vector< WordType >& words )
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
        ratings.emplace_back( 0.0 );
        auto& rating = ratings.back();
        libraryFileInput >> rating;
        rating = ClapRating( rating );
        if( !libraryFileInput.eof() && !libraryFileInput.good() )
        {
            std::cout << "Error reading rating at line: " << ratings.size() << std::endl;
            ratings.clear();
            words.clear();
            return;
        }
        
        while( std::isspace( libraryFileInput.peek() ) && libraryFileInput.seekg( std::size_t( libraryFileInput.tellg() ) + 1 )  );

        words.emplace_back( "" );
        auto& word = words.back();
        std::getline( libraryFileInput, word );            
        if( !libraryFileInput.eof() && !libraryFileInput.good() )
        {
            std::cout << "Error reading word at line: " << words.size() << std::endl;
            ratings.clear();
            words.clear();
            return;
        }
        while( word.size() && std::isspace( word.back() ) )

        std::cout << "Read line #" << ratings.size() << ": " << rating << " " << word << std::endl;
    }
}

int main()
{
    std::vector< RatingType > libraryRatings;
    std::vector< WordType > libraryWords;
    ReadLibrary( libraryRatings, libraryWords );

    if( libraryRatings.empty() || libraryWords.empty() || ( libraryRatings.size() != libraryWords.size() ) )
    {
        std::cout << "Exiting app..." << std::endl;
        return 1;
    }

    libraryRatings.clear();
    libraryWords.clear();
    return 0;
}