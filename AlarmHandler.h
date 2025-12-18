#ifndef ALARM_HANDLER_H
#define ALARM_HANDLER_H

#include "ISecurityHandler.h"
#include "Logger.h"
#include <iostream>

class AlarmHandler : public ISecurityHandler {
public:
    void handle() {
        std::cout << "[Security Step 1] Activating Siren (LLR-SC2)" << std::endl;
        Logger::getInstance().log("Security: Siren triggered."); // Integration with Afnan
        if (next) next->handle();
    }
};

#endif