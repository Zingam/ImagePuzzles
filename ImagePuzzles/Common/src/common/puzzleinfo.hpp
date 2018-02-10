#ifndef PUZZLEINFO_HPP
#define PUZZLEINFO_HPP

#include <vector>

#define IMPLEMENTATION_TYPE_CPlusPlus "C++"
#define IMPLEMENTATION_TYPE_OpenCL "OpenCL"
#define IMPLEMENTATION_TYPE_OpenGL "OpenGL"

struct PuzzleInfo
{
    enum ErrorCodes
    {
        NoError             = 0xC0000001,
        InvalidParameters   = 0xC0000101
    };

    enum ImplementationType
    {
        CPlusPlus,
        OpenCL,
        OpenGL
    };

    const char* number;
    const char* name;
    const char* paramaters;
    const char* parametersInfo;
    const char* text;

    bool usesExternalImage;

    // Assign a Map containing the function names and types
    using Implementations = std::vector<PuzzleInfo::ImplementationType>;
    Implementations* implementations;
};

//typedef std::vector<PuzzleInfo::ImplementationType> Implementations;

typedef const char* PuzzleGUID;
const PuzzleGUID puzzleGUID = "5a5a20a2-f5ef-4d21-9661-0942251e97a8";

#endif // PUZZLEINFO_HPP
