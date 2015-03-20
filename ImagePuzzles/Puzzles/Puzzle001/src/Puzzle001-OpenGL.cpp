#include "Puzzle001.h"

#include <vector>

#include "common/puzzleinfo.h"

/* ****************************************************************************
 * FUNCTIONS
 * ***************************************************************************/

PuzzlePixmap&
run_OpenGL(
        PuzzlePixmap& puzzlePixmap,
        const std::vector<std::string>* const parameters,
        PuzzleInfo::ErrorCodes& errorCode)
{
    puzzlePixmap.buffer = nullptr;
    puzzlePixmap.size = 0;

    return puzzlePixmap;
}
