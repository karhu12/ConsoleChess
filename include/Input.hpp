#pragma once
#include <vector>
#include <string>

class Input {
public:
    static void get();
    static std::string getCommand() { return mCommand; }
    static const std::vector<std::string>& getArguments() { return mArgs; }

private:
    static std::string mCommand;
    static std::vector<std::string> mArgs;
};


// move A2 to A3