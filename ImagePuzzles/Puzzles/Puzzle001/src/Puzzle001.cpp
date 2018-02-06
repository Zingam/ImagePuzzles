#include "Puzzle001.h"

#include <iostream>
#include <vector>

#include "common/puzzleinfo.h"

/* ****************************************************************************
 * FUNCTIONS
 * ***************************************************************************/

std::string&
getDefaultParametersString(std::string& defaultParametersString)
{
    if (!defaultParametersString.empty())
        defaultParametersString.erase();

    defaultParametersString
            .append(std::to_string(widthDefault)).append(" ")
            .append(std::to_string(heightDefault)).append(" ")
            .append(std::to_string(greyLevelDefault)).append(" ");

    return defaultParametersString;
}

std::vector<PuzzleInfo::ImplementationType>&
getImplementations(Implementations& implementations)
{
    implementations.push_back(PuzzleInfo::CPlusPlus);
    implementations.push_back(PuzzleInfo::OpenCL);
    implementations.push_back(PuzzleInfo::OpenGL);

    return implementations;
}

/* ****************************************************************************
 * FUNCTIONS
 * ***************************************************************************/
