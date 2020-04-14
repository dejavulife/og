#ifndef _OG_MATADAPTOR_H
#define _OG_MATADAPTOR_H
#include "vita2d.h"
#include "opencv2/core.hpp"
#include "opencv2/imgcodecs.hpp"
#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 544


class MatAdaptor
{
	public:
		vita2d_texture* getTexture(const unsigned int c);
		void setColor(const unsigned int c);
		void setFlag(const int flag);
		void setMatColor(const unsigned int c);
		void loadMat();
		
	private:
		int modeflag = 1;
		cv::Mat mymat = cv::Mat(SCREEN_HEIGHT,SCREEN_WIDTH,CV_8UC3);
		unsigned int color = 0;
		vita2d_texture* texture = NULL;
};

#endif
