/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "PreProcessing.h"
#include "IntensityImageStudent.h"

class StudentPreProcessing : public PreProcessing {
public:
	enum class Algorithms { INTENSITY, VALUE, LUMINANCE, LIGHTNESS, LUSTER } : int {};
	IntensityImage * stepToIntensityImage(const RGBImage &image) const;
	IntensityImage * stepScaleImage(const IntensityImage &image) const;
	IntensityImage * stepEdgeDetection(const IntensityImage &image) const;
	IntensityImage * stepThresholding(const IntensityImage &image) const;
	Intensity doGrayScaling(RGB pixel) const;
	Algorithms currentAlgorithm = Algorithms::INTENSITY;
};