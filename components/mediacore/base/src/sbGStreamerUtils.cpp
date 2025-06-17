#include "sbGStreamerUtils.h"

namespace sbGStreamerUtils {

std::string gst_state_to_string(GstState state) {
    switch (state) {
        case GST_STATE_VOID_PENDING: return "VOID_PENDING";
        case GST_STATE_NULL: return "NULL";
        case GST_STATE_READY: return "READY";
        case GST_STATE_PAUSED: return "PAUSED";
        case GST_STATE_PLAYING: return "PLAYING";
        default: return "UNKNOWN";
    }
}

}
