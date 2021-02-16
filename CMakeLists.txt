cmake_minimum_required(VERSION 3.10)
project(libppm)

set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(ppm STATIC
	"src/PPMImage.cc"
	"src/PPMPixel.cc"
)

target_include_directories(ppm PRIVATE
	"include/"
)
