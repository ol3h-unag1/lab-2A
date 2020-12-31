#include "ErrorMsg.hpp"

void StreamError( std::ostream& e, std::string const& msg )
{
    e << "Error: " << msg << std::endl;
}

void Error( std::string const& msg )
{
    StreamError( std::cout, msg );
}
