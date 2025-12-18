#ifndef I_SECURITY_HANDLER_H
#define I_SECURITY_HANDLER_H

class ISecurityHandler {
protected:
    ISecurityHandler* next;
public:
    ISecurityHandler() : next(0) {}
    virtual ~ISecurityHandler() {}
    void setNext(ISecurityHandler* n) { next = n; }
    virtual void handle() = 0;
};

#endif