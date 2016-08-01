#ifndef _NOTIFICATIONS_H_
#define _NOTIFICATIONS_H_

enum NOTIFICATION
{
    QUEST_AVAILABLE,
    QUEST_ACCEPTED,
    QUEST_COMPLETED,
    QUEST_OBJECTIVE_COMPLETED,
    INVALID_DEEP_LINK_ERROR,
    APP_CONFIGURATION_ERROR,
    VSTB_SERVER_ERROR,
    VIDEO_PLAYBACK_ERROR,
    VIDEO_PLAYBACK_CHANNEL_AUTH_ERROR,
    VIDEO_CONTENT_AUTH_LEVEL_ERROR,
    NETWORK_CONNECTION_ERROR,
    LOGOUT_CONFIRMATION,
    LOGOUT_SUCCESS,
    LOGOUT_FAIL
};

enum NOTIFICATION_TYPE
{
    DIALOG_NOTIFICATION_TYPE,
    GENERAL_NOTIFICATION_TYPE,
    SUCCESS_NOTIFICATION_TYPE,
    ERROR_NOTIFICATION_TYPE,
    UNKNOWN_NOTIFICATION_TYPE
};

#endif // _NOTIFICATIONS_H_

