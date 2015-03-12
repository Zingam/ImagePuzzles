#ifndef PUZZLEINFO
#define PUZZLEINFO

struct PuzzleInfo
{
    enum ErrorCodes
    {
        NoError             = 0xC0000001,
        InvalidParameters   = 0xC0000101
    };

    const char* number;
    const char* name;
    const char* parametersInfo;
    const char* text;
};

typedef const char* const PuzzleGUID;
PuzzleGUID puzzleGUID = "5a5a20a2-f5ef-4d21-9661-0942251e97a8";

#endif // PUZZLEINFO

