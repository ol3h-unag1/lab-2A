#include "Choice.hpp"

#include "Menu.hpp"

#include "ErrorMsg.hpp"

Choice::Choice( std::string title, std::shared_ptr< Menu > const targetMenu )
    : _title( title )
    , _targetMenu( targetMenu )
{
    if( _title.empty() )
    {
        Error( ERR_MSG( "Empty title!" ) );
    }

    if( !_targetMenu.lock() )
    {
        Error( ERR_MSG( "No target menu!" ) );
    }
}

void Choice::Apply()
{ 
    if( auto menu = _targetMenu.lock() )
    {
        menu->Show();
    }
    else
    {
        Error( ERR_MSG( "No target menu!" ) );
    }
}
