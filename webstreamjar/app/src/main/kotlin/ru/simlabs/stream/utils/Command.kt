package ru.simlabs.stream.utils

enum class Command {
    SET_CLIENT_TYPE,
    SET_CLIENT_LIMITATIONS,
    SET_CLIENT_RESOLUTION,
    ACTIVATE_POLICY_RULE,
    FORCE_IDR_FRAME,
    CLIENT_STAT_INFO,
    DATA_RECEIVED,
    USE_AUTO_BITRATE,
    USE_AUTO_FRAMERATE,
    USE_DEBUG_FRAME,
    SET_MAX_BITRATE,
    SET_SUSPEND_MODE,
    USE_FAKE_TIMESTAMP,

    // server -> client
    FRAME_SENT,
    FORCE_FLUSH,
    SERVER_STAT_INFO,
    SERVER_RESOLUTION
}