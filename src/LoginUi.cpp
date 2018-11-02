#include "LoginUi.hpp"

LoginUi::LoginUi(olc::PixelGameEngine* pge) : Ui(pge) {
    mSprites["Play online"] = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/play_online.png");
    mSprites["Play offline"] = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/play_offline.png");

    mElements["Play online"] = Element(56, 56, mSprites["Play online"].get(), "Play online");
    mElements["Play offline"] = Element(56, 48 + mSprites["Play online"]->height, mSprites["Play offline"].get(), "Play offline");
}
