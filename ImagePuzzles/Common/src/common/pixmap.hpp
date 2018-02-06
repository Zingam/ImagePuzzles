#ifndef PIXMAP_HPP
#define PIXMAP_HPP

namespace std
{
    class iostream;
    class string;
}

class Pixmap
{
public:
    Pixmap();
    ~Pixmap();

    enum PixmapType
    {
        NoImage,
        PGM,
        PPM
    };

    unsigned char* bytes;
    size_t bytesCount;
    size_t headerSize;
    PixmapType type;

    void generatePGM(uint width, uint height, uchar greyLevel, void (&generator)(Pixmap& pixmap, const std::vector<std::string>* const parameters));
    void generatePPM(uint width, uint height, uchar colorLevel, void (&generator)(Pixmap& pixmap, const std::vector<std::string>* const parameters));
};

#endif // PIXMAP_HPP
