#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	IntensityPixelStorage.clear();
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	IntensityPixelStorage.clear();
	for (int x = 0; x < (other.getWidth() * other.getHeight()); x++) {
		IntensityPixelStorage.push_back(other.getPixel(x));
	}
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	IntensityPixelStorage.clear();
	for (int x = 0; x < (width * height); x++) {
		IntensityPixelStorage.push_back(NULL);
	}

}

IntensityImageStudent::~IntensityImageStudent() {
	IntensityPixelStorage.clear();
}

void IntensityImageStudent::set(const int width_, const int height_) {
	IntensityImage::set(width_, height_);
	
	IntensityPixelStorage.clear();
	for (int x = 0; x < (width_ * height_); x++) {
		IntensityPixelStorage.push_back(NULL);
	}
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	set(other.getWidth(), other.getHeight());
	for (int x = 0; x < (other.getWidth() * other.getHeight()); x++) {
		IntensityPixelStorage.push_back(other.getPixel(x));
	}
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