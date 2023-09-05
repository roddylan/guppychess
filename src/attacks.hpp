// attacks.hpp
#include "bitboard.hpp"
#include "pbitboard.hpp"

#ifndef _U64 
#define _U64
#include <stdint.h>
typedef std::uint64_t U64;
#endif

// TODO: maybe change some of these to inlines
// PAWNS:
// fills used to determine closed, half open, and open files
U64 wFrontFill(U64 wPawns); // fill space infront of white pawns
U64 wRearFill(U64 wPawns);  // fill space behind white pawns

U64 bFrontFill(U64 bPawns); // fill space infront of black pawns
U64 bRearFill(U64 bPawns);  // fill space behind black pawns

U64 wFileFill(U64 wPawns); // fill files w/ white pawn
U64 bFileFill(U64 bPawns); // fill files w/ black pawn

// SPANS (fill starting 1 further in dir of fill)
// Pawns still member of their frontspan have at least one pawn behind on the same file
// Pawns still member of their rearspan have at least one pawn in front on the same file
// All pawns which are member of the opponent frontspans (or frontfill) have a mechanical obstruction and are unfree
U64 wFrontSpans(U64 wPawns);
U64 bFrontSpans(U64 bPawns);
U64 wRearSpans(U64 wPawns);
U64 bRearSpans(U64 bPawns);

// INTERSPAN - span1 & span2

// STOP SQUARES - push move targets for pawns
U64 wStop(U64 wPawns);
U64 bStop(U64 bPawns);
// TELESTOP SQUARES - frontspan - stop squares
U64 wTelestops(U64 wPawns);
U64 bTelestops(U64 bPawns);

// ATTACK SPANS
U64 wRightAttackFrontSpans (U64 wPawns);
U64 wLeftAttackFrontSpans (U64 wPawns);
U64 bRightAttackFrontSpans (U64 bPawns);
U64 bLeftAttackFrontSpans (U64 bPawns);

U64 wRightAttackRearSpans (U64 wPawns);
U64 wLeftAttackRearSpans (U64 wPawns);
U64 bRightAttackRearSpans (U64 bPawns);
U64 bLeftAttackRearSpans (U64 bPawns);

/*
pawn is not member of own west or east attack filefills -> pawn is half-isolated
pawn is not member of the union of own east and west attack filefills -> pawn is isolated.
pawn is not member of the union of all opponent front pawn- and attack-spans -> it is a passed pawn
*/