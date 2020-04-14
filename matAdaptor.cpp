#include <cstdlib>
#include "matAdaptor.h"

#define RGBA8(r,g,b,a) ((((a)&0xFF)<<24) | (((b)&0xFF)<<16) | (((g)&0xFF)<<8) | (((r)&0xFF)<<0))


vita2d_texture* MatAdaptor::getTexture(const unsigned int c)
{
	unsigned int *tex_ptr;
	vita2d_wait_rendering_done();
	//vita2d_free_texture(texture);
	if (!texture) {
		texture = vita2d_create_empty_texture( SCREEN_WIDTH, SCREEN_HEIGHT );
		if ( !texture ) return NULL;
	}
	//texture = buf[index];
	void *texture_data = vita2d_texture_get_datap(texture);
	unsigned int tex_stride = vita2d_texture_get_stride(texture);
	int y = 0;
	int mx=0, my=0, mat_x=0,mat_y=0;
	unsigned int tmpcolor;
	unsigned int b,g,r,a;
	unsigned int black = 0xFF000000;
	if ( mymat.cols < SCREEN_WIDTH ) 
	{
		mx = ( SCREEN_WIDTH - mymat.cols ) / 2;
	}
	if ( mymat.rows < SCREEN_HEIGHT ) 
	{
		my = ( SCREEN_HEIGHT - mymat.rows ) / 2;
	}
	for ( int i = 0; i < SCREEN_HEIGHT; i++) 
	{
		y = SCREEN_HEIGHT - 1 - i;
		tex_ptr = (unsigned int *)(texture_data + y*tex_stride);
		for ( int x = 0; x < SCREEN_WIDTH; x++)
		{
			if ( y < my || (y - mymat.rows) > my ) 
			{
				*tex_ptr = black;
				tex_ptr++;
				continue;
			}
			if ( x < mx || (x - mymat.cols) > mx) 
			{
				*tex_ptr = black;
				tex_ptr++;
				continue;
			}
			mat_x = x - mx;
			mat_y = y - my;
			b = mymat.at<cv::Vec3b>(mat_y,mat_x)[0] & 0xFF;
			g = mymat.at<cv::Vec3b>(mat_y,mat_x)[1] & 0xFF;
			r = mymat.at<cv::Vec3b>(mat_y,mat_x)[2] & 0xFF;
			a = 0xFF;
			tmpcolor = RGBA8(r,g,b,a);
			*tex_ptr = tmpcolor;
			tex_ptr++;
		}
	}
	return texture;
}

void MatAdaptor::setFlag(const int flag)
{
	modeflag = flag;
}

void MatAdaptor::setColor(const unsigned int c)
{
	color = c;
	if ( modeflag == 0 )
	{
		setMatColor(c);
	} else if ( modeflag == 1)
	{
		loadMat();
	} else {

	}
}

void MatAdaptor::setMatColor(const unsigned int c)
{
	for ( int y=0; y < mymat.rows; y++ )
	{
		for ( int x=0; x < mymat.cols; x++)
		{
			mymat.at<cv::Vec3b>(y,x)[0]= ((c & 0xFF0000) >> 16);
			mymat.at<cv::Vec3b>(y,x)[1]= ((c & 0xFF00) >> 8);
			mymat.at<cv::Vec3b>(y,x)[2]= (c & 0xFF );
		}
	}
}

void MatAdaptor::loadMat()
{
	mymat = cv::imread("ux0:data/og.png");
}
