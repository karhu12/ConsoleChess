#pragma once
#include <string>
#include <vector>

class Command {
public:
    Command() = default;
    Command(std::string name, std::vector<std::string> args) : mName(name), mArgs(args) {}

    std::string toString() const {
        std::string temp = mName;
        for (auto arg : mArgs) {
            temp += " " + arg;
        }
        return temp;
    }

    std::string name() const {
        return mName;
    }

    const std::vector<std::string>& arguments() const {
        return mArgs;
    }

private:
    std::string mName;
    std::vector<std::string> mArgs;
};