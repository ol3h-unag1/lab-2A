#include <cmath>
#include <limits>

#include "Word.hpp"

#include "App.hpp"
#include "Dictionary.hpp"

Word::Word( std::string str, double rating )
    : _str( str )
    , _rating( rating )
{}

void Word::AdjustRating( std::size_t userScore )
{
    _rating = ( _rating + userScore ) / 5;
    App::UpdateLibrary();
}

std::ostream& operator<<( std::ostream& os, Word const& w )
{
    os << w.GetRating() << " " << w.GetStr();
    return os;
}

bool AreSame( double a, double b )
{
    return std::fabs( a - b ) < std::numeric_limits<double>::epsilon();
}

bool operator<( Word const& left, Word const& right )
{
    if( AreSame( left.GetRating(), right.GetRating() ) )
    {
        return left.GetStr() < right.GetStr();
    }

    return left.GetRating() < right.GetRating();
}
