#include "Puzzle001.hpp"

#include <vector>

#include "common/puzzleinfo.hpp"


/* ****************************************************************************
 * FUNCTIONS
 * ***************************************************************************/

PuzzlePixmap&
run_OpenCL(
        PuzzlePixmap& puzzlePixmap,
        const std::vector<std::string>* const parameters,
        PuzzleInfo::ErrorCodes& errorCode)
{
    (void)parameters;
    (void)errorCode;
    puzzlePixmap.buffer = nullptr;
    puzzlePixmap.size = 0;

    return puzzlePixmap;
}
