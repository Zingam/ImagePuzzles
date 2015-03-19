#ifndef HEADER
#define HEADER

#include "common/cssstyles.h"


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
int width = 200;
int height = 300;
int grayLevel = 240;

#endif // HEADER

