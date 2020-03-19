#include "StudentPreProcessing.h"
#include "ImageFactory.h"
#include <algorithm>
#include <array>


Intensity StudentPreProcessing::doGrayScaling(RGB pixel) const {
	std::array<int, 3> x = { pixel.r, pixel.g, pixel.b };
	switch (currentAlgorithm) {
		case INTENSITY: {
			return(x[0] + x[1] + x[2] / 3);
		}
		case VALUE: {
			int result = *std::max(x.begin(), x.end());
			return Intensity(result);

		}
		case LUMINANCE: {
			return((x[0] * 0.3) + (x[1] * 0.59) + (x[2] * 0.11));
		}
		case LIGHTNESS: {
			int Y = 0.2126 * x[0] + 0.7152 * x[1] + 0.0722 * x[2];
			if (Y > (6 / 29) ^ 3) {
				Y = Y ^ (1 / 3);
			}
			else {
				Y = (1 / 3) * (29 / 6) ^ 2 * Y + (4 / 29);
			}
			return ((1 / 100) * (116 * Y - 16));
		}
		default: {
			return (1 / 2) * (*std::max(x.begin(), x.end()) + *std::min(x.begin(), x.end()));
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