// bitboard.h
#include <bitset>
#include <map>
#ifndef _U64
#include <cstdint>
typedef std::uint64_t U64;
#define _U64
#endif
// position bitboard
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

protected:
    // const int size = 64;
    // static std::bitset<64> wPawnBoard;
    // static std::bitset<64> bPawnBoard;
    // static std::bitset<64> wKingBoard;
    // static std::bitset<64> bKingBoard;
    // static std::bitset<64> wQueenBoard;
    // static std::bitset<64> bQueenBoard;
    // static std::bitset<64> wBishopBoard;
    // static std::bitset<64> bBishopBoard;
    // static std::bitset<64> wKnightBoard;
    // static std::bitset<64> bKnightBoard;
    // static std::bitset<64> wRookBoard;
    // static std::bitset<64> bRookBoard;
    
    // static std::map<char, std::bitset<64>> pieces;

    // TODO: convert to U64
    std::bitset<64> wPawnBoard;
    std::bitset<64> bPawnBoard;
    std::bitset<64> wKingBoard;
    std::bitset<64> bKingBoard;
    std::bitset<64> wQueenBoard;
    std::bitset<64> bQueenBoard;
    std::bitset<64> wBishopBoard;
    std::bitset<64> bBishopBoard;
    std::bitset<64> wKnightBoard;
    std::bitset<64> bKnightBoard;
    std::bitset<64> wRookBoard;
    std::bitset<64> bRookBoard;
    // FEN coding:
    // white = upper
    // black = lower
    std::map<char, std::bitset<64> *> pieces = {
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
    
    const std::map<char, int> values = {
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

    int activeColor = 0;
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
