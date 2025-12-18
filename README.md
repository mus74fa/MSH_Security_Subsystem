Security Subsystem – MSH Project
Overview
This component implements the Security System for the Monitoring Smart Home (MSH) application. It is responsible for monitoring the home environment (via simulated camera motion events) and executing a multi-stage emergency response when a breach is detected.

Responsibilities
Centralized Security Control: Managing the "Armed" and "Disarmed" states of the home.

Motion Detection Handling: Responding to camera events when the system is in a high-security state.

Emergency Escalation: Executing a specific sequence of actions (Siren -> Lights -> Police).

Persistent Logging: Ensuring every security event is recorded in the centralized system log for traceability.

Design Patterns Used
1. Singleton Pattern (SecurityController)
The SecurityController is implemented as a Singleton to ensure that only one instance manages the home's security state at any given time. This prevents conflicting security settings and provides a global access point for the Menu System to arm/disarm the house.

2. Chain of Responsibility Pattern
The emergency response logic is decoupled using a Chain of Responsibility. Instead of a single complex function, the response is divided into modular handlers:

AlarmHandler: Triggers the physical siren.

LightHandler: Activates emergency lighting to deter intruders.

PoliceHandler: Contacts authorities as the final escalation step.

Component Structure
SecurityController.h / .cpp: The Singleton controller that initiates the response chain.

ISecurityHandler.h: The interface defining the link in the chain.

AlarmHandler.h, LightHandler.h, PoliceHandler.h: Concrete implementations of the emergency steps.

CameraMotionEvent.h: Data structure representing a detected security breach.

Integration
This module is fully integrated with:

Afnan's Logger: Every handler in the chain logs its status to msh_log.txt.

Rima's MenuSystem: The controller is triggered via the main user interface.

Zakaria's StateSystem: The security chain only executes if the system is in the "Away" or "Night" state.
