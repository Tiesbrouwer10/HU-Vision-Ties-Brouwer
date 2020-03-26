#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
	RGBPixelStorage.clear();
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	RGBPixelStorage.clear();
	RGBPixelStorage.resize(other.getWidth() * other.getHeight());
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	RGBPixelStorage.clear();
	RGBPixelStorage.resize(width * height);
}

RGBImageStudent::~RGBImageStudent() {
	RGBPixelStorage.clear();
}

void RGBImageStudent::set(const int width_, const int height_) {
	RGBImage::set(width_, height_);
	RGBPixelStorage.clear();
	RGBPixelStorage.resize(width_ * height_);
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	RGBPixelStorage.clear();
	RGBPixelStorage.resize(other.getWidth() * other.getHeight());
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