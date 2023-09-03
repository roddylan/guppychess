#include "bitboard.hpp"
#include <bit>
int bitboard::bCount(U64 bb) {
    // hamming weight
    // Brian Kernighan's way
    int count = 0;
    
    while (bb) {
        count++;
        bb &= bb - 1; // reset LS1B
    }
    
    return count;
}
// maybe use multiple count methods (Kernighan's for piece bboard, alt for attack etc.)
/* 
// ALTERNATIVE bCount: 
const U64 k1 = 0x5555555555555555;
const U64 k2 = 0x3333333333333333;
const U64 k4 = 0x0f0f0f0f0f0f0f0f;
const U64 kf = 0x0101010101010101;
int bitboard::bCount(U64 bb) {
    bb = bb - ((bb >> 1) & k1);
    bb = (bb & k2) + ((x >> 2) & k2);
    bb = (bb + (bb >> 4)) & k4;
    bb = (bb * kf) >> 56;
    return (int) bb;
}
*/

 
int bitboard::bScanF(U64 bb) {
    // LS1B
    return std::__countr_zero(bb);
}


int bitboard::bScanR(U64 bb) {
    // MS1B
    return std::__countl_zero(bb);
}

