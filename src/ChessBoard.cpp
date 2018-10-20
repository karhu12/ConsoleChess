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

//Validates position is inside the board
bool ChessBoard::isPosOutOfBounds(const ChessPosition& pos) {
    if ( (pos.x() >= 0 && pos.x() < ChessBoard::board_width) && (pos.y() >= 0 && pos.y() < ChessBoard::board_height) ) {
        return false;
    }
    return true;
}

//Function validates if moving a piece to a neutral tile position is valid
//Function also checks if there is collision between the movement
bool ChessBoard::isValidMove(const ChessPosition& from, const ChessPosition& to) {
    ChessPiece pieceWith(at(from)), pieceTo(at(to));
    if (ChessBoard::isPosOutOfBounds(from) || ChessBoard::isPosOutOfBounds(to) || from == to) {
        return false;
    }
    Movement move(from, to);
    for (auto withMove : pieceWith.moves()) {
        //If piece has move type that matches the movement we check if its valid
        if (withMove == move.type()) {
            switch (withMove) {
                //Correct by default because it is checked from the move list in movement class
                case Piece::MoveType::LShape:
                    if (checkCollision(from, to, true)) {
                        return false;
                    }
                    return true;
                case Piece::MoveType::Diagonal:
                    //each direction is powered by two in squareroot to produce positive numbers which are then summed
                    //and divided by two which gives the total movement to diagonal direction
                    if ((sqrt(pow(move.x(),2)) + sqrt(pow(move.y(),2))) / 2 <= pieceWith.moveAmount()) {
                        if (checkCollision(from, to, true)) {
                            return false;
                        }
                        return true;
                    }
                    return false;
                case Piece::MoveType::Horizontal:
                    if (move.x() <= pieceWith.moveAmount()) {
                        if (checkCollision(from, to, true)) {
                            return false;
                        }
                        return true;
                    }
                    return false;
                case Piece::MoveType::Vertical:
                    if (move.y() <= pieceWith.moveAmount()) {
                        if (checkCollision(from, to, true)) {
                            return false;
                        }
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

//Replaces piece at "to" position with "from" and creates new tile at "from" position
void ChessBoard::movePiece(const ChessPosition& from, const ChessPosition& to) {
    mBoard[ChessBoard::indexAt(to)] = at(from);
    mBoard[ChessBoard::indexAt(from)] = ChessPiece(Piece::Type::Tile, Piece::Side::None);
    //If it is pawns first movement its speed will be reduced to one tile per movement after the move
    if (at(to).type() == Piece::Type::Pawn) {
        if (at(to).moveAmount() == 2) {
            at(to).setMoveAmount(1);
        }
    }
}

//Validates x,y position on board
bool ChessBoard::isValidPos(int x, int y) {
    if ( (x >= 0 && x < board_width) && (y >= 0 && y < board_height)) {
        return true;
    } 
    return false;
}

//Function checks collision from movement on board based on the move type
//Currently function assumes the move is correct so that is not checked
bool ChessBoard::checkCollision(const ChessPosition& from, const ChessPosition& to, bool checkEnd) {
    Movement move(from, to);
    //Cant move to where you started
    if (from == to)
        return true;

    int tempX = from.x(), tempY = from.y();
    switch (move.type()) {
        case Piece::MoveType::LShape:
            if (checkEnd ? at(to).side() != Piece::Side::None : false)
                return true;
            return false;
        case Piece::MoveType::Diagonal:
            //Check if the diagonal movement is towards positive x and negative y
            if (move.x() > 0 && move.y() < 0) {
                for (tempX++, tempY--; tempX <= (checkEnd ? to.x() : to.x() - 1) && tempY >= (checkEnd ? to.y() : to.y() + 1); tempX++, tempY--) {
                    if (at(tempX, tempY).side() != Piece::Side::None)
                        return true;
                }
                return false;
            }
            //Check if the diagonal movement is towards positive x and positive y
            else if (move.x() > 0 && move.y() > 0) {
                for (tempX++, tempY++; tempX <= (checkEnd ? to.x() : to.x() - 1) && tempY <= (checkEnd ? to.y() : to.y() - 1); tempX++, tempY++) {
                    if (at(tempX, tempY).side() != Piece::Side::None)
                        return true;
                }
                return false;
            }
            //Check if the diagonal movement is towards negative x and positive y
            else if (move.x() < 0 && move.y() > 0) {
                for (tempX--, tempY++; tempX >= (checkEnd ? to.x() : to.x() + 1) && tempY <= (checkEnd ? to.y() : to.y() - 1); tempX--, tempY++) {
                    if (at(tempX, tempY).side() != Piece::Side::None)
                        return true;
                }
                return false;
            }
            //Check if the diagonal movement is towards negative x and negative y
            else if (move.x() < 0 && move.y() < 0) {
                for (tempX--, tempY--; tempX >= (checkEnd ? to.x() : to.x() + 1) && tempY >= (checkEnd ? to.y() : to.y() + 1); tempX--, tempY--) {
                    if (at(tempX, tempY).side() != Piece::Side::None)
                        return true;
                }
                return false;
            }
            return true;
        case Piece::MoveType::Horizontal:
            //Check if the horizontal movement is towards positive x
            if (move.x() > 0) {
                for (tempX++; tempX <= (checkEnd ? to.x() : to.x() - 1); tempX++) {
                    if (at(tempX, tempY).side() != Piece::Side::None)
                        return true;
                }
            }
            //Check if the horizontal movement is towards negative x
            else if (move.x() < 0) {
                for (tempX--; tempX >= (checkEnd ? to.x() : to.x() + 1); tempX--) {
                    if (at(tempX, tempY).side() != Piece::Side::None)
                        return true;
                }
            }
            return false;
        case Piece::MoveType::Vertical:
            //Check if the vertical movement is towards positive y
            if (move.y() > 0) {
                for (tempY++; tempY <= (checkEnd ? to.y() : to.y() - 1); tempY++) {
                    if (at(tempX, tempY).side() != Piece::Side::None)
                        return true;
                }
            }
            //Check if the vertical movement is towards negative y
            else if (move.y() < 0) {
                for (tempY--; tempY >= (checkEnd ? to.y() : to.y() + 1); tempY--) {
                    if (at(tempX, tempY).side() != Piece::Side::None)
                        return true;
                }
            }
            return false;
        default:
            return true;
    }
}

bool ChessBoard::isValidEat(const ChessPosition& from, const ChessPosition& to) {
    ChessPiece pieceWith(at(from)), pieceTo(at(to));
    if (ChessBoard::isPosOutOfBounds(from) || ChessBoard::isPosOutOfBounds(to) || from == to || pieceWith.side() == pieceTo.side()) {
        return false;
    }
    Movement move(from, to);
    if (pieceWith.type() == Piece::Type::Pawn) {
        if (pieceWith.side() == Piece::Side::White) {
            if ( (from.x() + 1 == to.x() || from.x() - 1 == to.x()) && to.y() + 1 == from.y()) {
                return true;
            }
            return false;
        }
        else {
            if ( (from.x() + 1 == to.x() || from.x() - 1 == to.x()) && to.y() - 1 == from.y()) {
                return true;
            }
            return false;
        }
    }
    else {
        for (auto withMove : pieceWith.moves()) {
            //If piece has move type that matches the movement we check if its valid
            if (withMove == move.type()) {
                switch (withMove) {
                    //Correct by default because it is checked from the move list in movement class
                    case Piece::MoveType::LShape:
                        if (checkCollision(from, to, false)) {
                            return false;
                        }
                        return true;
                    case Piece::MoveType::Diagonal:
                        //each direction is powered by two in squareroot to produce positive numbers which are then summed
                        //and divided by two which gives the total movement to diagonal direction
                        if ((sqrt(pow(move.x(),2)) + sqrt(pow(move.y(),2))) / 2 <= pieceWith.moveAmount()) {
                            if (checkCollision(from, to, false)) {
                                return false;
                            }
                            return true;
                        }
                        return false;
                    case Piece::MoveType::Horizontal:
                        if (move.x() <= pieceWith.moveAmount()) {
                            if (checkCollision(from, to, false)) {
                                return false;
                            }
                            return true;
                        }
                        return false;
                    case Piece::MoveType::Vertical:
                        if (move.y() <= pieceWith.moveAmount()) {
                            if (checkCollision(from, to, false)) {
                                return false;
                            }
                            return true;
                        }
                        return false;
                    default:
                        return false;
                }
            }
        }
    }
    return false;
}