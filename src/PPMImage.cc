#include "PPMPixel.h"
#include "PPMImage.h"
#include <cstdint>
#include <fstream>

namespace ppm {
    Image::Image(uint32_t width, uint32_t height) {
        m_width = width;
        m_height = height;

        m_data = new Pixel*[height];
        for (int i = 0; i < height; i++)
            m_data[i] = new Pixel[width];
    }

    Image::~Image() {
        for (int i = 0; i < m_height; i++)
            delete[] m_data[i];
        delete[] m_data;
    }

    uint32_t Image::get_width() { return m_width; }
    uint32_t Image::get_height() { return m_height; }

    void Image::draw_pixel(uint32_t x, uint32_t y, const Pixel& color) {
        m_data[y][x] = color;
    }

    void Image::clear(const Pixel& color) {
        for (int y = 0; y < m_height; y++) {
            for (int x = 0; x < m_width; x++) {
                draw_pixel(x, y, color);
            }
        }
    }

    void Image::save(const char* filename) {
        std::ofstream file(filename);
        file << "P6 " << m_width << " " << m_height << " 255\n";
        for (int y = 0; y < m_height; y++) {
            for (int x = 0; x < m_width; x++) {
                file << static_cast<char>(m_data[y][x].r)
                     << static_cast<char>(m_data[y][x].g)
                     << static_cast<char>(m_data[y][x].b);
            }
        }
        file.close();
    }
}
