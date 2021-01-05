#include "Word.hpp"

Word::Word( std::string str, double rating )
    : _str( str )
    , _rating( rating )
{}

void Word::AdjustRating( std::size_t userScore )
{
    _rating = ( _rating + userScore ) / 5;
}
