#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	IntensityPixelStorage.clear();
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	IntensityPixelStorage.clear();
	IntensityPixelStorage.resize(other.getWidth() * other.getHeight(), Intensity());
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	IntensityPixelStorage.clear();
	IntensityPixelStorage.resize(width * height,Intensity());
}

IntensityImageStudent::~IntensityImageStudent() {
	IntensityPixelStorage.clear();
}

void IntensityImageStudent::set(const int width_, const int height_) {
	IntensityImage::set(width_, height_);
	IntensityPixelStorage.clear();
	IntensityPixelStorage.resize(width_ * height_, Intensity());
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	IntensityPixelStorage.clear();
	IntensityPixelStorage.resize(other.getWidth() * other.getHeight(), Intensity());
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	IntensityPixelStorage[(y * Image::getWidth()) + x] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	IntensityPixelStorage[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return IntensityPixelStorage[(y * Image::getWidth()) + x];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	return IntensityPixelStorage[i];
}