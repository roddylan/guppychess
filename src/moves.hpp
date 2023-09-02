// moves.hpp
#ifndef MOVES_HPP_
#define MOVES_HPP_
#include "constants.hpp"

class Move {
    public:
        Move();
        PIECES getPieceType() const;
        COLOR getPieceColor() const;
        PIECES getCapturedPieceType() const;
        COLOR getCapturedPieceColor() const;
        // from square
        // to square

        // U64 upperBits =  C64(~1) << sq;
        // U64 lowerBits = (C64(1 ) << sq) - 1);

    private:
        
};








#endif