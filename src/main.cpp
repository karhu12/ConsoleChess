#include <ChessGame.hpp>

int main() {
    //Check-mate
    ChessGame g("E2 E4 E7 E5 F2 F4 F8 C5 F4 E5 D8 H4 E1 E2 H4 E4");
    g.draw();

    //Check-mate
    ChessGame g2("D2 D4 G8 F6 B1 D2 E7 E5 D4 E5 F6 G4 H2 H3 G4 E3 F2 E3 D8 H4 G2 G3 H4 G3");
    g2.draw();

    //Check-mate
    ChessGame g3("E2 E4 E7 E5 G1 F3 D7 D6 F1 C4 H7 H6 B1 C3 C8 G4 F3 E5 G4 D1 C4 F7 E8 E7 C3 D5");
    g3.draw();
    
    //Check-mate
    ChessGame g4("E2 E4 E7 E5 F2 F4 E5 F4 G1 F3 G7 G5 F1 C4 F7 F6 F3 G5 F6 G5 D1 H5 E8 E7 H5 G5 E7 E8 G5 E5");
    g4.draw();

    //Check-mate
    ChessGame g5("E2 E4 B8 C6 G2 G4 C6 D4 G1 E2 D4 F3 ");
    g5.draw();
    
    //Check-mate
    ChessGame g6("E2 E4 E7 E5 G1 F3 B8 C6 F1 C4 C6 D4 F3 E5 D8 G5 E5 F7 G5 G2 H1 F1 G2 E4 C4 E2 D4 F3");
    g6.draw();

    //Check-mate
    ChessGame g7("E2 E4 E7 E5 G1 H3 G8 F6 F1 C4 F6 E4 F2 F3 D8 H4 H3 F2 H4 F2");
    g7.draw();

    //Check-mate
    ChessGame g8("E2 E4 E7 E5 G1 F3 B8 C6 F1 B5 A7 A6 B5 C4 G8 F6 F3 G5 F8 C5 G5 F7 C5 F2 E1 F2 F6 E4 F2 E3 D8 E7 F7 H8 D7 D5 C4 D3 E7 G5 E3 E2 G5 G2 E2 E3 G2 F2");
    g8.draw();

    return 0;
}