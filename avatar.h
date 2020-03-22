#ifndef _OG_AVATAR_H
#define _OG_AVATAR_H
#include <vita2d.h>
#include "shareObject.h"

class avatar
{
    public:
        double move;
        int action;
        double express;
        char str[2048]={};
        vita2d_pgf *pgf;
    void startup();
    void shutdown();
    void process(shareObj* shobj);
    private:
        void mydoing(shareObj* shobj);
};


#endif