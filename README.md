# libppm
libppm is a library for interacting with the PPM image format in C++.  
This library was made for fun and exercise, this shouldn't be used in any production software.
# building
This library builds as a static library. To build it, clone the repository, and cd into the root directory. Then, run the following commands:

    mkdir build
	cd build
	cmake ..
	make

Now, the directory you're in should have the built libppm.a file ready to go.  
In order to use this project in your programs, you'll need to set up the include paths, and to do that, all you need to do is add the include folder.

# example

Let's create a PPM image, make all the pixels red, and save it to a file.

    #include "PPMImage.h"

	ppm::Image image(256, 256); // 256x256 image
	image.clear(ppm::Color(255, 0, 0)); // 255 0 0 is RGB for the color RED.
    // Optionally you can call the ppm::Image constructor like this:
    //
    // ppm::Image image(256, 256, ppm::Color(255, 0, 0));
    //
    // This way will also prevent a lot of unnecessary allocations.
	image.save("cool_image.ppm"); // save to specified filename
