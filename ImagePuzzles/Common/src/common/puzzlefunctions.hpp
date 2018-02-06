#ifndef PUZZLEFUNCTIONS_HPP
#define PUZZLEFUNCTIONS_HPP

#include "puzzlepixmap.h"
#include "puzzleinfo.hpp"


/* ****************************************************************************
 * FUNCTION POINTER DEFINITIONS
 * ***************************************************************************/
///
/// \brief
///
/// Signature:
///     const PuzzleInfo::ErrorCodes getErrorCode();
///
#define GetErrorCode(name) \
    PuzzleInfo::ErrorCodes (name) \
    (void)

typedef GetErrorCode(*getErrorCode_t);

///
/// \brief
///
/// Signature:
///     PuzzleGUID getPuzzleGUID();
///
#define GetPuzzleGUID(name) \
    PuzzleGUID (name) \
    (void)
typedef GetPuzzleGUID(*getPuzzleGUID_t);

///
/// \brief
///
/// Signature:
///     PuzzleInfo* getPuzzleInfo()
///
#define GetPuzzleInfo(name) \
    PuzzleInfo* (name) \
    (void)
typedef GetPuzzleInfo(*getPuzzleInfo_t);

///
/// \brief
///
/// Signature:
///     void run (const char* const, const void* const);
///
#define Run(name) \
    PuzzlePixmap* (name) \
    (void* parameters, PuzzleInfo::ImplementationType implementationType)
typedef Run(*run_t);

#endif // PUZZLEFUNCTIONS_HPP

