#pragma once

#include <iostream>
#include <string> 

void StreamError( std::ostream& e, std::string const& msg );

void Error( std::string const& msg );

#define ERR_MSG( msg ) ( std::string( __FILE__ ) + ":" + std::to_string( __LINE__ ) + ": " + std::string( __FUNCSIG__ ) + " " + std::string( (msg) ) )