// pbitboard.hpp
// for pieces
#ifndef PBITBOARD_HPP_
#define PBITBOARD_HPP_
#include <bitset>
#include <map>
#include "constants.hpp"
#ifndef _U64
#include <cstdint>
typedef std::uint64_t U64;
#define _U64
#endif

constexpr U64 UNIVERSE = 0xffffffffffffffffULL;
constexpr U64 ONE = 1ULL;
constexpr U64 ZERO = 0ULL;

// piece bitboard
// FEN coding:
// black = lower
// white = upper
// top to bottom (far left to far right)
// left shift

class pBitboard
{
public:
    pBitboard(); // constructor
    void setup(std::string FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");


private:
    
    
    /*
    U64 wPawnBoard;
    U64 bPawnBoard;
    U64 wKingBoard;
    U64 bKingBoard;
    U64 wQueenBoard;
    U64 bQueenBoard;
    U64 wBishopBoard;
    U64 bBishopBoard;
    U64 wKnightBoard;
    U64 bKnightBoard;
    U64 wRookBoard;
    U64 bRookBoard;
    // FEN coding:
    // white = upper
    // black = lower
    std::map<char, U64 *> pieces = {
        {'P', &wPawnBoard},
        {'p', &bPawnBoard},
        {'K', &wKingBoard},
        {'k', &bKingBoard},
        {'Q', &wQueenBoard},
        {'q', &bQueenBoard},
        {'N', &wKnightBoard},
        {'n', &bKnightBoard},
        {'R', &wRookBoard},
        {'r', &bRookBoard},
    };
    */
    
    // squareIndex = 8*rankIndex + fileIndex
    U64 m_pieces[(int) COLOR::TOTAL][(int) PIECES::TOTAL];
    std::map<char, U64 *> m_pieceMap = {
        {'K', &m_pieces[(int) COLOR::W][(int) PIECES::KING]}, 
        {'k', &m_pieces[(int) COLOR::B][(int) PIECES::KING]},  
        {'Q', &m_pieces[(int) COLOR::W][(int) PIECES::QUEEN]}, 
        {'q', &m_pieces[(int) COLOR::B][(int) PIECES::QUEEN]}, 
        {'N', &m_pieces[(int) COLOR::W][(int) PIECES::KNIGHT]}, 
        {'n', &m_pieces[(int) COLOR::B][(int) PIECES::KNIGHT]}, 
        {'B', &m_pieces[(int) COLOR::W][(int) PIECES::BISHOP]}, 
        {'b', &m_pieces[(int) COLOR::B][(int) PIECES::BISHOP]}, 
        {'R', &m_pieces[(int) COLOR::W][(int) PIECES::ROOK]}, 
        {'r', &m_pieces[(int) COLOR::B][(int) PIECES::ROOK]}, 
        {'P', &m_pieces[(int) COLOR::W][(int) PIECES::PAWN]}, 
        {'p', &m_pieces[(int) COLOR::B][(int) PIECES::PAWN]}
    };
    
    const std::map<char, int> m_values = {
        {'K', 100},
        {'k', -100},
        {'Q', 10},
        {'q', -10},
        {'R', 5},
        {'r', -5},
        {'N', 3},
        {'n', -3},
        {'B', 3},
        {'b', -3},
        {'P', 1},
        {'p', -1},
        
    };

    int m_activeColor = 0;
    U64 m_board[2] = {ZERO, ZERO}; // TODO: IMPLEMENT FILL
    // 0 = white, 1 = black
};


/*
bitboard repr:

far left->  00000000
            00000000
            00000000
            00000000
            00000000
            00000000
            00000000
            00000000 <- far right


far left->  0000 0000
            0000 0000
            0000 0000
            0000 0000
            0000 0000
            0000 0000
            0000 0000
            0000 0000 <- far right
*/

#endif
