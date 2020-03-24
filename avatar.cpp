#include <stdio.h>
#include "avatar.h"

#define FONTPGF "ux0:data/font.pgf"

void avatar::startup()
{
    vita2d_init();
    vita2d_set_clear_color(RGBA8(0x00, 0x00, 0x00, 0xFF));
    pgf = vita2d_load_custom_pgf(FONTPGF);
    if (pgf == NULL) { 
        pgf = vita2d_load_default_pgf(); 
    }
}

void avatar::shutdown()
{
    vita2d_fini();
    vita2d_free_pgf(pgf);
}

void avatar::process(shareObj* shobj)
{
    vita2d_start_drawing();
    vita2d_clear_screen();
    //draw something here
    drawscreen(shobj->mad);
    mydoing(shobj);
    vita2d_end_drawing();
    vita2d_swap_buffers();

}

void avatar::drawscreen(MatAdaptor* mad)
{
	if ( !mad ) {
		return;
	} 
	vita2d_texture* tx = mad->getTexture(1);
	if ( tx == NULL ) {
		return;
	}
	vita2d_draw_texture(tx, 0, 0);
}

void avatar::mydoing(shareObj* shobj)
{
    int key_step = 20, y = 520;
    int i= 1;
    //left stick 
    sprintf(str, "[%03d,%03d]", shobj->lx, shobj->ly);
    vita2d_pgf_draw_text(pgf, key_step * i++, y -20, RGBA8(0,255,0,255), 1.0f, str);
    //key_L 
    sprintf(str, "L");
    if (shobj->L) 
    {
        vita2d_pgf_draw_text(pgf, key_step * i++, y, RGBA8(255,0,0,255), 1.0f, str);
    } else {
        vita2d_pgf_draw_text(pgf, key_step * i++, y, RGBA8(0,255,0,255), 1.0f, str);
    }
    //key_left 
    sprintf(str, "<");
    if (shobj->left) 
    {
        vita2d_pgf_draw_text(pgf, key_step * i++, y, RGBA8(255,0,0,255), 1.0f, str);
    } else {
        vita2d_pgf_draw_text(pgf, key_step * i++, y, RGBA8(0,255,0,255), 1.0f, str);
    }
    //key_up 
    sprintf(str, "^");
    if (shobj->up) 
    {
        vita2d_pgf_draw_text(pgf, key_step * i++, y, RGBA8(255,0,0,255), 1.0f, str);
    } else {
        vita2d_pgf_draw_text(pgf, key_step * i++, y, RGBA8(0,255,0,255), 1.0f, str);
    }
    //key_down 
    sprintf(str, "v");
    if (shobj->down) 
    {
        vita2d_pgf_draw_text(pgf, key_step * i++, y, RGBA8(255,0,0,255), 1.0f, str);
    } else {
        vita2d_pgf_draw_text(pgf, key_step * i++, y, RGBA8(0,255,0,255), 1.0f, str);
    }
    //key_right 
    sprintf(str, ">");
    if (shobj->right) 
    {
        vita2d_pgf_draw_text(pgf, key_step * i++, y, RGBA8(255,0,0,255), 1.0f, str);
    } else {
        vita2d_pgf_draw_text(pgf, key_step * i++, y, RGBA8(0,255,0,255), 1.0f, str);
    }
    //key_E 
    sprintf(str, "E");
    if (shobj->X) 
    {
        vita2d_pgf_draw_text(pgf, key_step * i++, y, RGBA8(255,0,0,255), 1.0f, str);
    } else {
        vita2d_pgf_draw_text(pgf, key_step * i++, y, RGBA8(0,255,0,255), 1.0f, str);
    }
    //key_A 
    sprintf(str, "A");
    if (shobj->Y) 
    {
        vita2d_pgf_draw_text(pgf, key_step * i++, y, RGBA8(255,0,0,255), 1.0f, str);
    } else {
        vita2d_pgf_draw_text(pgf, key_step * i++, y, RGBA8(0,255,0,255), 1.0f, str);
    }
    //key_X 
    sprintf(str, "X");
    if (shobj->A) 
    {
        vita2d_pgf_draw_text(pgf, key_step * i++, y, RGBA8(255,0,0,255), 1.0f, str);
    } else {
        vita2d_pgf_draw_text(pgf, key_step * i++, y, RGBA8(0,255,0,255), 1.0f, str);
    }
    //key_O 
    sprintf(str, "O");
    if (shobj->B) 
    {
        vita2d_pgf_draw_text(pgf, key_step * i++, y, RGBA8(255,0,0,255), 1.0f, str);
    } else {
        vita2d_pgf_draw_text(pgf, key_step * i++, y, RGBA8(0,255,0,255), 1.0f, str);
    }
    //key_R 
    sprintf(str, "R");
    if (shobj->R) 
    {
        vita2d_pgf_draw_text(pgf, key_step * i++, y, RGBA8(255,0,0,255), 1.0f, str);
    } else {
        vita2d_pgf_draw_text(pgf, key_step * i++, y, RGBA8(0,255,0,255), 1.0f, str);
    }
    //key_select 
    sprintf(str, "s");
    if (shobj->select) 
    {
        vita2d_pgf_draw_text(pgf, key_step * i++, y, RGBA8(255,0,0,255), 1.0f, str);
    } else {
        vita2d_pgf_draw_text(pgf, key_step * i++, y, RGBA8(0,255,0,255), 1.0f, str);
    }
    //key_start 
    sprintf(str, "S");
    if (shobj->start) 
    {
        vita2d_pgf_draw_text(pgf, key_step * i++, y, RGBA8(255,0,0,255), 1.0f, str);
    } else {
        vita2d_pgf_draw_text(pgf, key_step * i++, y, RGBA8(0,255,0,255), 1.0f, str);
    }
    //right stick 
    sprintf(str, "[%03d,%03d]", shobj->rx, shobj->ry);
    vita2d_pgf_draw_text(pgf, key_step * i++, y - 20, RGBA8(0,255,0,255), 1.0f, str);

    sprintf(str, "FRONT:P[%04d,%04d]T[%04d,%04d]R[%04d,%04d]", shobj->front_axis[0][0],shobj->front_axis[0][1],shobj->front_axis[1][0],shobj->front_axis[1][1], shobj->front_axis[2][0], shobj->front_axis[2][1]);
    vita2d_pgf_draw_text(pgf, 10, y - 60, RGBA8(0,255,0,255), 1.0f, str);
    sprintf(str, "BACK:P[%04d,%04d]T[%04d,%04d]R[%04d,%04d]", shobj->back_axis[0][0],shobj->back_axis[0][1],shobj->back_axis[1][0],shobj->back_axis[1][1], shobj->back_axis[2][0], shobj->back_axis[2][1]);
    vita2d_pgf_draw_text(pgf, 10, y - 40, RGBA8(0,0,255,255), 1.0f, str);
    
}