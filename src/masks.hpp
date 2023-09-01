// masks.hpp
#pragma once
#ifndef MASKS_HPP_
#define MASKS_HPP_
#ifndef _U64
#include <cstdint>
typedef std::uint64_t U64;
#define _U64
#endif

namespace masks {
    const U64 RANKS[] = {
        0xFF,               // 1
        0xFF00,             // 2
        0xFF0000,           // 3
        0xFF000000,         // 4
        0xFF00000000,       // 5
        0xFF0000000000,     // 6
        0xFF000000000000,   // 7
        0xFF00000000000000  // 8
    };

    const U64 FILES[] = {
        0x0101010101010101, // A
        0x0202020202020202, // B
        0x0404040404040404, // C
        0x0808080808080808, // D
        0x1010101010101010, // E
        0x2020202020202020, // F
        0x4040404040404040, // G
        0x8080808080808080  // H
    };

    const U64 CLEAR_RANK[] = {
        0xFFFFFFFFFFFFFF00, // 1
        0xFFFFFFFFFFFF00FF, // 2
        0xFFFFFFFFFF00FFFF, // 3
        0xFFFFFFFF00FFFFFF, // 4
        0xFFFFFF00FFFFFFFF, // 5
        0xFFFF00FFFFFFFFFF, // 6
        0xFF00FFFFFFFFFFFF, // 7
        0x00FFFFFFFFFFFFFF  // 8
    };

    const U64 CLEAR_FILE[] = {
        0xFEFEFEFEFEFEFEFE, // A
        0xFDFDFDFDFDFDFDFD, // B
        0xFBFBFBFBFBFBFBFB, // C
        0xF7F7F7F7F7F7F7F7, // D
        0xEFEFEFEFEFEFEFEF, // E
        0xDFDFDFDFDFDFDFDF, // F
        0xBFBFBFBFBFBFBFBF, // G
        0x7F7F7F7F7F7F7F7F  // H
    };

}

#endif