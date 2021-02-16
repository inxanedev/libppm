#include "PPMColor.h"
#include "PPMImage.h"
#include <cstdint>
#include <fstream>
#include <vector>

namespace ppm {
    Image::Image(uint32_t width, uint32_t height) : m_width(width), m_height(height) {
        _alloc_data(width, height, 0, 0, 0);
    }
    
    Image::Image(uint32_t width, uint32_t height, const Color& color) : m_width(width), m_height(height) {
        _alloc_data(width, height, color.r, color.g, color.b);
    }

    uint32_t Image::get_width() { return m_width; }
    uint32_t Image::get_height() { return m_height; }

    void Image::draw_pixel(uint32_t x, uint32_t y, const Color& color) {
        m_data[y][x] = color;
    }

    void Image::clear(const Color& color) {
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
    
    void Image::_alloc_data(uint32_t width, uint32_t height, uint32_t r, uint32_t g, uint32_t b) {
        m_data.reserve(height);
        for (int y = 0; y < height; y++) {
            m_data[y].reserve(width);
            for (int x = 0; x < width; x++)
                m_data[y].emplace_back(r, g, b);
        }
    }
}
