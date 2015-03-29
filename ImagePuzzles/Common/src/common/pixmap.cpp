#include "pixmap.h"

Pixmap::Pixmap()
{

}

Pixmap::~Pixmap()
{
    free(this->bytes);
    this->bytesCount = 0;
    this->type = Pixmap::NoImage;
}

void
Pixmap::generatePGM(
        uint width,
        uint height,
        uchar greyLevel,
        const std::vector<std::string>* const parameters,
        void (&generator)(Pixmap* pixmap, const std::vector<std::string>* const parameters))
{
    this->bytes = nullptr;
    this->bytesCount = 0;
    this->type = Pixmap::PGM;

    // Create pixmap header (PGM)
    /* PGM Format:
     *
     * Magic number:                P5
     * White space:                 ' '
     * Width in ASCII chars:        width
     * White space:                 ' '
     * Height in ASCII chars:       height
     * White space:                 ' '
     * Grey level in ASCII chars:   greyLevel
     * White space:                 ' '
     * 1 byte per pixel data:       bytes
     *
     * First columns then rows.
     * */
    char header[65535];
    const char* magicNumberString = "P5";
#pragma warning(push)
#pragma warning(disable: 4996) //4996 for _CRT_SECURE_NO_WARNINGS equivalent
    sprintf(header, "%s %d %d %d ", // This corresponds the the format above
            magicNumberString,
            width,
            height,
            greyLevel);
#pragma warning(pop)

    size_t headerLength = strlen(header);
    size_t pixelDataLength = width * height * sizeof(greyLevel);

    this->bytesCount = headerLength + pixelDataLength;

    this->bytes  = (unsigned char*) malloc(pgmPixmap.bytesCount);

    // Copy the pixmap header into the buffer
    unsigned char* buffer = pgmPixmap.bytes;
    unsigned int index = 0;
    while (headerLength > index)
    {
        (*(buffer++)) = header[index++];
    }

    (*generator)(this, parameters);
}

void Pixmap::generatePPM(
        uint width,
        uint height,
        uchar colorLevel,
        const std::vector<std::string>* const parameters,
        void (&generator)(Pixmap& pixmap, const std::vector<std::string>* const parameters))
{
    this->bytes = nullptr;
    this->bytesCount = 0;
    this->type = Pixmap::PPM;

    // Create pixmap header (PPM)
    /* PGM Format:
     *
     * Magic number:                P6
     * White space:                 ' '
     * Width in ASCII chars:        width
     * White space:                 ' '
     * Height in ASCII chars:       height
     * White space:                 ' '
     * Grey level in ASCII chars:   colorLevel
     * White space:                 ' '
     * 1 byte per pixel data:       bytes
     *
     * First columns then rows.
     * */
    char header[65535];
    const char* magicNumberString = "P6";
#pragma warning(push)
#pragma warning(disable: 4996) //4996 for _CRT_SECURE_NO_WARNINGS equivalent
    sprintf(header, "%s %d %d %d ",
            magicNumberString,
            width,
            height,
            colorLevel);
#pragma warning(pop)

    size_t headerLength = strlen(header);
    size_t pixelDataLength = width * height * sizeof(colorLevel) * 3;

    ppmPixmap.bytesCount = headerLength + pixelDataLength;

    ppmPixmap.bytes  = (unsigned char*) malloc(ppmPixmap.bytesCount);
    unsigned char* buffer = ppmPixmap.bytes;
    unsigned int index = 0;
    while (headerLength > index)
    {
        (*(buffer++)) = header[index++];
    }

    (*generator)(this, parameters);
}

