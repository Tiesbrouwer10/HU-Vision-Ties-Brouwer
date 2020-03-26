#include "StudentPreProcessing.h"
#include "ImageFactory.h"
#include <algorithm>
#include <array>
#include <math.h>



Intensity StudentPreProcessing::doGrayScaling(RGB pixel) const {
    std::array<float, 3> x = { pixel.r, pixel.g, pixel.b };
    switch (currentAlgorithm) {
    case Algorithms::INTENSITY: {
        return Intensity(((pixel.r + pixel.g + pixel.b) / 3));
    }
    case Algorithms::VALUE: {
        return Intensity(std::max({ pixel.r, pixel.g, pixel.b }));
    }
    case Algorithms::LUMINANCE: {
        return Intensity(((pixel.r * 0.3) + (pixel.g * 0.59) + (pixel.b * 0.11)));
    }
    case Algorithms::LUMA: {
        return Intensity(((pixel.r * 0.2126) + (pixel.g * 0.7152) + (pixel.b * 0.0722)));
    }
    case Algorithms::LUSTER: {
        return Intensity(0.5 * (std::max({ pixel.r, pixel.g, pixel.b })) +
            std::min({ pixel.r, pixel.g, pixel.b }));
    }
    }
}

IntensityImage* StudentPreProcessing::stepToIntensityImage(
    const RGBImage& image) const {
    int height = image.getHeight();
    int width = image.getWidth();
    std::cout << "Student pre processing" << std::endl;
    IntensityImage* IntensityImage_ =
        ImageFactory::newIntensityImage(width, height);

    for (size_t i = 0; i < width; i++) {
        for (size_t j = 0; j < height; j++) {
            IntensityImage_->setPixel(i, j, doGrayScaling(image.getPixel(i, j)));
        }
    }

    return IntensityImage_;
}

IntensityImage* StudentPreProcessing::stepScaleImage(
    const IntensityImage& image) const {
    return nullptr;
}

IntensityImage* StudentPreProcessing::stepEdgeDetection(
    const IntensityImage& image) const {
    return nullptr;
}

IntensityImage* StudentPreProcessing::stepThresholding(
    const IntensityImage& image) const {
    return nullptr;
}