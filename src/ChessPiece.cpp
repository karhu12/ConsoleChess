#include "ChessPiece.hpp"

ChessPiece::ChessPiece(Piece::Type type, Piece::Side side) {
    mPieceType = type;
    mPieceSide = side;
    switch (mPieceType) {
        case Piece::Tile:
            mMoveAmount = 0;
            break;
        case Piece::King:
            mMoveAmount = 1;
            mMoves.push_back(Piece::MoveType::Diagonal);
            mMoves.push_back(Piece::MoveType::Horizontal);
            mMoves.push_back(Piece::MoveType::Vertical);
            break;
        case Piece::Queen:
            mMoveAmount = 7;
            mMoves.push_back(Piece::MoveType::Diagonal);
            mMoves.push_back(Piece::MoveType::Horizontal);
            mMoves.push_back(Piece::MoveType::Vertical);
            break;
        case Piece::Bishop:
            mMoveAmount = 7;
            mMoves.push_back(Piece::MoveType::Diagonal);
            break;
        case Piece::Knight:
            mMoveAmount = 1;
            mMoves.push_back(Piece::MoveType::LShape);
            break;
        case Piece::Pawn:
            mMoveAmount = 2;
            mMoves.push_back(Piece::MoveType::Vertical);
            break;
        case Piece::Rook:
            mMoveAmount = 7;
            mMoves.push_back(Piece::MoveType::Horizontal);
            mMoves.push_back(Piece::MoveType::Vertical);
            break;
        default:
            mMoveAmount = 0;
    }
}