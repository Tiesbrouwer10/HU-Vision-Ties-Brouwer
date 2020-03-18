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
	//int throwError = 0, e = 1 / throwError;
	//TODO: delete allocated objects
}

void IntensityImageStudent::set(const int width_, const int height_) {
	IntensityImage::set(width_, height_);
	
	IntensityPixelStorage.clear();
	for (int x = 0; x < (width_ * height_); x++) {
		IntensityPixelStorage.push_back(NULL);
	}
	//int throwError = 0, e = 1 / throwError;
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	//IntensityImage::set(other.getWidth(), other.getHeight());

	set(other.getWidth(), other.getHeight());
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	IntensityPixelStorage[(y * Image::getWidth()) + x] = pixel;
	//TODO: no comment needed :)
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	IntensityPixelStorage[i] = pixel;
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

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	//TODO: no comment needed :)
	return IntensityPixelStorage[(y * Image::getWidth()) + x];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	//TODO: see setPixel(int i, RGB pixel)
	return IntensityPixelStorage[i];
}