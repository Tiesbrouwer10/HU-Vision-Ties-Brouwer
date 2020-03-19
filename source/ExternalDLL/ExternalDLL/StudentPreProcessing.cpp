#include "StudentPreProcessing.h"
#include "ImageFactory.h"
#include <algorithm>


Intensity StudentPreProcessing::doGrayScaling(RGB pixel) const {
	switch (currentAlgorithm) {
		case INTENSITY: {
			return(pixel.r + pixel.g + pixel.b) / 3;
		}
		case VALUE: {
			return std::max(pixel.r, pixel.g, pixel.b);
		}
		case LUMINANCE: {
			return((pixel.r * 0.3) + (pixel.g * 0.59) + (pixel.b * 0.11));
		}
		case LIGHTNESS: {
			int Y = 0.2126 * pixel.r + 0.7152 * pixel.g + 0.0722 * pixel.b;
			if (Y > (6 / 29) ^ 3) {
				Y = Y ^ (1 / 3);
			}
			else {
				Y = (1 / 3) * (29 / 6) ^ 2 * Y + (4 / 29);
			}
			return ((1 / 100) * (116 * Y - 16));
		}
		default:{
			return (1 / 2) * (std::max(pixel.r, pixel.g, pixel.b) + std::min(pixel.r, pixel.g, pixel.b));
		}
	}

}

IntensityImage* StudentPreProcessing::stepToIntensityImage(const RGBImage& image) const {
	int height = image.getHeight();
	int width = image.getWidth();
	std::cout << "Student pre processing" << std::endl;
	IntensityImage* IntensityImage_ = ImageFactory::newIntensityImage(width, height);
	IntensityImage_->set(width, height);

	for (size_t i = 0; i < width; i++) {
		for (size_t j = 0; j < height; j++) {
			IntensityImage_->setPixel(i, j, doGrayScaling(image.getPixel(i, j)));
		}
	}

	return IntensityImage_;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}