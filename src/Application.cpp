#include "Application.hpp"
#include "ChessUi.hpp"

Application::Application() {
    mState = State::Login;
	sAppName = "Console Chess";
}

bool Application::OnUserCreate() {
    return true;
}

bool Application::OnUserUpdate(float fElapsedTime)  {
    static std::string start, end, user;
    char ch;
    switch (mState) {/*
        case State::Login:
            getInput(user);
            DrawString(15, 15, user);
            if (GetKey(olc::ENTER).bPressed) {
                //Check if valid user from db etc.
                mState = State::Browse;
            }
            break;*/
        case State::Login:
            //Allow player to join new match
            mGame = std::make_unique<ChessGame>(Player(user, Piece::Side::White), Player("Opponent", Piece::Side::Black));
            mUi = std::make_unique<ChessUi>(this, *mGame);
            mState = State::Game;
            break;
        case State::Game:
            
            mUi->draw(50, 50);
            if (GetMouse(0).bPressed) {
                ChessUi temp(*mUi, *mGame);
                start = temp.getChessPositionAtMouse(50, 50);
            }
            else if (GetMouse(0).bReleased) {
                ChessUi temp(*mUi, *mGame);
                end = temp.getChessPositionAtMouse(50, 50);
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