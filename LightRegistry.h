#ifndef LIGHT_REGISTRY_H
#define LIGHT_REGISTRY_H
#include <vector>
#include <string>

class LightRegistry {
public:
    std::vector<std::string> secureLights;
    void addLight(std::string id) { secureLights.push_back(id); }
};
#endif