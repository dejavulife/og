#include <psp2/ctrl.h>
#include <psp2/touch.h>
#include <string.h>
#include "hid.h"

extern "C"
{

void hid::startup()
{
    sceCtrlSetSamplingMode(SCE_CTRL_MODE_ANALOG);
    sceTouchSetSamplingState(SCE_TOUCH_PORT_FRONT, SCE_TOUCH_SAMPLING_STATE_START);
    sceTouchSetSamplingState(SCE_TOUCH_PORT_BACK, SCE_TOUCH_SAMPLING_STATE_START);
    sceTouchEnableTouchForce(SCE_TOUCH_PORT_FRONT);
    sceTouchEnableTouchForce(SCE_TOUCH_PORT_BACK);
}

void hid::shutdown()
{
    //nothing needed to do.
    
    
}

void hid::process(shareObj* shobj)
{
    clearkeys();
    memcpy(touch_old, touch, sizeof(touch_old)); 
    sceCtrlPeekBufferPositive(0, &pad, 1);
    sceTouchPeek(0, &touch[SCE_TOUCH_PORT_FRONT], 1);
    sceTouchPeek(1, &touch[SCE_TOUCH_PORT_BACK], 1);
    if ( istouch_press_f == 0) {
        if ( touch[SCE_TOUCH_PORT_FRONT].reportNum > 0 ) {
            memcpy(touch_press, touch, sizeof(touch_press));
            touch_press_fx = touch_press[SCE_TOUCH_PORT_FRONT].report[0].x;
            touch_press_fy = touch_press[SCE_TOUCH_PORT_FRONT].report[0].y;            
            istouch_press_f = 1;
        }
    } else if ( istouch_press_f == 1 ) {
        if ( touch[SCE_TOUCH_PORT_FRONT].reportNum <= 0 ) {
            memcpy(touch_release, touch_old, sizeof(touch_release));
            touch_release_fx = touch_release[SCE_TOUCH_PORT_FRONT].report[0].x;
            touch_release_fy = touch_release[SCE_TOUCH_PORT_FRONT].report[0].y;      
            istouch_press_f = 0;
        }
    }
    if ( istouch_press_b == 0) {
        if ( touch[SCE_TOUCH_PORT_BACK].reportNum > 0 ) {
            memcpy(touch_press, touch, sizeof(touch_press));
            touch_press_bx = touch_press[SCE_TOUCH_PORT_BACK].report[0].x;
            touch_press_by = touch_press[SCE_TOUCH_PORT_BACK].report[0].y;            
            istouch_press_b = 1;
        }
    } else if ( istouch_press_b == 1 ) {
        if ( touch[SCE_TOUCH_PORT_BACK].reportNum <= 0 ) {
            memcpy(touch_release, touch_old, sizeof(touch_release));
            touch_release_bx = touch_release[SCE_TOUCH_PORT_BACK].report[0].x;
            touch_release_by = touch_release[SCE_TOUCH_PORT_BACK].report[0].y;      
            istouch_press_b = 0;
        }
    }
    int i = 0;
    for(i = 0; i < SCE_TOUCH_MAX_REPORT; i++) {
        if ( i < touch[SCE_TOUCH_PORT_FRONT].reportNum ) {
            touch_fx = touch[SCE_TOUCH_PORT_FRONT].report[i].x;
            touch_fy = touch[SCE_TOUCH_PORT_FRONT].report[i].y;
        }
        if ( i < touch[SCE_TOUCH_PORT_BACK].reportNum ) {
            touch_bx = touch[SCE_TOUCH_PORT_BACK].report[i].x;
            touch_by = touch[SCE_TOUCH_PORT_BACK].report[i].y;
        }
    }
    if (pad.buttons & SCE_CTRL_START) key_start = 1;
    if (pad.buttons & SCE_CTRL_SELECT) key_select = 1;
    if (pad.buttons & SCE_CTRL_UP)  key_up = 1;
    if (pad.buttons & SCE_CTRL_DOWN)  key_down = 1;
    if (pad.buttons & SCE_CTRL_LEFT)  key_left = 1;
    if (pad.buttons & SCE_CTRL_RIGHT)  key_right = 1;
    if (pad.buttons & SCE_CTRL_TRIANGLE) key_A = 1;
    if (pad.buttons & SCE_CTRL_SQUARE) key_E = 1;
    if (pad.buttons & SCE_CTRL_CIRCLE)  key_O = 1;
    if (pad.buttons & SCE_CTRL_CROSS) key_X = 1;
    lx = pad.lx ;
    ly = pad.ly ;
    rx = pad.rx;
    ry = pad.ry;
    if (pad.buttons & SCE_CTRL_LTRIGGER) key_L = 1;
    if (pad.buttons & SCE_CTRL_RTRIGGER) key_R = 1;
	updateShareobj(shobj);
}

void hid::clearkeys()
{
    key_L = 0; 
    key_R = 0; 
    key_start = 0; 
    key_select = 0; 
    key_up = 0; 
    key_down = 0; 
    key_left = 0;
    key_right = 0; 
    key_A = 0; 
    key_E = 0; 
    key_O = 0; 
    key_X = 0;
}

void hid::updateShareobj(shareObj* shobj)
{
    shobj->clear();
    shobj->L = key_L;
    shobj->R = key_R;
    shobj->start = key_start;
    shobj->select = key_select;
    shobj->lx = lx;
    shobj->ly = ly;
    shobj->rx = rx;
    shobj->ry = ry;
    shobj->up = key_up;
    shobj->down = key_down;
    shobj->left = key_left;
    shobj->right = key_right;
    shobj->A = key_X;
    shobj->B = key_O;
    shobj->X = key_E;
    shobj->Y = key_A;
    /* int touch_press_fx, touch_press_fy, touch_fx, touch_fy, touch_release_fx, touch_release_fy; 
        int touch_press_bx, touch_press_by, touch_bx, touch_by, touch_release_bx, touch_release_by; 
        */ 
    shobj->front_axis[0][0] = touch_press_fx;
    shobj->front_axis[0][1] = touch_press_fy;
    shobj->front_axis[1][0] = touch_fx;
    shobj->front_axis[1][1] = touch_fy;
    shobj->front_axis[2][0] = touch_release_fx;
    shobj->front_axis[2][1] = touch_release_fy;
    shobj->back_axis[0][0] = touch_press_bx;
    shobj->back_axis[0][1] = touch_press_by;
    shobj->back_axis[1][0] = touch_bx;
    shobj->back_axis[1][1] = touch_by;
    shobj->back_axis[2][0] = touch_release_bx;
    shobj->back_axis[2][1] = touch_release_by;
}
}
