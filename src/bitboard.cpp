#include "bitboard.hpp"

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