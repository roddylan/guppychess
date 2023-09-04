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


U64 bitboard::bFlipVertical(U64 bb) {
    const U64 k1 = 0x00FF00FF00FF00FF;
    const U64 k2 = 0x0000FFFF0000FFFF;
    bb = ((bb >> 8) & k1) | ((bb & k1) << 8);
    bb = ((bb >> 16) & k2) | ((bb & k2) << 16);
    bb = (bb >> 32) | (bb << 32);
    return bb;
}

U64 bitboard::bFlipHorizontal(U64 bb) {
    const U64 k1 = 0x5555555555555555; // 1 . 1 . 1 . 1 .
    const U64 k2 = 0x3333333333333333; // 1 1 . . 1 1 . .
    const U64 k4 = 0x0F0F0F0F0F0F0F0F; // 1 1 1 1 . . . . 

    bb = ((bb >> 1) & k1) + 2*(bb & k1);
    bb = ((bb >> 2) & k2) + 4*(bb & k2);
    bb = ((bb >> 4) & k4) + 16*(bb & k4);
    return bb;

}


U64 bitboard::bFlipDiagonalA1H8(U64 bb) {
    const U64 k1 = 0x5500550055005500; // 1 . 1 . 1 . 1 .
    const U64 k2 = 0x3333000033330000; // 1 1 . . 1 1 . . x2
                                       // . . . . . . . . x2
                                       //                 x2
    const U64 k4 = 0x0F0F0F0F00000000; // 1 1 1 1 . . . . x4
                                       // . . . . . . . . x4

    U64 temp = k4 & (bb ^ (bb << 28));
    bb ^= temp ^ (temp >> 28);
    temp = k2 & (bb ^ (bb << 14));
    bb ^= temp ^ (temp >> 14);
    temp = k1 & (bb ^ (bb << 7));
    bb ^= bb ^ (temp >> 7);
    /*
    t  = k2 & (x ^ (x << 14));
    x ^=       t ^ (t >> 14) ;
    t  = k1 & (x ^ (x <<  7));
    x ^=       t ^ (t >>  7) ;
    
    */
}

U64 bitboard::bFlipDiagonalH1A8(U64 bb) {
    const U64 k1 = 0xAA00AA00AA00AA00; // . 1 . 1 . 1 . 1
    const U64 k2 = 0xCCCC0000CCCC0000; // . . 1 1 . . 1 1
    const U64 k4 = 0xF0F0F0F00F0F0F0F; // . . . . 1 1 1 1 x4
                                       // 1 1 1 1 . . . . x4

    U64 temp = bb ^ (bb << 36);
    bb ^= k4 & (temp ^ (bb >> 36));
    temp = k2 & (bb ^ (bb << 18));
    bb ^= temp ^ (temp >> 18);
    temp = k1 & (bb ^ (bb << 9));
    bb ^= temp ^ (temp >> 9);
    return bb;

}



U64 bitboard::bReversal(U64 bb) {
    return bitboard::bFlipHorizontal(bitboard::bFlipVertical(bb));
    
    /*

    const U64 h1 = 0x5555555555555555; // 1 . 1 . 1 . 1 .
    const U64 h2 = 0x3333333333333333; // 1 1 . . 1 1 . .
    const U64 h4 = 0x0F0F0F0F0F0F0F0F; // 1 1 1 1 . . . .

    const U64 v1 = 0x00FF00FF00FF00FF; // 1 1 1 1 1 1 1 1
                                       // . . . . . . . . 
                                       //                 x4
    
    const U64 v2 = 0x0000FFFF0000FFFF; // 1 1 1 1 1 1 1 1 x2
                                       // . . . . . . . . x2
                                       //                 x2

    bb = ((bb >> 1) & h1) | ((bb & h1) << 1);
    bb = ((bb >> 2) & h2) | ((bb & h2) << 2);
    bb = ((bb >> 4) & h4) | ((bb & h4) << 4);
    bb = ((bb >> 8) & v1) | ((bb & v1) << 8);
    bb = ((bb >> 16) & v2) | ((bb & v2) << 16);
    bb = (bb >> 32) | (bb << 32);
    
    return bb;

    */
}