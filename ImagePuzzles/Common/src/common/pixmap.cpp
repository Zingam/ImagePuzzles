#include "pixmap.hpp"

#include <cassert>

#include <sstream>
#include <tuple>

////////////////////////////////////////////////////////////////////////////////
// Constructors & destructors
////////////////////////////////////////////////////////////////////////////////
Pixmap::Pixmap()
    : Pixmap { Pixmap::PixmapType::NoImage, 0, 0}
{}

Pixmap::Pixmap(
        PixmapType type,
        const uint32_t width,
        const uint32_t height,
        const uint16_t maxValue)
    : bytesCount { 0 }
    , headerSize { 0 }
    , height { height }
    , maxValue { maxValue }
    , type { type }
    , width { width }
{
    switch (this->type)
    {
        case PixmapType::PBM:
        {
            this->InitializePixmap_PBM();
            break;
        }
        case PixmapType::PGM:
        {
            this->InitializePixmap_PGM();
            break;
        }
        case PixmapType::PPM:
        {
            this->InitializePixmap_PPM();
            break;
        }
        default:
        {
            this->height = 0;
            this->maxValue = 0;
            this->width = 0;
            break;
        }
    }
}

Pixmap::~Pixmap()
{
    this->bytesCount = 0;
    this->headerSize = 0;
    this->type = Pixmap::PixmapType::NoImage;
}

////////////////////////////////////////////////////////////////////////////////
// Public properties
////////////////////////////////////////////////////////////////////////////////

const uint8_t*
Pixmap::Data() const
{
    return this->buffer->data();
}

const uint8_t*
Pixmap::PixelData() const
{
    return (this->buffer->data() + this->headerSize);
}

////////////////////////////////////////////////////////////////////////////////
// Public methods
////////////////////////////////////////////////////////////////////////////////

bool
Pixmap::LoadFromMemory(const uint8_t* buffer)
{

    auto get_token =
            [](const uint8_t* buffer, size_t offset) -> std::pair<std::string, size_t>
    {
        // TAB   : '\x09', '\t';
        // LF    : '\x0A', '\n';
        // CR    : '\x0D', '\r';
        // Space : '\x2"',  ' ';
        std::string whitespaces { "\t\n\r " };

        std::string token;
        bool isWhiteSpace = false;
        while (!isWhiteSpace)
        {
            ++offset;
            char character = *(buffer + offset);
            if (std::string::npos != whitespaces.find_first_of(character))
            {
                token.push_back(*(buffer + offset));
            }
            else
            {
                isWhiteSpace = true;
            }
        }
        return { token, offset };
    };

    size_t offset = 0;
    auto [token, offset1] = get_token(buffer, offset);
    if ("P4" == token)
    {

    }
    else if ("P5" == token)
    {

    }
    else if ("P6" == token)
    {

    }
    else
    {
        return false;
    }

    auto pair = get_token(buffer, offset);
    this->width = atoi(pair.first.c_str());

    pair = get_token(buffer, offset);
    //this->height = atoi(get_token(buffer).c_str());

    //if (isMaxlevel)
    {
        //this->maxValue = atoi(get_token(buffer).c_str());
    }

    uint8_t whitespace = *buffer;

    return true;
}

////////////////////////////////////////////////////////////////////////////////
// Private methods
////////////////////////////////////////////////////////////////////////////////
void
Pixmap::InitializePixmap(
        const size_t bufferSize,
        const std::string& imageHeader)
{
    this->headerSize = imageHeader.length();
    this->bytesCount = this->headerSize + bufferSize;
    this->buffer = std::make_unique<std::vector<uint8_t>>(this->bytesCount);

    // Copy the pixmap header into the buffer
    size_t index = 0;
    while (this->headerSize > index)
    {
        (*(this->bytes++)) = imageHeader.data()[index++];
    }
}

// Portable Bitmap Format
void
Pixmap::InitializePixmap_PBM()
{
    ////////////////////////////////////////////////////////////////////////////
    // PBM Format
    // http://netpbm.sourceforge.net/doc/pbm.html
    //
    // Header format:
    //
    // Magic number:                "P4"
    // White space:                 " "
    // Width in ASCII chars:        Width
    // White space:                 " "
    // Height in ASCII chars:       Height
    // White space:                 " "
    // 1 bit per pixel data:        bytes
    //
    // A raster of Height rows, in order from top to bottom. Each row is Width
    // bits, packed 8 to a byte, with don't care bits to fill out the last byte
    // in the row. Each bit represents a pixel: 1 is black, 0 is white. The
    // order of the pixels is left to right. The order of their storage within
    // each file byte is most significant bit to least significant bit. The
    // order of the file bytes is from the beginning of the file toward the end
    // of the file.
    // A row of an image is horizontal. A column is vertical. The pixels in the
    // image are square and contiguous.
    ////////////////////////////////////////////////////////////////////////////

    // Create pixmap header (PBM)
    std::stringstream imageHeader { "P4 " };
    imageHeader << this->Width() << " " << this->Height() << " ";

    size_t adjustmentByte = (0 == (25 % 8)) ? 0 : 1;
    size_t bytesPerRow = this->Width() / 8 + adjustmentByte;
    size_t bufferSize = bytesPerRow * this->Height();

    this->InitializePixmap(bufferSize, imageHeader.str());
}

// Portable Graymap Format
void
Pixmap::InitializePixmap_PGM()
{
    this->bytes = nullptr;
    this->bytesCount = 0;
    this->type = Pixmap::PixmapType::PGM;

    ////////////////////////////////////////////////////////////////////////////
    // PGM Format
    // http://netpbm.sourceforge.net/doc/pgm.html
    //
    // Header format:
    //
    // Magic number:                "P5"
    // White space:                 " "
    // Width in ASCII chars:        Width
    // White space:                 " "
    // Height in ASCII chars:       Height
    // White space:                 " "
    // Grey level in ASCII chars:   0 < Maxval < 65536
    // White space:                 " "
    // 1 byte per pixel data:       bytes
    //
    // A raster of Height rows, in order from top to bottom. Each row consists
    // of Width gray values, in order from left to right. Each gray value is a
    // number from 0 through Maxval, with 0 being black and Maxval being white.
    // Each gray value is represented in pure binary by either 1 or 2 bytes. If
    // the Maxval is less than 256, it is 1 byte. Otherwise, it is 2 bytes. The
    // most significant byte is first.
    // A row of an image is horizontal. A column is vertical. The pixels in the
    // image are square and contiguous.
    ////////////////////////////////////////////////////////////////////////////

    // Create pixmap header (PGM)
    std::stringstream imageHeader { "P5 " };
    imageHeader << this->Width() << " " << this->Height() << " "
                << this->MaxValue() << " ";

    size_t bytesPerGreyValue = (256 > this->MaxValue()) ? 1 : 2;
    size_t bytesPerRow = bytesPerGreyValue * this->Width();
    size_t bufferSize = bytesPerRow * this->Height();

    this->InitializePixmap(bufferSize, imageHeader.str());
}

// Portable Pixmap Format
void Pixmap::InitializePixmap_PPM()
{
    this->bytes = nullptr;
    this->bytesCount = 0;
    this->type = Pixmap::PixmapType::PPM;

    ////////////////////////////////////////////////////////////////////////////
    // PPM Format
    // http://netpbm.sourceforge.net/doc/ppm.html
    //
    // Header format:
    //
    // Magic number:                "P6"
    // White space:                 " "
    // Width in ASCII chars:        Width
    // White space:                 " "
    // Height in ASCII chars:       Height
    // White space:                 " "
    // Grey level in ASCII chars:   0 < Maxval < 65536
    // White space:                 " "
    // 3 bytes per pixel data:      bytes
    //
    // A raster of Height rows, in order from top to bottom. Each row consists
    // of Width pixels, in order from left to right. Each pixel is a triplet of
    // red, green, and blue samples, in that order. Each sample is represented
    // in pure binary by either 1 or 2 bytes. If the Maxval is less than 256,
    // it is 1 byte. Otherwise, it is 2 bytes. The most significant byte is
    // first.
    // A row of an image is horizontal. A column is vertical. The pixels in the
    // image are square and contiguous.
    ////////////////////////////////////////////////////////////////////////////

    // Create pixmap header (PPM)
    std::stringstream imageHeader { "P6 " };
    imageHeader << this->Width() << " " << this->Height() << " "
                << this->MaxValue() << " ";

    size_t bytesPerColorSample = (256 > this->MaxValue()) ? 1 : 2;
    size_t bytesPerPixel = bytesPerColorSample * 3;
    size_t bytesPerRow = bytesPerPixel * this->Width();
    size_t bufferSize = bytesPerRow * this->Height();

    this->InitializePixmap(bufferSize, imageHeader.str());
}
