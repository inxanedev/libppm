#pragma once
#include <cstdint>
#include "PPMColor.h"
#include <vector>

namespace ppm {
    class Image {
    public:
        // Constructs a new PPMImage with the specified dimensions.
        Image(uint32_t width, uint32_t height);
        Image(uint32_t width, uint32_t height, const Color& color);

        uint32_t get_width();
        uint32_t get_height();

        void draw_pixel(uint32_t x, uint32_t y, const Color& color);
        void clear(const Color& color);

        void save(const char* filename);
    private:
        uint32_t m_width;
        uint32_t m_height;
        std::vector<std::vector<Color>> m_data;
    
        void _alloc_data(uint32_t width, uint32_t height, uint32_t r, uint32_t g, uint32_t b);
    };
}
