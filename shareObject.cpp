#include "shareObject.h"

void shareObj::startup()
{
    updateflag = 1;
    exitflag = 0;
    up = 0; 
    down = 0;
    left = 0;
    right = 0;
    L = 0;
    R = 0;
    select = 0;
    start = 0;
    lx = 0;
    ly = 0;
    rx = 0;
    ry = 0;
    A = 0;
    B = 0;
    X = 0;
    Y = 0;
    for ( int i = 0 ; i < 3 ; i++) {
        for ( int j =0; j < 2; j++) {
            front_axis[i][j] = 0;
            back_axis[i][j] = 0;
        }
    }
}

void shareObj::shutdown()
{
    
    
}

void shareObj::clear()
{
    up = 0; 
    down = 0;
    left = 0;
    right = 0;
    L = 0;
    R = 0;
    select = 0;
    start = 0;
    lx = 0;
    ly = 0;
    rx = 0;
    ry = 0;
    A = 0;
    B = 0;
    X = 0;
    Y = 0;
    for ( int i = 0 ; i < 3 ; i++) {
        for ( int j =0; j < 2; j++) {
            front_axis[i][j] = 0;
            back_axis[i][j] = 0;
        }
    }
}