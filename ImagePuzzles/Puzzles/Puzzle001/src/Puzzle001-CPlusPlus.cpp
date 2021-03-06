#include "Puzzle001.hpp"

#include <common/puzzleinfo.hpp>
#include <common/pixmap.hpp>

#include <iostream>
#include <stdexcept>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// FUNCTIONS
////////////////////////////////////////////////////////////////////////////////

PuzzlePixmap&
run_CPlusPlus(
        PuzzlePixmap& puzzlePixmap,
        const std::vector<std::string>* const parameters,
        PuzzleInfo::ErrorCodes& errorCode)
{
    int width = 0;
    int height = 0;
    int greyLevel = 0;

    const std::string& widthString = parameters->at(0);
    const std::string& heightString = parameters->at(1);
    const std::string& greyLevelString = parameters->at(2);

    try
    {
        width = std::stoi(widthString);
        height = std::stoi(heightString);
        greyLevel = std::stoi(greyLevelString);
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

    if (nullptr != puzzlePixmap.buffer)
    {
        free(puzzlePixmap.buffer);
        puzzlePixmap.size = 0;
    }

    size_t widthCharCount = widthString.length();
    size_t heightCharCount = heightString.length();
    size_t greyLevelCount = greyLevelString.length();

    size_t pgmHeaderSize =
            (2 + 1
             + widthCharCount + 1
             + heightCharCount + 1
             + greyLevelCount + 1)
            * sizeof(char);
    size_t pixmapDataSize =
            width * height
            * sizeof(unsigned char);

    size_t pgmSize = pgmHeaderSize + pixmapDataSize;

    std::string pgmHeader("P5 ");
    pgmHeader +=
            widthString + " "
            + heightString + " "
            + greyLevelString + " ";

    puzzlePixmap.buffer =
            (unsigned char*) malloc(pgmSize);
    puzzlePixmap.size = width * height;

    auto pgmHeader_c_str_Ptr = const_cast<char*>(pgmHeader.c_str());
    // Keep the original pointer to the buffer untouched
    auto buffer_Ptr = puzzlePixmap.buffer;

    // Copy the header
    size_t index = 0;
    while (index < pgmHeaderSize)
    {
        buffer_Ptr[index] = pgmHeader_c_str_Ptr[index];
        ++index;
    }

    // Generate the image data/pixels
    for (int column = 0; width > column; ++column)
    {
        for (int row = 0; height > row; ++row)
        {
            buffer_Ptr[index + column + row] = greyLevel;
        }
    }

    puzzlePixmap.size = pgmSize;

    return puzzlePixmap;
}
