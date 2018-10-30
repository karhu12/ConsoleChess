#define OLC_PGE_APPLICATION
#include <Ui.hpp>
#include <Application.hpp>

/*
Olc Pixel Game Engine used in this project.
Created by OneLoneCoder
*/

int main() {
    Application app;
    if (app.Construct(512, 512, 1, 1))
        app.Start();
    return 0;
}