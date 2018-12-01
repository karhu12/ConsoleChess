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
    bool shown = true;
};

//Abstract Ui base class, derive main Ui classes from this
class Ui {
public:
    Ui(olc::PixelGameEngine * engine) : mEngine(engine) {
        mOffsetX = 0;
        mOffsetY = 0;
    }

    //Used to call current ui's draw of elements
    virtual void draw(int x = 0, int y = 0) = 0;


    virtual std::vector<Element> clickedElement() {
        int mouseX = mEngine->GetMouseX();
        int mouseY = mEngine->GetMouseY();
        std::vector<Element> elements;

        for (const auto& elem : mElements) {
            if (mouseX >= elem.second.x + mOffsetX && mouseX < elem.second.x + mOffsetX + elem.second.sprite->width) {
                if (mouseY >= elem.second.y + mOffsetY && mouseY < elem.second.y + mOffsetY + elem.second.sprite->height)
                    if (elem.second.shown)
                        elements.push_back(elem.second);
            }
        }
        return elements;
    }

    virtual void drawElements(int x = 0, int y = 0) {
        for (auto& elem : mElements) {
            if (elem.second.shown)
                mEngine->DrawSprite(elem.second.x + x, elem.second.y + y, elem.second.sprite);
        }
    }

    virtual void showElement(const std::string& elemName, bool shown = true) {
        if (shown)
            mElements[elemName].shown = true;
        else
            mElements[elemName].shown = false;
    }

    virtual void flush() {
        for (int y = 0; y < mEngine->ScreenHeight(); y++)
            for (int x = 0; x < mEngine->ScreenWidth(); x++)
                mEngine->Draw(x, y, olc::BLACK);
    }
    
protected:
    int mOffsetX, mOffsetY;
    olc::PixelGameEngine* mEngine;
    std::map<std::string, Element> mElements;
    std::map<std::string, std::unique_ptr<olc::Sprite>> mSprites;
};