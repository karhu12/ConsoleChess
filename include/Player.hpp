#pragma once
#include <string>

class Player {
public:
    Player() = default;
    Player(const std::string& name) : mName(name) {}
    std::string name() const { return mName; }

private:
    std::string mName;
};