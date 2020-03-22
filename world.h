#ifndef _OG_WORLD_H
#define _OG_WORLD_H
#include "shareObject.h"

class world
{
    public:
        double eye;
        int hand;
        double feel;
    void startup();
    void shutdown();
    void process(shareObj* shobj);
    private:
        void mydoing();
};

#endif