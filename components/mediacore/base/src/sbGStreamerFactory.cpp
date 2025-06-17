#include "sbGStreamerFactory.h"

sbGStreamerPlayer* sbGStreamerFactory::createPlayer() {
    return new sbGStreamerPlayer();
}
