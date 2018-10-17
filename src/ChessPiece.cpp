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
            mMoves.diagonal = true;
            mMoves.horizontal = true;
            mMoves.vertical = true;
            break;
        case Piece::Queen:
            mMoveAmount = 7;
            mMoves.diagonal = true;
            mMoves.horizontal = true;
            mMoves.vertical = true;
            break;
        case Piece::Bishop:
            mMoveAmount = 7;
            mMoves.diagonal = true;
            break;
        case Piece::Knight:
            mMoveAmount = 1;
            mMoves.LShape = true;
            break;
        case Piece::Pawn:
            mMoveAmount = 2;
            mMoves.vertical = true;
            break;
        case Piece::Rook:
            mMoveAmount = 7;
            mMoves.horizontal = true;
            mMoves.vertical = true;
            break;
        default:
            mMoveAmount = 0;
    }
}