// bitboard.cpp
#include "bitboard.hpp"

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
    int i = 0;
    std::bitset<64> currentPiece(0x8000000000000000);
    

    while (FEN[i] && FEN[i] != ' ') {

        if (FEN[i] >= 48 && FEN[i] <= 57) {
            int temp = (FEN[i] - '0');
            currentPiece >>= temp;
        }
        else {
            if (FEN[i] == '/') {
                i++;
                continue;
            }
            else {
                *pieces[FEN[i]] ^= currentPiece;
                currentPiece >>= 1;
                i++;
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
                activeColor = FEN[i] % 2;
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
    }

    // (length - i) to (length - 1)
    return;
}
