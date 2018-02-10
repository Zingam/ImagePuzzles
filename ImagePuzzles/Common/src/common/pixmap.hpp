#ifndef PIXMAP_HPP
#define PIXMAP_HPP

#include <cstdint>

#include <memory>
#include <vector>

class Pixmap
{
public:
    enum class PixmapType
    {
        NoImage,
        PBM,
        PGM,
        PPM
    };

public:
    Pixmap();
    Pixmap(const PixmapType type, const uint32_t width, const uint32_t height, const uint16_t maxValue = 0);
    ~Pixmap();

public:
    const uint8_t* Data() const;
    uint32_t Height() const;
    uint32_t MaxValue() const;
    const uint8_t* PixelData() const;
    uint32_t Width() const;

public:
    bool LoadFromMemory(const uint8_t* buffer);

private:
    unsigned char* bytes;
    std::unique_ptr<std::vector<uint8_t>> buffer;
    size_t bytesCount;
    size_t headerSize;
    uint32_t height;
    uint16_t maxValue;
    PixmapType type;
    uint32_t width;

private:
    void InitializePixmap(const size_t bufferSize, const std::string& imageHeader);
    void InitializePixmap_PBM();
    void InitializePixmap_PGM();
    void InitializePixmap_PPM();
};

////////////////////////////////////////////////////////////////////////////////
// Inline public properties
////////////////////////////////////////////////////////////////////////////////
inline
uint32_t
Pixmap::Height() const
{
    return this->height;
}

inline
uint32_t
Pixmap::MaxValue() const
{
    return this->maxValue;
}

inline
uint32_t
Pixmap::Width() const
{
    return this->width;
}

#endif // PIXMAP_HPP
