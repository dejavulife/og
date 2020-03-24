#ifndef _OG_SHAREOBJECT_H
#define _OG_SHAREOBJECT_H
#include "MatAdaptor.h"

class shareObj
{
    public:
        int updateflag;
        int exitflag;
        int up, down, left, right;
        int L, R;
        int select, start;
        int lx, ly, rx, ry;
        int A, B, X, Y;
		unsigned int color;
        //press: axis[0], touching: axis[1], release: axis[2]
        // x: axis[x][0], y: axis[x][1]
        int front_axis[3][2], back_axis[3][2]; 
		MatAdaptor* mad = NULL;
        void startup();
        void shutdown();
        void clear();
		
};

#endif