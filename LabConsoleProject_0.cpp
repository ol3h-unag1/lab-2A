#include <algorithm>

#include <string>
#include <vector>
#include <map>

#include <iostream>
#include <fstream>
#include <sstream>

#include <cctype>
#include <cassert>

#include <stdexcept>

// refactor into object using menus and item (other menus objects) collections and choices as indexes of those collections

// load words: read file (user inputs file name) or make user to type new word (user inputs word manually)
//      check if new words are already in the library, if new words are in library check their Hard-To-Remember-Rating (HRR, or Rating)

// suggest 15 words for repeating and recalling
// prompt to value how hard was to remember a word ( 0 - easy to remember, 10 - can't remember at all)
//      adjust words Rating index accordingly to result

// TYPES DEFINITIONS
using RatingType = double;
using WordType = std::string;

// GLOBAL VARIABLES
std::vector< RatingType > libraryRatings;
std::vector< WordType > libraryWords;

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

        while( word.size() && std::isspace( word.back() ) );

        //std::cout << "Read line #" << ratings.size() << ": " << rating << " " << word << std::endl;
    }
}

enum class E_MENU_ITEM
{
    INVALID = 0,
    TRAIN = 1,
    ADD = 2,
    QUIT = 3
};

E_MENU_ITEM PromptUserInput()
{
    E_MENU_ITEM menuItem = E_MENU_ITEM::INVALID;

    try {
        while( true )
        {
            std::cout << "Hi! You wanna train memory or add new word(s)? Please enter a number to make a choice:" << std::endl;
            std::cout << "1 - for training\n"
                "2 - for adding new word(s)\n"
                "3 - for quit" << std::endl;

            std::string choice;
            std::getline( std::cin, choice );

            if( choice.empty() ||
                choice.size() > 1 ||
                std::isdigit( choice[ 0 ] ) == false ||
                std::stoi( choice ) < 1 ||
                std::stoi( choice ) > 3 )
            {
                std::cout << "Wrong input. Check input tips or press Ctrl+Z to break quit the programm." << std::endl;
                continue;
            }

            menuItem = static_cast< E_MENU_ITEM >( std::stoi( choice ) );
            break;
        }
    }
    catch( std::invalid_argument& e )
    {
        std::cout << e.what() << std::endl;
    }
    catch( ... )
    {
        std::cout << "Unhandled exeception!" << std::endl;
    }

    return menuItem;
}

void TrainWords()
{

}

void AddWords()
{

}

int main()
{
    ReadLibrary( libraryRatings, libraryWords );

    assert( ( "ratings and words collections have different sizes" ), libraryRatings.size() == libraryWords.size() );
    if( libraryRatings.empty() || libraryWords.empty() || ( libraryRatings.size() != libraryWords.size() ) )
    {
        std::cout << "Exiting app..." << std::endl;
        return 1;
    }

    auto choice = E_MENU_ITEM::INVALID;
    while( choice != E_MENU_ITEM::QUIT )
    {
        choice = PromptUserInput();
        if( choice == E_MENU_ITEM::QUIT )
        {
            continue;
        }

        switch( choice )
        {

        case E_MENU_ITEM::TRAIN:
            TrainWords();
            break;

        case E_MENU_ITEM::ADD:
            AddWords();
            break;

        case E_MENU_ITEM::QUIT:
            continue; // exit on cycle condition check
            break;

        default:
            continue;
            break;
        }

    }

    std::cout << "Quit the programm..." << std::endl;

    libraryRatings.clear();
    libraryWords.clear();

    return 0;
}