#ifndef PUZZLEINFO
#define PUZZLEINFO

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

    // Assign a Map containing the function names and types
    const void* implementations;
};

typedef std::vector<PuzzleInfo::ImplementationType> Implementations;

typedef const char* const PuzzleGUID;
PuzzleGUID puzzleGUID = "5a5a20a2-f5ef-4d21-9661-0942251e97a8";

#endif // PUZZLEINFO

