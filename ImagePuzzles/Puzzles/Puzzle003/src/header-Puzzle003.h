#ifndef HEADER
#define HEADER

/* ****************************************************************************
 * CONSTANTS
 * ***************************************************************************/

const char* const number =
        "003";
const char* const name =
        "Create a Gray Wedge Image";
const char* const parametersInfo =
        "(int)width, (int)height, (int)grayLevel";
const char* const text =
        "Create an image that is a gray wedge. A gray wedge is an image that "
        "has a gray level 0 in its first row and gray level 255 in its last "
        "row, and the rows in between increasing in gray level. The command "
        "line specifies the size of the image."
        "\n"
        "Use parameters:\n"
        "    200 400 240";

// Default parameters
int width = 300;
int height = 300;
int grayLevel = 240;

#endif // HEADER

