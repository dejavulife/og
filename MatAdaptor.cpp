#include <cstdlib>
#include "MatAdaptor.h"

vita2d_texture* MatAdaptor::getTexture(const unsigned int c)
{
	unsigned int *tex_ptr;
	vita2d_wait_rendering_done();
	vita2d_free_texture(texture);
	texture = vita2d_create_empty_texture( SCREEN_WIDTH, SCREEN_HEIGHT );
	if ( !texture ) {
		return NULL;
	}
	void *texture_data = vita2d_texture_get_datap(texture);
	unsigned int tex_stride = vita2d_texture_get_stride(texture);
	int y = 0;
	for ( int i = 0; i < SCREEN_HEIGHT; i++) 
	{
		y = SCREEN_HEIGHT - 1 - i;
		tex_ptr = (unsigned int *)(texture_data + y*tex_stride);
		for ( int x = 0; x < SCREEN_WIDTH; x++)
		{
			*tex_ptr = color;
			tex_ptr++;
		}
	}
	return texture;
}

void MatAdaptor::setFinishFlag(const int flag)
{
	finishflag = flag;
}

void MatAdaptor::setColor(const unsigned int c)
{
	color = c;
}