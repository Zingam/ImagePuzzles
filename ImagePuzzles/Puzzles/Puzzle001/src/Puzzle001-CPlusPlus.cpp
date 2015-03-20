#include "Puzzle001.h"

#include <iostream>
#include <vector>

#include "common/puzzleinfo.h"


/* ****************************************************************************
 * FUNCTIONS
 * ***************************************************************************/

PuzzlePixmap&
run_CPlusPlus(
        PuzzlePixmap& puzzlePixmap,
        const std::vector<std::string>* const parameters,
        PuzzleInfo::ErrorCodes& errorCode)
{
    int width = 0;
    int height = 0;
    int greyLevel = 0;

    try
    {
        width = std::stoi(parameters->at(0));
        height = std::stoi(parameters->at(1));
        greyLevel = std::stoi(parameters->at(2));
    }
    catch (std::invalid_argument& exception)
    {
        errorCode = PuzzleInfo::InvalidParameters;

        width = widthDefault;
        height = heightDefault;
        greyLevel = greyLevelDefault;

        std::cout << "Invalid parameter: " << exception.what() << std::endl;
        std::cout << "Using default values." << std::endl;
    }

    std::cout << "Width:      " << width << std::endl;
    std::cout << "Heigth:     " << height << std::endl;
    std::cout << "Grey level: " << greyLevel << std::endl;

    puzzlePixmap.buffer = nullptr;
    puzzlePixmap.size = 0;

    return puzzlePixmap;
}
