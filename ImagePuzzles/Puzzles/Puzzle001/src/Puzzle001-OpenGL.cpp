#include "Puzzle001.hpp"

#include <common/puzzleinfo.hpp>

#include <vector>

////////////////////////////////////////////////////////////////////////////////
// FUNCTIONS
////////////////////////////////////////////////////////////////////////////////

PuzzlePixmap&
run_OpenGL(
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
