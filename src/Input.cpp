#include "Input.hpp"

const Command Input::get() {
    std::string userInput;
    std::getline(std::cin, userInput);

    std::istringstream ss{userInput};
    using StrIt = std::istream_iterator<std::string>;
    std::vector<std::string> spaceSeparated{StrIt{ss}, StrIt{}};
    
    if (spaceSeparated.size() > 0) {
        userInput = *spaceSeparated.begin();
        std::vector<std::string> args(spaceSeparated.begin() + 1, spaceSeparated.end());
        return Command(userInput, args);
    }
    return Command();
}