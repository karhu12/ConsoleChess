#include "ChessBoard.hpp"

//Initializes the array with all chesspieces in their starting places
ChessBoard::ChessBoard() {
    mBoard = {{
        ChessPiece(Piece::Rook, Piece::Black), ChessPiece(Piece::Knight, Piece::Black),
        ChessPiece(Piece::Bishop, Piece::Black), ChessPiece(Piece::Queen, Piece::Black),
        ChessPiece(Piece::King, Piece::Black), ChessPiece(Piece::Bishop, Piece::Black),
        ChessPiece(Piece::Knight, Piece::Black), ChessPiece(Piece::Rook, Piece::Black),
        ChessPiece(Piece::Pawn, Piece::Black), ChessPiece(Piece::Pawn, Piece::Black),
        ChessPiece(Piece::Pawn, Piece::Black), ChessPiece(Piece::Pawn, Piece::Black),
        ChessPiece(Piece::Pawn, Piece::Black), ChessPiece(Piece::Pawn, Piece::Black),
        ChessPiece(Piece::Pawn, Piece::Black), ChessPiece(Piece::Pawn, Piece::Black),
        ChessPiece(Piece::Tile, Piece::None), ChessPiece(Piece::Tile, Piece::None),
        ChessPiece(Piece::Tile, Piece::None), ChessPiece(Piece::Tile, Piece::None),
        ChessPiece(Piece::Tile, Piece::None), ChessPiece(Piece::Tile, Piece::None),
        ChessPiece(Piece::Tile, Piece::None), ChessPiece(Piece::Tile, Piece::None),
        ChessPiece(Piece::Tile, Piece::None), ChessPiece(Piece::Tile, Piece::None),
        ChessPiece(Piece::Tile, Piece::None), ChessPiece(Piece::Tile, Piece::None),
        ChessPiece(Piece::Tile, Piece::None), ChessPiece(Piece::Tile, Piece::None),
        ChessPiece(Piece::Tile, Piece::None), ChessPiece(Piece::Tile, Piece::None),
        ChessPiece(Piece::Tile, Piece::None), ChessPiece(Piece::Tile, Piece::None),
        ChessPiece(Piece::Tile, Piece::None), ChessPiece(Piece::Tile, Piece::None),
        ChessPiece(Piece::Tile, Piece::None), ChessPiece(Piece::Tile, Piece::None),
        ChessPiece(Piece::Tile, Piece::None), ChessPiece(Piece::Tile, Piece::None),
        ChessPiece(Piece::Tile, Piece::None), ChessPiece(Piece::Tile, Piece::None),
        ChessPiece(Piece::Tile, Piece::None), ChessPiece(Piece::Tile, Piece::None),
        ChessPiece(Piece::Tile, Piece::None), ChessPiece(Piece::Tile, Piece::None),
        ChessPiece(Piece::Tile, Piece::None), ChessPiece(Piece::Tile, Piece::None),
        ChessPiece(Piece::Pawn, Piece::White), ChessPiece(Piece::Pawn, Piece::White),
        ChessPiece(Piece::Pawn, Piece::White), ChessPiece(Piece::Pawn, Piece::White),
        ChessPiece(Piece::Pawn, Piece::White), ChessPiece(Piece::Pawn, Piece::White),
        ChessPiece(Piece::Pawn, Piece::White), ChessPiece(Piece::Pawn, Piece::White),
        ChessPiece(Piece::Rook, Piece::White), ChessPiece(Piece::Knight, Piece::White),
        ChessPiece(Piece::Bishop, Piece::White), ChessPiece(Piece::Queen, Piece::White),
        ChessPiece(Piece::King, Piece::White), ChessPiece(Piece::Bishop, Piece::White),
        ChessPiece(Piece::Knight, Piece::White), ChessPiece(Piece::Rook, Piece::White),
    }};
}

bool ChessBoard::isPosOutOfBounds(const ChessPosition& pos) {
    if ( (pos.x() >= 0 && pos.x() < ChessBoard::board_width) && (pos.y() >= 0 && pos.y() < ChessBoard::board_height) ) {
        return false;
    }
    return true;
}

bool ChessBoard::isValidMove(const ChessPosition& from, const ChessPosition& to, const ChessPiece& with) {
    if (ChessBoard::isPosOutOfBounds(from) || ChessBoard::isPosOutOfBounds(to) || from == to) {
        return false;
    }
    Movement move(from, to);
    for (auto withMove : with.moves()) {
        //If piece has move type that matches the movement we check if its valid
        if (withMove == move.type()) {
            switch (withMove) {
                //Correct by default because it is checked from the move list in movement class
                case Piece::MoveType::LShape:
                    return true;
                case Piece::MoveType::Diagonal:
                    //each direction is powered by two in squareroot to produce positive numbers which are then summed
                    //and divided by two which gives the total movement to diagonal direction
                    if ((sqrt(pow(move.x(),2)) + sqrt(pow(move.y(),2))) / 2 <= with.moveAmount()) {
                        return true;
                    }
                    return false;
                case Piece::MoveType::Horizontal:
                    if (move.x() <= with.moveAmount()) {
                        return true;
                    }
                    return false;
                case Piece::MoveType::Vertical:
                    if (move.y() <= with.moveAmount()) {
                        return true;
                    }
                    return false;
                default:
                    return false;
            }
        }
    }
    return false;
}

void ChessBoard::movePiece(const ChessPosition& from, const ChessPosition& to) {
    
}