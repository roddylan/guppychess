// pbitboard.cpp
// for pieces
#include "pbitboard.hpp"
#ifndef _U64
#include <cstdint>
typedef std::uint64_t U64;
#define _U64
#endif
// bitboard::starting {
//     {"wp", 65280},
//     {"bp", 71776119061217280},
//     {"wk"}
// }

// FEN coding:
// black = lower
// white = upper



pBitboard::pBitboard() {
    setup();
}

// std::map<char, std::bitset<64>> pBitboard::pieces {
    
// };

void pBitboard::setup(std::string FEN) {
    // "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"
    // int i = 0;
    // std::bitset<64> currentPiece(0x8000000000000000);


    
    int i = 0;
    // little endian
    // 0000 0001 A
    // 0000 0010 B ...
    // 1000 0000 H

    // 0x00000000000000FF -> 1 RANK
    // 0xFF00000000000000 -> 8 RANK
    // LSF
    
    std::bitset<64> firstPiece(0x0000000000000001);
    
    int rankIdx = 7;
    int fileIdx = 0;

    while (FEN[i] && FEN[i] != ' ') {

        if (FEN[i] >= 48 && FEN[i] <= 57) {
            int temp = (FEN[i] - '0');
            fileIdx += temp;
            // currentPiece <<= temp;
        }
        else {
            if (FEN[i] == '/') {
                rankIdx -= 1;
                fileIdx = 0;
                i++;
                // continue;
            }
            else {
                int squareIdx = 8*rankIdx + fileIdx;
                *m_pieceMap[FEN[i]] |= (firstPiece << squareIdx).to_ullong();
                
                fileIdx += 1;
                // currentPiece <<= 1;
                i++;
            }
        }
    }
    
    int field = 0;
    for (i; i < FEN.length(); i++) {
        if (FEN[i] == ' ') {
            field++;
            continue;
        }
        if (field == 1) {
            // active color
            m_activeColor = ((int) FEN[i]) % 2;
        }
        else if (field == 2) {
            // casting rights
            // upper case first (white)
            // "k" -> kingside castling; "q" -> queenside castling; "-" no castling
            // lower case after (black)
        }
        else if (field == 3) {
            // possible en passant targets
            
        }

    }

    
    
    return;
}