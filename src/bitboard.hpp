#ifndef BITBOARD_HPP_
#define BITBOARD_HPP_
#include "masks.hpp"
#include "constants.hpp"
#ifndef _CMATH
#define _CMATH
#include <cmath>
#endif
#ifndef _U64

#include <cstdint>
typedef std::uint64_t U64;
#define _U64
#endif

// constexpr U64 UNIVERSE = 0xffffffffffffffffULL;
// constexpr U64 ONE = 1ULL;
// constexpr U64 ZERO = 0ULL;


namespace bitboard {
    // common shifts
    inline U64 shiftDownOne(U64 bb) { return ((bb >> (std::abs((int) DIRECTION::DOWN)))); }
    inline U64 shiftUpOne(U64 bb) { return ((bb << (int) DIRECTION::UP)); }
    inline U64 shiftRightOne(U64 bb) { return ((bb << (int) DIRECTION::RIGHT)) & (U64) masks::CLEAR_FILE[0]; }
    inline U64 shiftLeftOne(U64 bb) { return ((bb >> (std::abs((int) DIRECTION::LEFT)))) & (U64) masks::CLEAR_FILE[7];}
    inline U64 shiftDUpLeftOne(U64 bb) { return ((bb << (int) DIRECTION::D_UP_LEFT)) & (U64) masks::CLEAR_FILE[7]; }
    inline U64 shiftDUpRightOne(U64 bb) { return ((bb << (int) DIRECTION::D_UP_RIGHT)) & (U64) masks::CLEAR_FILE[0]; }
    inline U64 shiftDDownLeftOne(U64 bb) { return ((bb >> (std::abs((int) DIRECTION::D_DOWN_LEFT)))) & (U64) masks::CLEAR_FILE[7]; }
    inline U64 shiftDDownRightOne(U64 bb) { return ((bb >> (std::abs((int) DIRECTION::D_DOWN_RIGHT)))) & (U64) masks::CLEAR_FILE[0]; }


    int bCount(U64 bb);
}


#endif