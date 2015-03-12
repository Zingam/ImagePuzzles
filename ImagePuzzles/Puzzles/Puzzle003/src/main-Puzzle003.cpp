#include <string>
#include <iostream>

#include "header-Puzzle003.h"

#include "common/library.h"
#include "common/puzzleinfo.h"


/* ****************************************************************************
 * GLOBAL VARIABLES
 * ***************************************************************************/
PuzzleInfo puzzleInfo;
static PuzzleInfo::ErrorCodes errorCode = PuzzleInfo::ErrorCodes::NoError;

/* ****************************************************************************
 * EXPORTED FUNCTIONS
 * ***************************************************************************/

///
/// \brief Returns an unique identifier
///
/// The returned value must be "5a5a20a2-f5ef-4d21-9661-0942251e97a8". The
/// application needs to check for this value to identify if the loaded dynamic
/// library is a puzzle. If \return is a correct value the application can
/// load the rest of the functions;
///
/// \returns "5a5a20a2-f5ef-4d21-9661-0942251e97a8"
///
extern "C"
API_EXPORT PuzzleGUID
getPuzzleGUID()
{
    return puzzleGUID;
}

///
/// \brief Returns the last error code
///
/// \returns PuzzleInfo::ErorrCodes
///
extern "C"
API_EXPORT const PuzzleInfo::ErrorCodes
getErrorCode()
{
    return errorCode;
}

///
/// \brief Returns information about the puzzle.
///
/// \returns PuzzleInfo*
///
extern "C"
API_EXPORT PuzzleInfo*
getPuzzleInfo()
{
    PuzzleInfo* puzzleInfo = new PuzzleInfo();

    puzzleInfo->number = const_cast<char*>(number);
    puzzleInfo->name = const_cast<char*>(name);
    puzzleInfo->parametersInfo = const_cast<char*>(parametersInfo);
    puzzleInfo->text = const_cast<char*>(text);

    return puzzleInfo;
}

///
/// \brief Runs the puzzle with the passed parameters.
/// \param[in] char* parameters A list of parameters.
///
extern "C"
API_EXPORT void
run(const char* const parameters)
{
    std::cout << "Parameters: " << parameters << std::endl;
}
