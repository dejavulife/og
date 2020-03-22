#include "world.h"
#include "shareObject.h"


void world::startup()
{
    
    
}

void world::shutdown()
{
    
}

void world::process(shareObj* shobj)
{
    if ( shobj->L == 1 && shobj->start == 1 ){
        shobj->exitflag = 1;
    }
    
}

void world::mydoing()
{
    
}