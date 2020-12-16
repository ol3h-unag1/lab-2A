#include <algorithm>

#include <string>
#include <vector>
#include <unordered_map>

#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
    std::string const fileNameInput = "english_src.txt";
    std::ifstream fileInput( fileNameInput );
    bool const errorOpeningFile = static_cast< bool >( fileInput ) == false;
    if( errorOpeningFile )
    {
        std::cout << "CAN'T OPEN << " << fileNameInput << std::endl;
        return 1;
    }

    std::cout << fileNameInput << " opened ok! " << std::endl;

    std::vector< std::string > words;
    std::size_t const wordsAproximateReserveSize = 256;
    words.reserve( wordsAproximateReserveSize );

    std::vector< std::string > const ignoredLines{ "My English", "Channel photo changed" };
    char const delimeter{ '/' };

    std::string lineInput;
    while( fileInput )
    {
        std::getline( fileInput, lineInput );
        if( ignoredLines.end() != std::find( ignoredLines.begin(), ignoredLines.end(), lineInput ) )
        {
            continue;
        }

        if( lineInput.size() == 0 )
        {
            continue;
        }

        if( std::isdigit( *lineInput.begin() ) )
        {
            continue;
        }

        if( auto separation = lineInput.find( delimeter ); separation != std::string::npos )
        {
            std::stringstream ss;
            ss << lineInput;

            std::string word;
            std::getline( ss, word, delimeter );

            word.pop_back();
            words.emplace_back( std::move( word ) );

            ss.seekg( separation + 2 );
            std::getline( ss, word, delimeter );
            words.emplace_back( std::move( word ) );

            continue;
        }

        words.emplace_back( std::move( lineInput ) );
        // assert( ("Actually move never happened..."), lineInput.size() == 0 ); // std::move check
    }

    std::cout << words.size() << " word(s) was read from " << fileNameInput << std::endl;
    std::sort( words.begin(), words.end() );

    for( auto const& str : words )
    {
        std::cout << str << std::endl;
    }

    fileInput.close();

    return 0;
}