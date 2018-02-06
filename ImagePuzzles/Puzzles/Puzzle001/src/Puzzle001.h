#ifndef HEADER
#define HEADER

#include <string>
#include <vector>

#include "common/cssstyles.h"
#include "common/puzzleinfo.h"
#include "common/puzzlepixmap.h"
#include "memory"


/* ****************************************************************************
 * CONSTANTS
 * ***************************************************************************/
const char* const number =
        "001";
const char* const name =
        "Create an Image of Uniform Gray Level";
const char* const parametersInfo =
        "(int)width, (int)height, (int)grayLevel";
const char* const text =
        CSS_STYLES
        "<p class='heading'>Problem:</p>"
        "<p>Create a gray level image file of size 200 rows by 300 columns with "
        "all pixels at level 240.</p>"
        "<p class='heading'>Parameters:</p>"
        "<p class='parameters'>200 300 240</p>"
        "<p class='note'>Use the above parameters in the parameters line edit.</note>";

// Default parameters
const int widthDefault = 200;
const int heightDefault = 300;
const int greyLevelDefault = 240;


/* ****************************************************************************
 * FUNCTIONS
 * ***************************************************************************/
std::string&
getDefaultParametersString(std::string& defaultParametersString);

std::vector<PuzzleInfo::ImplementationType>&
getImplementations(Implementations& implementations);

/* ****************************************************************************
 * FUNCTIONS
 * ***************************************************************************/

PuzzlePixmap&
run_CPlusPlus(
        PuzzlePixmap& puzzlePixmap,
        const std::vector<std::string>* const parameters,
        PuzzleInfo::ErrorCodes& errorCode);

PuzzlePixmap&
run_OpenCL(
        PuzzlePixmap& puzzlePixmap,
        const std::vector<std::string>* const parameters,
        PuzzleInfo::ErrorCodes& errorCode);

PuzzlePixmap&
run_OpenGL(
        PuzzlePixmap& puzzlePixmap,
        const std::vector<std::string>* const parameters,
        PuzzleInfo::ErrorCodes& errorCode);

#endif // HEADER

