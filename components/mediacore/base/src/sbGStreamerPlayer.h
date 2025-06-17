#ifndef SB_GSTREAMER_PLAYER_H
#define SB_GSTREAMER_PLAYER_H

#include <gst/gst.h>
#include <string>

class sbGStreamerPlayer {
public:
    sbGStreamerPlayer();
    ~sbGStreamerPlayer();

    bool load(const std::string& uri);
    bool play();
    bool pause();
    bool stop();
    bool set_position(gint64 position);
    gint64 get_position();
    gint64 get_duration();
    GstState get_state();

private:
    GstElement* pipeline;
    GstBus* bus;
    bool is_loaded;
};

#endif // SB_GSTREAMER_PLAYER_H
