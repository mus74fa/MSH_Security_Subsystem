#ifndef SECURITY_CONTROLLER_H
#define SECURITY_CONTROLLER_H

#include "ISecurityHandler.h"
#include "AlarmHandler.h"
#include "LightHandler.h"
#include "PoliceHandler.h"

class SecurityController {
private:
    static SecurityController* instance;
    bool active;
    ISecurityHandler* sequenceChain;

    SecurityController(); // Private constructor

public:
    static SecurityController* getInstance(); //
    void setActive(bool status);
    bool isActive() const;
    void onMotionDetected(); // Triggers LLR-SC1 through LLR-SC5
};

#endif