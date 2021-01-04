#include "Word.hpp"

Word::Word( std::string str, double rating )
    : _str( str )
    , _rating( rating )
{}

void Word::AdjustRating( double userScore )
{
    _rating = ( _rating + userScore ) / 5;
}
