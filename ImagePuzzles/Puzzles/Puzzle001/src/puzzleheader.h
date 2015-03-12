#ifndef HEADER
#define HEADER

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
        "Create a gray level image file of size 200 rows by 300 columns with"
        " all pixels at level 240.\n"
        "Use parameters:\n"
        "    200 300 240";

// Default parameters
int width = 300;
int height = 300;
int grayLevel = 140;

#endif // HEADER

