// attacks.cpp
#include "attacks.hpp"

// PAWNS
// FILL
U64 wFrontFill(U64 wPawns) { return bitboard::bNFill(wPawns); } // fill space infront of white pawns
U64 wRearFill(U64 wPawns) { return bitboard::bSFill(wPawns); }  // fill space behind white pawns

U64 bFrontFill(U64 bPawns) { return bitboard::bSFill(bPawns); } // fill space infront of black pawns
U64 bRearFill(U64 bPawns) { return bitboard::bNFill(bPawns); }  // fill space behind black pawns

U64 wFileFill(U64 wPawns) { return bitboard::bFillFile(wPawns); } // fill files w/ white pawn
U64 bFileFill(U64 bPawns) { return bitboard::bFillFile(bPawns); } // fill files w/ black pawn

// SPANS (fill starting 1 further in dir of fill)
U64 wFrontSpans(U64 wPawns) { return wFrontFill(wStop(wPawns)); }
U64 bFrontSpans(U64 bPawns) { return bFrontFill(bStop(bPawns)); }
U64 wRearSpans(U64 wPawns) { return bitboard::shiftDownOne(bitboard::bSFill(wPawns)); }
U64 bRearSpans(U64 bPawns) { return bitboard::shiftUpOne(bitboard::bNFill(bPawns)); }
/*
old:
U64 wFrontSpans(U64 wPawns) { return bitboard::shiftUpOne(bitboard::bNFill(wPawns)); }
U64 bFrontSpans(U64 bPawns) { return bitboard::shiftDownOne(bitboard::bSFill(bPawns)); }
*/


// STOPS
U64 wStop(U64 wPawns) { return bitboard::shiftUpOne(wPawns); }
U64 bStop(U64 bPawns) { return bitboard::shiftDownOne(bPawns); }
// TELESTOPS
U64 wTelestops(U64 wPawns) { return wFrontSpans(wStop(wPawns)) ^ wStop(wPawns); }
U64 bTelestops(U64 bPawns) { return bFrontSpans(bStop(bPawns)) ^ bStop(bPawns); }

// ATTACK SPANS
U64 wRightAttackFrontSpans (U64 wPawns) { return bitboard::shiftRightOne(wFrontSpans(wPawns)); }
U64 wLeftAttackFrontSpans (U64 wPawns) { return bitboard::shiftLeftOne(wFrontSpans(wPawns)); }
U64 bRightAttackFrontSpans (U64 bPawns) { return bitboard::shiftRightOne(bFrontSpans(bPawns)); }
U64 bLeftAttackFrontSpans (U64 bPawns) { return bitboard::shiftLeftOne(bFrontSpans(bPawns)); }

U64 wRightAttackRearSpans (U64 wPawns) { return bitboard::shiftRightOne(wRearSpans(wPawns)); }
U64 wLeftAttackRearSpans (U64 wPawns) { return bitboard::shiftLeftOne(wRearSpans(wPawns)); }
U64 bRightAttackRearSpans (U64 bPawns) { return bitboard::shiftRightOne(bRearSpans(bPawns)); }
U64 bLeftAttackRearSpans (U64 bPawns) { return bitboard::shiftLeftOne(bRearSpans(bPawns)); }
