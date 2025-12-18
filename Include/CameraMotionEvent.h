#ifndef CAMERA_MOTION_EVENT_H
#define CAMERA_MOTION_EVENT_H

#include <string>

class CameraMotionEvent {
public:
    std::string timestamp;
    int zoneID;
    CameraMotionEvent(std::string time, int zone) : timestamp(time), zoneID(zone) {}
};

#endif