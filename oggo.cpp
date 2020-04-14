
#include "world.h"
#include "hid.h"
#include "avatar.h"
#include "shareObject.h"
#include <psp2/kernel/processmgr.h>

//extern "C"
//{

shareObj sobj;

int main()
{
    world psvworld;
    avatar psvavatar;
    hid psvhid;
    
    sobj.startup();
    psvhid.startup();
    psvworld.startup();
    psvavatar.startup();
    while(1) 
    {
        psvhid.process(&sobj);
        psvworld.process(&sobj);
        psvavatar.process(&sobj);
        if (sobj.exitflag)
            break;
    }
    psvavatar.shutdown();
    psvhid.shutdown();
    psvworld.shutdown();
    sobj.shutdown();
    sceKernelExitProcess(0);
}
//}
