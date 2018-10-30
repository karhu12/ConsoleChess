#pragma once
#include <Application.hpp>
#include <vector>

class Ui {
public:
    Ui(olc::PixelGameEngine * engine) : mEngine(engine) {}

    virtual void draw(int x, int y) = 0;
    
protected:
    olc::PixelGameEngine* mEngine;
};