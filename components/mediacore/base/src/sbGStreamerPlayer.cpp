#include "sbGStreamerPlayer.h"
#include <iostream>

sbGStreamerPlayer::sbGStreamerPlayer()
    : pipeline(nullptr), bus(nullptr), is_loaded(false)
{
    gst_init(nullptr, nullptr);
}

sbGStreamerPlayer::~sbGStreamerPlayer()
{
    if (pipeline) {
        gst_element_set_state(pipeline, GST_STATE_NULL);
        gst_object_unref(pipeline);
    }
    if (bus) {
        gst_object_unref(bus);
    }
}

bool sbGStreamerPlayer::load(const std::string& uri)
{
    if (pipeline) {
        gst_element_set_state(pipeline, GST_STATE_NULL);
        gst_object_unref(pipeline);
        pipeline = nullptr;
    }

    pipeline = gst_element_factory_make("playbin", "player");
    if (!pipeline) {
        std::cerr << "Failed to create playbin element." << std::endl;
        return false;
    }

    g_object_set(pipeline, "uri", uri.c_str(), nullptr);

    bus = gst_element_get_bus(pipeline);
    is_loaded = true;
    return true;
}

bool sbGStreamerPlayer::play()
{
    if (!pipeline) return false;
    gst_element_set_state(pipeline, GST_STATE_PLAYING);
    return true;
}

bool sbGStreamerPlayer::pause()
{
    if (!pipeline) return false;
    gst_element_set_state(pipeline, GST_STATE_PAUSED);
    return true;
}

bool sbGStreamerPlayer::stop()
{
    if (!pipeline) return false;
    gst_element_set_state(pipeline, GST_STATE_NULL);
    return true;
}

bool sbGStreamerPlayer::set_position(gint64 position)
{
    if (!pipeline) return false;
    return gst_element_seek_simple(
        pipeline, GST_FORMAT_TIME,
        GST_SEEK_FLAG_FLUSH | GST_SEEK_FLAG_KEY_UNIT, position);
}

gint64 sbGStreamerPlayer::get_position()
{
    if (!pipeline) return -1;
    gint64 pos = 0;
    if (gst_element_query_position(pipeline, GST_FORMAT_TIME, &pos))
        return pos;
    return -1;
}

gint64 sbGStreamerPlayer::get_duration()
{
    if (!pipeline) return -1;
    gint64 dur = 0;
    if (gst_element_query_duration(pipeline, GST_FORMAT_TIME, &dur))
        return dur;
    return -1;
}

GstState sbGStreamerPlayer::get_state()
{
    if (!pipeline) return GST_STATE_NULL;
    GstState state;
    gst_element_get_state(pipeline, &state, nullptr, GST_CLOCK_TIME_NONE);
    return state;
}
