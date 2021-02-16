#include "PPMPixel.h"
namespace ppm {
    Pixel::Pixel(uint32_t r, uint32_t g, uint32_t b) {
        this->r = r;
        this->g = g;
        this->b = b;
    }
    Pixel::Pixel() {
        r = 0, g = 0, b = 0;
    }
}
