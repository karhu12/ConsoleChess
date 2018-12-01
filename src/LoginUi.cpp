#include "LoginUi.hpp"

LoginUi::LoginUi(olc::PixelGameEngine* pge) : Ui(pge) {
    mSprites["Play online"] = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/play_online.png");
    mSprites["Play offline"] = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/play_offline.png");
    mSprites["New Game"] = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/new_game.png");
    mSprites["Load Game"] = std::make_unique<olc::Sprite>("D:/Ohjelmointi/ConsoleChess/images/load_game.png");

    mElements["Play online"] = Element(56, 56, mSprites["Play online"].get(), "Play online");
    mElements["Play offline"] = Element(56, 48 + mSprites["Play online"]->height, mSprites["Play offline"].get(), "Play offline");
    mElements["New Game"] = Element(56, 56, mSprites["New Game"].get(), "New Game");
    mElements["New Game"].shown = false;
    mElements["Load Game"] = Element(56, 48 + mSprites["New Game"]->height, mSprites["Load Game"].get(), "Load Game");
    mElements["Load Game"].shown = false;
}
