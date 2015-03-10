#include <string>
#include <iostream>

#include "common/library.h"
#include "common/types.h"

const char* const number =
        "001";
const char* const name =
        "Create an Image of Uniform Gray Level";
const char* const parametersInfo =
        "(int)width, (int)height, (int)grayLevel";
const char* const text =
        "Creates a gray level image file of size 200 rows by 300 columns with"
        " all pixels at level 240."
        "Use parameters: 200 300 240";

// Default parameters
int width = 300;
int height = 300;
int grayLevel = 140;


extern "C" API_EXPORT PuzzleInfo* getPuzzleInfo()
{
    PuzzleInfo* puzzleInfo = new PuzzleInfo();

    puzzleInfo->number = const_cast<char*>(number);
    puzzleInfo->name = const_cast<char*>(name);
    puzzleInfo->parametersInfo = const_cast<char*>(parametersInfo);
    puzzleInfo->text = const_cast<char*>(text);

    return puzzleInfo;
}

extern "C" API_EXPORT void run(char* parameters)
{
    std::cout << "Parameters: " << parameters << std::endl;
}
