#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
	RGBPixelStorage.clear();
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	RGBPixelStorage.clear();
	for (int x = 0; x < (other.getWidth() * other.getHeight()); x++) {
		RGBPixelStorage.push_back(other.getPixel(x));
	}
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	RGBPixelStorage.clear();
	for (int x = 0; x < (width * height); x++) {
		RGBPixelStorage.push_back(NULL);
	}
}

RGBImageStudent::~RGBImageStudent() {
	RGBPixelStorage.clear();
}

void RGBImageStudent::set(const int width_, const int height_) {
	RGBImage::set(width_, height_);
	RGBPixelStorage.clear();

	for (int x = 0; x < (width_ * height_); x++) {
		RGBPixelStorage.push_back(NULL);
	}
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	set(other.getWidth(), other.getHeight());
	for (int x = 0; x < (other.getWidth() * other.getHeight()); x++) {
		RGBPixelStorage.push_back(other.getPixel(x));
	}
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	RGBPixelStorage[(y * Image::getWidth()) + x] = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	RGBPixelStorage[i] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {

	return RGBPixelStorage[(y* Image::getWidth()) + x];
}

RGB RGBImageStudent::getPixel(int i) const {
	return RGBPixelStorage[i];
}