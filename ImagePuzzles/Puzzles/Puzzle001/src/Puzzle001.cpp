#include "Puzzle001.hpp"

#include <iostream>
#include <vector>

#include "common/puzzleinfo.hpp"

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
