#ifndef SB_GSTREAMER_UTILS_H
#define SB_GSTREAMER_UTILS_H

#include <gst/gst.h>
#include <string>

namespace sbGStreamerUtils {
    std::string gst_state_to_string(GstState state);
}

#endif // SB_GSTREAMER_UTILS_H
