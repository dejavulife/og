#include "world.h"
#include "shareObject.h"
#include "MatAdaptor.h"

#define RGBA8(r,g,b,a) ((((a)&0xFF)<<24) | (((b)&0xFF)<<16) | (((g)&0xFF)<<8) | (((r)&0xFF)<<0))

void world::startup()
{
    
    
}

void world::shutdown()
{
    
}

void world::process(shareObj* shobj)
{
	mydoing(shobj);
    if ( shobj->L == 1 && shobj->start == 1 ){
        shobj->exitflag = 1;
    }
    
}

void world::mydoing(shareObj* shobj)
{
	if (!shobj->mad) {
		shobj->mad=&matada;
	}
    matada.setColor(RGBA8(shobj->lx, shobj->ly, shobj->rx, shobj->ry));
}