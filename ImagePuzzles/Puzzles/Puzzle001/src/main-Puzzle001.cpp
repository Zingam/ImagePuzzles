#include "Puzzle001.hpp"

#include <common/apiexport.hpp>
#include <common/puzzlefunctions.hpp>
#include <common/puzzleinfo.hpp>

#include <iostream>
#include <string>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// GLOBAL VARIABLES
////////////////////////////////////////////////////////////////////////////////

static PuzzleInfo* puzzleInfo;
static PuzzleInfo::ErrorCodes errorCode = PuzzleInfo::ErrorCodes::NoError;
static std::string defaultParametersString;
static PuzzleInfo::Implementations implementations;
static PuzzlePixmap puzzlePixmap;

////////////////////////////////////////////////////////////////////////////////
// EXPORTED FUNCTIONS
////////////////////////////////////////////////////////////////////////////////

///
/// \brief Returns the last error code
///
/// \returns PuzzleInfo::ErorrCodes
///
extern "C"
API_EXPORT                      // const PuzzleInfo::ErrorCodes
GetErrorCode(getErrorCode)      // void
{
    return errorCode;
}

///
/// \brief Returns an unique identifier
///
/// The returned value must be "5a5a20a2-f5ef-4d21-9661-0942251e97a8". The
/// application needs to check for this value to identify if the loaded dynamic
/// library is a puzzle. If \return is a correct value the application can
/// load the rest of the functions;
///
/// \returns "5a5a20a2-f5ef-4d21-9661-0942251e97a8"
///
extern "C"
API_EXPORT                      // PuzzleGUID
GetPuzzleGUID(getPuzzleGUID)    // void
{
    return puzzleGUID;
}

///
/// \brief Returns information about the puzzle.
///
/// \returns PuzzleInfo*
///
extern "C"
API_EXPORT                      // PuzzleInfo*
GetPuzzleInfo(getPuzzleInfo)    // void
{
    puzzleInfo = new PuzzleInfo();

    puzzleInfo->number = number;
    puzzleInfo->name = name;
    std::string& parameters = getDefaultParametersString(defaultParametersString);
    puzzleInfo->paramaters = parameters.c_str();
    puzzleInfo->parametersInfo = parametersInfo;
    puzzleInfo->text = text;
    puzzleInfo->implementations = &getImplementations(implementations);

    return puzzleInfo;
}

///
/// \brief Runs the puzzle with the passed parameters.
/// \param[in] char* parameters A list of parameters.
/// The type is: const std::vector<std::string>* const.
/// \param[in] PuzzleInfo::ImplemenationType implementationType The type of the function.
/// The type is enum class FunctionType.
///
/// \returns PuzzleImage*
///
extern "C"
API_EXPORT                      // void
Run(run)                        // const void* const parameters,
                                // PuzzleInfo::ImplemenationType implementaionType
{
    const std::vector<std::string>* const parametersString =
            reinterpret_cast<const std::vector<std::string>* const>(parameters);

    switch (implementationType)
    {
        case PuzzleInfo::CPlusPlus:
        {
            PuzzlePixmap& temp = run_CPlusPlus(puzzlePixmap, parametersString, errorCode);
            puzzlePixmap = temp;

            break;
        }
        case PuzzleInfo::OpenCL:
        {
            puzzlePixmap = run_OpenCL(puzzlePixmap, parametersString, errorCode);
        } break;
        case PuzzleInfo::OpenGL:
        {
            puzzlePixmap = run_OpenGL(puzzlePixmap, parametersString, errorCode);
        } break;

        default:
        {
            puzzlePixmap.buffer = nullptr;
            puzzlePixmap.size = 0;

            return &puzzlePixmap;
        }
    }

    return &puzzlePixmap;
}
