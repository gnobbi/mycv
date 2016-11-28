#include "Image/image.h"
#include <iostream>
#include <opencv2/opencv.hpp>

void Dummy() { Image x; };


Image::Image() {
	std::cout << "Image Ctor" << std::endl;
	cv::namedWindow("EyeLikeBase");
	cv::waitKey(0);
}


