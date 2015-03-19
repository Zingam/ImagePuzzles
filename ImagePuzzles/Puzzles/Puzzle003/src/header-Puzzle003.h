#ifndef HEADER
#define HEADER

#include "common/cssstyles.h"

/* ****************************************************************************
 * CONSTANTS
 * ***************************************************************************/

const char* const number =
        "003";
const char* const name =
        "Create a Gray Wedge Image";
const char* const parametersInfo =
        "(int)width, (int)height";
const char* const text =
        CSS_STYLES
        "<p class='heading'>Problem:</p>"
        "<p>Create an image that is a gray wedge. A gray wedge is an image that "
        "has a gray level 0 in its first row and gray level 255 in its last "
        "row, and the rows in between increasing in gray level. The command "
        "line specifies the size of the image.</p>"
        "<p class='heading'>Parameters:</p>"
        "<p class='parameters'>200 400</p>"
        "<p class='note'>Use the above parameters in the parameters line edit.</note>";

// Default parameters
int width = 200;
int height = 400;

#endif // HEADER

