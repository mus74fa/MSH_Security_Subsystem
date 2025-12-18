#ifndef POLICE_HANDLER_H
#define POLICE_HANDLER_H

#include "ISecurityHandler.h"
#include "Logger.h"
#include <iostream>

class PoliceHandler : public ISecurityHandler {
public:
    void handle() {
        std::cout << "[Security Step 3] Sequence Complete: Calling Police (LLR-SC4)" << std::endl;
        Logger::getInstance().log("CRITICAL: Police contacted due to security breach.");
        // End of chain, no "next" call here
    }
};

#endif