// constants.hpp
#pragma once
#ifndef _U64
#include <cstdint>
typedef std::uint64_t U64;
#define _U64
#endif

constexpr U64 ONE = 0ULL;

enum class SQUARES : int {
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8,
    TOTAL,
    EMPTY = -1
};


// << -> +
// >> -> -
enum class DIRECTION : int {
    UP = 8,
    DOWN = -8,
    LEFT = 1,
    RIGHT = -1,
    D_UP_LEFT = 7,
    D_UP_RIGHT = 9,
    D_DOWN_LEFT = -9,
    D_DOWN_RIGHT = -7
};

enum class COMMON : U64 {
    H1A8_DIAG = 0x8040201008040201,
    A1H8_DIAG = 0x0102040810204080,
    LIGHT = 0x55AA55AA55AA55AA,
    DARK = 0xAA55AA55AA55AA55
};

enum class COLOR : int {
    W,
    B,
    TOTAL,
    BOTH = 2
};

enum class PIECES : int {
    KING,
    QUEEN,
    KNIGHT,
    BISHOP,
    ROOK,
    PAWN,
    TOTAL,
    EMPTY = 6
};

enum class CASTLING_RIGHTS : int {
    KING_W = 1,
    QUEEN_W = 2,
    KING_B = 4,
    QUEEN_B = 8
};