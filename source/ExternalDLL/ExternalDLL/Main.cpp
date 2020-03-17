/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#include <iostream> //std::cout
#include <sstream>
#include <fstream>
#include <string>
#include "ImageIO.h" //Image load and save functionality
#include "HereBeDragons.h"
#include "ImageFactory.h"
#include "DLLExecution.h"
#include "RGBImageStudent.h"

void drawFeatureDebugImage(IntensityImage &image, FeatureMap &features);
bool executeSteps(DLLExecution * executor, int & pictureHitrate);

int test(int argc, char* argv[]) {

	//ImageFactory::setImplementation(ImageFactory::DEFAULT);
	ImageFactory::setImplementation(ImageFactory::STUDENT);

//	ImageIO::debugFolder = "C:\\Users\\ties1\\OneDrive\\Bureaublad\\STUDIE\\HBO-ICT jaar 2019-2020\\Vision\\Github repo\\HU-Vision-Ties-Mick\\source\\ExternalDLL\\OutputFolder";

	//std::string picturelocation = "C:\\Users\\mickb\\source\\repos\\Tiesbrouwer10\\HU-Vision-Ties-Mick\\testsets\\Set D Resolution\\Child- resolution\\";
	std::string picturelocation = "C:\\Users\\ties1\\OneDrive\\Bureaublad\\STUDIE\\HBO-ICT jaar 2019-2020\\Vision\\Github repo\\HU-Vision-Ties-Mick\\testsets\\Set C Lightness\\Man - Lightness\\";
	std::ofstream debugoutput(picturelocation + "Intensity.csv");

	ImageIO::debugFolder = picturelocation;
	ImageIO::isInDebugMode = true; //If set to false the ImageIO class will skip any image save function calls

	
	std::string pictureName = "";

	RGBImage* input = ImageFactory::newRGBImage();


	debugoutput << "LIGHTNESS METINGEN" << std::endl <<
		"Algoritme 1" << std::endl
		<< "," << "Localization Steps" << "," << "," << "," << "," << "," << "Extraction Steps" << "," << "," << "," << "," << "Postprocessing" << "," << "Representation" << "," << "Hit ratio" << std::endl <<
		"Picture" << "," << "Prep" << "," << "1" << "," << "2" << "," << "3" << "," << " 4" << "," << "5" << "," << "Prep" << "," << "1" << "," << "2" << "," << "3" << "," << " 1" << "," << "1" << std::endl;



	for (int testPicture = 42; testPicture < 43; testPicture++) {

		std::cout << "Currently working on picture: " + std::to_string(testPicture) << std::endl;
		pictureName = "Man (" + std::to_string(testPicture) + ").png";

		if (!ImageIO::loadImage(picturelocation + pictureName, *input)) {
			std::cout << "Image could not be loaded!" << std::endl;
			system("pause");
			return 0;
		}

		ImageIO::saveRGBImage(*input, ImageIO::getDebugFileName("Debug.png"));

		DLLExecution* executor = new DLLExecution(input);
		int pictureHitrate = 0;

		if (executeSteps(executor, pictureHitrate)) {
			std::cout << "Face recognition successful!" << std::endl;
			std::cout << "Facial parameters: " << std::endl;
			for (int i = 0; i < 16; i++) {
				std::cout << (i + 1) << ": " << executor->facialParameters[i] << std::endl;
			}
			
		}
		debugoutput << pictureName << ", ";
		
		for (int stepHits = 0; stepHits < pictureHitrate; stepHits++) {
			debugoutput << "1" << ",";
		}
		for (int missedSteps = 12 - pictureHitrate; missedSteps >= 0; missedSteps--) {
			debugoutput << "0" << ",";
		}

		debugoutput << "( " << pictureHitrate << " / 12 )" << std::endl;


		delete executor;
		pictureHitrate = 0;
	}








		////for (int pictureN = 10; pictureN < 101; pictureN++) {
		//int pictureN = 50;

		//	std::cout << "little bit forther than halfway there" << std::endl;
		//	picturename = "Child (" + std::to_string(pictureN) + ").png";
		//	//	if (!ImageIO::loadImage("C:\\Users\\ties1\\OneDrive\\Bureaublad\\STUDIE\\HBO-ICT jaar 2019-2020\\Vision\\Github repo\\HU-Vision-Ties-Mick\\testsets\\Set A\\TestSet Images\\child-1.png", *input)) {
		//	if (!ImageIO::loadImage(picturelocation + picturename, *input)) {
		//		std::cout << "Image could not be loaded!" << std::endl;
		//		system("pause");
		//		return 0;
		//	}

		//	ImageIO::saveRGBImage(*input, ImageIO::getDebugFileName("Debug.png"));

		//	DLLExecution* executor = new DLLExecution(input);
		//
		//	int hitrate = 0;
		//	//for (int j = 0; j < 10; j++) {
		//		if (executeSteps(executor)) {
		//			std::cout << "Face recognition successful!" << std::endl;
		//			std::cout << "Facial parameters: " << std::endl;
		//			for (int i = 0; i < 16; i++) {
		//				std::cout << (i + 1) << ": " << executor->facialParameters[i] << std::endl;
		//			}
		//			hitrate++;
		//		}
		//	//}
		//	debugoutput << picturename << ", " << hitrate << std::endl;

		//	delete executor;
		////}

	system("pause");
	return 1;
}


int main(int argc, char* argv[]) {
	try {
		test(argc, argv);
	}
	catch (cv::Exception & e) {
		std::cerr << e.msg << std::endl;
	}
}





bool executeSteps(DLLExecution * executor, int& pictureHitrate) {
	std::cout << "entered executeStepts function" << std::endl;

	//Execute the four Pre-processing steps
	if (!executor->executePreProcessingStep1(false)) {
		std::cout << "Pre-processing step 1 failed!" << std::endl;
		return false;
	}
	std::cout << "After PreProcessing step 1" << std::endl;


	if (!executor->executePreProcessingStep2(false)) {
		std::cout << "Pre-processing step 2 failed!" << std::endl;
		return false;
	}
	std::cout << "After PreProcessing step 2" << std::endl;

	ImageIO::saveIntensityImage(*executor->resultPreProcessingStep2, ImageIO::getDebugFileName("Pre-processing-2.png"));

	if (!executor->executePreProcessingStep3(false)) {
		std::cout << "Pre-processing step 3 failed!" << std::endl;
		return false;
	}
	ImageIO::saveIntensityImage(*executor->resultPreProcessingStep3, ImageIO::getDebugFileName("Pre-processing-3.png"));

	if (!executor->executePreProcessingStep4(false)) {
		std::cout << "Pre-processing step 4 failed!" << std::endl;
		return false;
	}
	ImageIO::saveIntensityImage(*executor->resultPreProcessingStep4, ImageIO::getDebugFileName("Pre-processing-4.png"));



	//Execute the localization steps
	if (!executor->prepareLocalization()) {
		std::cout << "Localization preparation failed!" << std::endl;
		return false;
	}
	pictureHitrate++;

	if (!executor->executeLocalizationStep1(false)) {
		std::cout << "Localization step 1 failed!" << std::endl;
		return false;
	}
	pictureHitrate++;
	if (!executor->executeLocalizationStep2(false)) {
		std::cout << "Localization step 2 failed!" << std::endl;
		return false;
	}
	pictureHitrate++;
	if (!executor->executeLocalizationStep3(false)) {
		std::cout << "Localization step 3 failed!" << std::endl;
		return false;
	}
	pictureHitrate++;
	if (!executor->executeLocalizationStep4(false)) {
		std::cout << "Localization step 4 failed!" << std::endl;
		return false;
	}
	pictureHitrate++;
	if (!executor->executeLocalizationStep5(false)) {
		std::cout << "Localization step 5 failed!" << std::endl;
		return false;
	}
	pictureHitrate++;


	//Execute the extraction steps
	if (!executor->prepareExtraction()) {
		std::cout << "Extraction preparation failed!" << std::endl;
		return false;
	}
	pictureHitrate++;
	if (!executor->executeExtractionStep1(false)) {
		std::cout << "Extraction step 1 failed!" << std::endl;
		return false;
	}
	pictureHitrate++;
	if (!executor->executeExtractionStep2(false)) {
		std::cout << "Extraction step 2 failed!" << std::endl;
		return false;
	}
	std::cout << "made it to all extraction steps" << std::endl;
	pictureHitrate++;
	if (!executor->executeExtractionStep3(false)) {
		std::cout << "Extraction step 3 failed!" << std::endl;
		return false;
	}
	pictureHitrate++;
	//Post processing and representation
	if (!executor->executePostProcessing()) {
		std::cout << "Post-processing failed!" << std::endl;
		return false;
	}
	pictureHitrate++;
	drawFeatureDebugImage(*executor->resultPreProcessingStep1, executor->featuresScaled);

	if (!executor->executeRepresentation()) {
		std::cout << "Representation failed!" << std::endl;
		return false;
	}
	pictureHitrate++;
	std::cout << "made it to the end" << std::endl;
	return true;
}

void drawFeatureDebugImage(IntensityImage &image, FeatureMap &features) {
	RGB colorRed(244, 67, 54);
	RGBImage * debug = ImageFactory::newRGBImage(image.getWidth(), image.getHeight());
	ImageIO::intensityToRGB(image, *debug);

	//Nose
	Point2D<double> noseLeft = features.getFeature(Feature::FEATURE_NOSE_END_LEFT)[0];
	Point2D<double> noseRight = features.getFeature(Feature::FEATURE_NOSE_END_RIGHT)[0];
	Point2D<double> nostrilLeft = features.getFeature(Feature::FEATURE_NOSTRIL_LEFT)[0];
	Point2D<double> nostrilRight = features.getFeature(Feature::FEATURE_NOSTRIL_RIGHT)[0];
	Point2D<double> noseBottom = features.getFeature(Feature::FEATURE_NOSE_BOTTOM)[0];


	//These (weird) methods can be used to draw debug points
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, noseLeft, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, noseRight, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, nostrilLeft, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, nostrilRight, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, noseBottom, colorRed);

	//Chin
	std::vector<Point2D<double>> points = features.getFeature(Feature::FEATURE_CHIN_CONTOUR).getPoints();
	for (size_t i = 0; i < points.size(); i++) {
		HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, points[i], colorRed);
	}

	//Eye
	Feature leftEye = features.getFeature(Feature::FEATURE_EYE_LEFT_RECT);
	Feature rightEye = features.getFeature(Feature::FEATURE_EYE_RIGHT_RECT);


	//These (weird) methods can be used to draw debug rects
	HereBeDragons::AsHisTriumphantPrizeProudOfThisPride(*debug, leftEye[0], leftEye[1], colorRed);
	HereBeDragons::AsHisTriumphantPrizeProudOfThisPride(*debug, rightEye[0], rightEye[1], colorRed);


	//Head
	Feature headTop = features.getFeature(Feature::FEATURE_HEAD_TOP);
	Feature headLeftNoseMiddle = features.getFeature(Feature::FEATURE_HEAD_LEFT_NOSE_MIDDLE);
	Feature headLeftNoseBottom = features.getFeature(Feature::FEATURE_HEAD_LEFT_NOSE_BOTTOM);
	Feature headRightNoseMiddle = features.getFeature(Feature::FEATURE_HEAD_RIGHT_NOSE_MIDDLE);
	Feature headRightNoseBottom = features.getFeature(Feature::FEATURE_HEAD_RIGHT_NOSE_BOTTOM);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, headTop[0], colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, headLeftNoseMiddle[0], colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, headLeftNoseBottom[0], colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, headRightNoseMiddle[0], colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, headRightNoseBottom[0], colorRed);

	//Mouth
	Point2D<double> mouthTop = features.getFeature(Feature::FEATURE_MOUTH_TOP)[0];
	Point2D<double> mouthBottom = features.getFeature(Feature::FEATURE_MOUTH_BOTTOM)[0];
	Point2D<double> mouthLeft = features.getFeature(Feature::FEATURE_MOUTH_CORNER_LEFT)[0];
	Point2D<double> mouthRight = features.getFeature(Feature::FEATURE_MOUTH_CORNER_RIGHT)[0];

	//This (weird) method can be used to draw a debug line
	HereBeDragons::ButRisingAtThyNameDothPointOutThee(*debug, mouthLeft, mouthRight, colorRed);

	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, mouthTop, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, mouthBottom, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, mouthLeft, colorRed);
	HereBeDragons::TriumphInLoveFleshStaysNoFatherReason(*debug, mouthRight, colorRed);

	ImageIO::saveRGBImage(*debug, ImageIO::getDebugFileName("feature-points-debug.png"));
	delete debug;
}



//RGBImage* input = ImageFactory::newRGBImage();

	//std::cout << "little bit forther than halfway there" << std::endl;
	////	if (!ImageIO::loadImage("C:\\Users\\ties1\\OneDrive\\Bureaublad\\STUDIE\\HBO-ICT jaar 2019-2020\\Vision\\Github repo\\HU-Vision-Ties-Mick\\testsets\\Set A\\TestSet Images\\child-1.png", *input)) {
	//std::string filename = "C:\\Users\\mickb\\source\\repos\\Tiesbrouwer10\\HU-Vision-Ties-Mick\\testsets\\Set A\\TestSet Images\\";
	//int test = 1;
	//filename += "child-";
	//filename += std::to_string(test);
	//filename += ".png";
	//std::cout << filename;
	//if (!ImageIO::loadImage(filename, *input)) {
	//	std::cout << "Image could not be loaded!" << std::endl;
	//	system("pause");
	//	return 0;
	//}
	//std::cout << "3/4th there" << std::endl;


	//ImageIO::saveRGBImage(*input, ImageIO::getDebugFileName("debug.png"));

	//DLLExecution* executor = new DLLExecution(input);
	//std::cout << "almost done" << std::endl;

	//if (executeSteps(executor)) {
	//	std::cout << "Face recognition successful!" << std::endl;
	//	std::cout << "Facial parameters: " << std::endl;
	//	for (int i = 0; i < 16; i++) {
	//		std::cout << (i + 1) << ": " << executor->facialParameters[i] << std::endl;
	//	}
	//}

	//delete executor;