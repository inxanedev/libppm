#pragma once

#include <cstdint>

namespace ppm {
    class Color {
        public:
            char r, g, b;
            // Constructs new color with specified R, G and B values.
            Color(uint32_t r, uint32_t g, uint32_t b);
    };
}
