#pragma once

#include <cstdint>

namespace ppm {
    class Pixel {
        public:
            char r, g, b;
            // Constructs new pixel with specified R, G and B values.
            Pixel(uint32_t r, uint32_t g, uint32_t b);
            // Constructs new default black pixel
            Pixel();
    };
}
