#ifndef PUZZLE_H
#define PUZZLE_H

#include <QtCore/QLibrary>
#include <QtCore/QString>

#include "common/puzzleinfo.h"


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
    const PuzzleInfo::ErrorCodes (*name) \
    ()
typedef GetErrorCode(getErrorCode_t);

///
/// \brief
///
/// Signature:
///     PuzzleGUID getPuzzleGUID();
///
#define GetPuzzleGUID(name) \
    PuzzleGUID (*name) \
    ()
typedef GetPuzzleGUID(getPuzzleGUID_t);

///
/// \brief
///
/// Signature:
///     PuzzleInfo* getPuzzleInfo()
///
#define GetPuzzleInfo(name) \
    PuzzleInfo* (*name) \
    ()
typedef GetPuzzleInfo(getPuzzleInfo_t);

///
/// \brief
///
/// Signature:
///     void run (const char*);
///
#define Run(name) \
    void (*name) \
    (const char* const)
typedef Run(run_t);


/* ****************************************************************************
 * CLASS DEFINITION
 * ***************************************************************************/
class Puzzle
{
public:
    explicit Puzzle(QString path);
    ~Puzzle();

    Run(run);

public:
    bool isLoaded;

    PuzzleInfo* puzzleInfo;

private:
    GetErrorCode(getErrorCode);
    GetPuzzleGUID(getPuzzleGUID);
    GetPuzzleInfo(getPuzzleInfo);

    QLibrary library;
    PuzzleGUID GUID;
};

#endif // PUZZLE_H
