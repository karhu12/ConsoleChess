#pragma once
#include <Application.hpp>
#include <map>

//Single element contains a position, name and sprite and it can be displayed somewhere
struct Element {
    Element() = default;
    Element(int x, int y, olc::Sprite* sprite, const std::string& name) {
        this->x = x;
        this->y = y;
        this->sprite = sprite;
        this->name = name;
    }
    int x, y;
    std::string name;
    olc::Sprite* sprite;
};

//Abstract Ui base class, derive main Ui classes from this
class Ui {
public:
    Ui(olc::PixelGameEngine * engine) : mEngine(engine) {
        mOffsetX = 0;
        mOffsetY = 0;
    }

    virtual void draw(int x = 0, int y = 0) = 0;

    virtual std::string clickedElement() = 0;

    virtual void drawElements(int x = 0, int y = 0) {
        for (auto elem : mElements) {
            mEngine->DrawSprite(elem.second.x + x, elem.second.y + y, elem.second.sprite);
        }
    }
    
protected:
    int mOffsetX, mOffsetY;
    olc::PixelGameEngine* mEngine;
    std::map<std::string, Element> mElements;
    std::map<std::string, std::unique_ptr<olc::Sprite>> mSprites;
};