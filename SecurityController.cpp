#include "SecurityController.h"
#include "Logger.h" // Integration with Afnan
#include <iostream>

SecurityController* SecurityController::instance = 0;

SecurityController::SecurityController() : active(false) {
    // Create the Chain
    AlarmHandler* alarm = new AlarmHandler();
    LightHandler* light = new LightHandler();
    PoliceHandler* police = new PoliceHandler();

    // Link the Chain
    alarm->setNext(light);
    light->setNext(police);

    sequenceChain = alarm;
}

SecurityController* SecurityController::getInstance() {
    if (!instance) instance = new SecurityController();
    return instance;
}

void SecurityController::setActive(bool status) {
    active = status;
    Logger::getInstance().log(status ? "Security ARMED" : "Security DISARMED");
}

bool SecurityController::isActive() const {
    return active;
}

void SecurityController::onMotionDetected() {
    if (active) {
        std::cout << "[SecurityController] Motion detected! Initiating sequence..." << std::endl;
        sequenceChain->handle(); // Starts Alarm -> Light -> Police
    }
}