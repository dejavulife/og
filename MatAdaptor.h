#ifndef _OG_MATADAPTOR_H
#define _OG_MATADAPTOR_H
#include "vita2d.h"

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 544


class MatAdaptor
{
	public:
		vita2d_texture* getTexture(const unsigned int c);
		void setColor(const unsigned int c);
		void setFinishFlag(const int flag);
		
	private:
		int finishflag = 1;
		unsigned int color = 0;
		vita2d_texture* texture = NULL;
};

#endif