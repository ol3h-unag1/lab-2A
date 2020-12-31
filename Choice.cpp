#include "Choice.hpp"

#include "Menu.hpp"

#include "ErrorMsg.hpp"

Choice::Choice( std::string title, std::shared_ptr< Menu > targetMenu )
    : _title( title )
    , _target( targetMenu )
{
    if( _title.empty() )
    {
        Error( ERR_MSG( "Empty title!" ) );
    }

    if( !_target )
    {
        Error( ERR_MSG( "No target menu!" ) );
    }
}

void Choice::Apply()
{
    if( _target )
    {
        _target->Show();
    }
    else
    {
        Error( ERR_MSG( "No target menu!" ) );
    }
}
