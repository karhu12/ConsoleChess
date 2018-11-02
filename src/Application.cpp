#include "Application.hpp"
#include "ChessUi.hpp"
#include "LoginUi.hpp"

Application::Application() {
    mState = State::Login;
	sAppName = "Console Chess";
}

bool Application::OnUserCreate() {
    mUi = std::make_unique<LoginUi>(this);
    return true;
}

bool Application::OnUserUpdate(float fElapsedTime)  {
    static std::string start, end, user;
    char ch;
    switch (mState) {
        case State::Login:
            mUi->draw();
            if (GetMouse(0).bPressed) {
                start = mUi->clickedElement();
                if (start == "Play offline") {
                    mState = State::Game;
                    mGame = std::make_unique<ChessGame>(Player(user, Piece::Side::White), Player("Opponent", Piece::Side::Black));
                    //mUi.release();
                    mUi = std::make_unique<ChessUi>(this, *mGame);
                }
            }
            //Allow player to join new match
            /*
            mState = State::Game;*/
            break;
        case State::Game:
            
            mUi->draw(50, 50);
            if (GetMouse(0).bPressed) {
                start = mUi->clickedElement();
            }
            else if (GetMouse(0).bReleased) {
                end = mUi->clickedElement();
                for (int y = 0; y < ScreenHeight(); y++)
                    for (int x = 0; x < ScreenWidth(); x++)
                        Draw(x, y, olc::BLACK);
                        
                DrawString(ScreenWidth() / 3, 5, mGame->moveAction(start, end));
            }
            break;
        default:
            break;
    }
    return true;
}

void Application::getInput(std::string& target) {
    for (int i = 0; i <= olc::Key::Z; i++) {
        if (GetKey((olc::Key)i).bPressed)
            if (GetKey(olc::SHIFT).bHeld)
                target += (char)('A' + i);
            else
                target += (char)('a' + i);
    }
    for (int i = olc::Key::K0; i <= olc::Key::K9; i++) {
        if (GetKey((olc::Key)i).bPressed)
            target += (char)('0' + (i - olc::Key::K0));
    }
    if (GetKey(olc::SPACE).bPressed)
        target += " ";
    if (GetKey(olc::BACK).bPressed || GetKey(olc::DEL).bPressed)
        target.pop_back();
    
}