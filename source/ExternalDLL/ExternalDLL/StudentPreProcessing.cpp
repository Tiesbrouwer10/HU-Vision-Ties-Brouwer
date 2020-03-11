#include "StudentPreProcessing.h"
#include "ImageFactory.h"


Intensity StudentPreProcessing::doGrayScaling(RGB pixel) const {
	return(pixel.r + pixel.g + pixel.b) / 3;
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