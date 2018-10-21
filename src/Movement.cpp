#include "Movement.hpp"

const std::vector<Movement> Movement::LShapeMoves = {
    Movement(1, -2),
    Movement(-1, -2),
    Movement(-2, -1),
    Movement(2, -1),
    Movement(-2, 1),
    Movement(2, 1),
    Movement(-1, 2),
    Movement(1, 2)
};

Piece::MoveType Movement::type() const {
    //Check if move is LShape
    for (auto move : Movement::LShapeMoves) {
        if (move.x() == this->x() && move.y() == this->y()) {
            return Piece::MoveType::LShape;
        }
    }
    //Check if move is diagonal BEFORE vertical and horizontal
    if (sqrt(pow(this->x(), 2)) == sqrt(pow(this->y(), 2))) {
        return Piece::MoveType::Diagonal;
    }
    //Check if move is Vertical
    if (this->x() == 0 && (this->y() > 0 || this->y() < 0)) {
        return Piece::MoveType::Vertical;
    }
    //Check if move is Horizontal
    if (this->y() == 0 && (this->x() > 0 || this->x() < 0)) {
        return Piece::MoveType::Horizontal;
    }
    return Piece::MoveType::Invalid;
}