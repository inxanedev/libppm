#pragma once
#include <cstdint>
#include "PPMPixel.h"

namespace ppm {
    class Image {
    public:
        // Constructs a new PPMImage with the specified dimensions.
        Image(uint32_t width, uint32_t height);
        ~Image();

        uint32_t get_width();
        uint32_t get_height();

        void draw_pixel(uint32_t x, uint32_t y, const Pixel& color);
        void clear(const Pixel& color);

        void save(const char* filename);
    private:
        uint32_t m_width;
        uint32_t m_height;
        Pixel** m_data;
    };
}
