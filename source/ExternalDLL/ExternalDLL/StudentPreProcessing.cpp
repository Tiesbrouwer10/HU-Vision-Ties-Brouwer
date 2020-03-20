#include "StudentPreProcessing.h"
#include "ImageFactory.h"
#include <algorithm>
#include <array>
#include <math.h>

Intensity StudentPreProcessing::doGrayScaling(RGB pixel) const {
	std::array<float, 3> x = { pixel.r, pixel.g, pixel.b };
	switch (currentAlgorithm) {
	case Algorithms::INTENSITY: {
		 return((x[0] + x[1] + x[2]) / 3);
		}
		case Algorithms::VALUE: {
			return Intensity(*std::max_element(x.begin(), x.end()));

		}
		case Algorithms::LUMINANCE: {
			return((x[0] * 0.3) + (x[1] * 0.59) + (x[2] * 0.11));
		}
		case Algorithms::LUMA: {
			return((x[0] * 0.2126) + (x[1] * 0.7152) + (x[2] * 0.0722));
		}
		case Algorithms::LUSTER: {
			return Intensity(0.5 *(*std::max_element(x.begin(), x.end()) + *std::min_element(x.begin(), x.end())));
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