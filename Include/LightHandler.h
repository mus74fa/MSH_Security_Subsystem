#ifndef LIGHT_HANDLER_H
#define LIGHT_HANDLER_H

#include "ISecurityHandler.h"
#include "Logger.h"
#include <iostream>

class LightHandler : public ISecurityHandler {
public:
    void handle() {
        std::cout << "[Security Step 2] Emergency Lights ON (LLR-SC3)" << std::endl;
        Logger::getInstance().log("Security: Emergency lighting activated.");
        if (next) next->handle();
    }
};

#endif