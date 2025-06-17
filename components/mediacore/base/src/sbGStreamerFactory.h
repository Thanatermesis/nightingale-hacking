#ifndef SB_GSTREAMER_FACTORY_H
#define SB_GSTREAMER_FACTORY_H

#include "sbGStreamerPlayer.h"

class sbGStreamerFactory {
public:
    static sbGStreamerPlayer* createPlayer();
};

#endif // SB_GSTREAMER_FACTORY_H
