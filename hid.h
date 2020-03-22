#ifndef _OG_HID_H
#define _OG_HID_H

#include <psp2/ctrl.h>
#include <psp2/touch.h>
#include "shareObject.h"

class hid
{
    public:
        int key_L, key_R, key_start, key_select, \
            key_up, key_down, key_left, key_right, \
            key_A, key_E, key_O, key_X, \
            lx, ly, rx, ry;
        int touch_press_fx, touch_press_fy, touch_fx, touch_fy, touch_release_fx, touch_release_fy; 
        int touch_press_bx, touch_press_by, touch_bx, touch_by, touch_release_bx, touch_release_by; 
    void startup();
    void shutdown();
    void process(shareObj* shobj);
    void updateShareobj(shareObj* shobj);
    private:
        int istouch_press_f = 0 , istouch_press_b = 0;
        SceCtrlData pad;
        SceTouchData touch_old[SCE_TOUCH_PORT_MAX_NUM];
        SceTouchData touch_press[SCE_TOUCH_PORT_MAX_NUM];
        SceTouchData touch_release[SCE_TOUCH_PORT_MAX_NUM];
        SceTouchData touch[SCE_TOUCH_PORT_MAX_NUM];
        void clearkeys();
};

#endif