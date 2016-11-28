#include "image/Image.h"
#include <iostream>


void Dummy() { Image img; };


Image::Image() {
	std::cout << "Image Ctor" << std::endl;
}

