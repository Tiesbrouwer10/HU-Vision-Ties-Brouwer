#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
	RGBPixelStorage.clear();
	std::cout << "RGBStudent made" << std::endl;
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	RGBPixelStorage.clear();
	for (int x = 0; x < (other.getWidth() * other.getHeight()); x++) {
		RGBPixelStorage.push_back(other.getPixel(x));
	}
	//TODO: Create a copy from the other object
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	RGBPixelStorage.clear();
	//TODO: Initialize pixel storage
}

RGBImageStudent::~RGBImageStudent() {
	RGBPixelStorage.clear();
	//int throwError = 0, e = 1 / throwError;
	//TODO: delete allocated objects
}

void RGBImageStudent::set(const int width_, const int height_) {
	RGBImage::set(width_, height_);
	RGBPixelStorage.clear();

	for (int x = 0; x < (width_ * height_); x++) {
		RGBPixelStorage.push_back(NULL);
	}

	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	set(other.getWidth(), other.getHeight());
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	RGBPixelStorage[(y * Image::getWidth()) + x] = pixel;
	//TODO: no comment needed :)
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	std::cout << "for some reason komt hij in de tweede setPixel functie" << std::endl;
	RGBPixelStorage[i] = pixel;

	/*
	* TODO: set pixel i in "Row-Major Order"
	*
	*
	* Original 2d image (values):
	* 9 1 2
	* 4 3 5
	* 8 7 8
	*
	* 1d representation (i, value):
	* i		value
	* 0		9
	* 1		1
	* 2		2
	* 3		4
	* 4		3
	* 5		5
	* 6		8
	* 7		7
	* 8		8
	*/
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	
	//TODO: no comment needed :)
	return RGBPixelStorage[(y* Image::getWidth()) + x];
}

RGB RGBImageStudent::getPixel(int i) const {
	return RGBPixelStorage[i];
	//TODO: see setPixel(int i, RGB pixel)
}