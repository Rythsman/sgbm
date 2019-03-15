#include <iostream>
#include "stereosgbm.h"
using namespace cv;

int main()
{

	Mat img1 = imread("000001.png", 0);
	Mat img2 = imread("000002.png", 0);
	// imshow("left", img1);
	// waitKey(10);

	cv::myStereoSGBM sgbm;

	int SADWindowSize = 5;
	sgbm.preFilterCap = 63;
	sgbm.SADWindowSize = SADWindowSize > 0 ? SADWindowSize : 3;
	int cn = img1.channels();
	int numberOfDisparities = 128;
	sgbm.P1 = 8 * cn*sgbm.SADWindowSize*sgbm.SADWindowSize;
	sgbm.P2 = 32 * cn*sgbm.SADWindowSize*sgbm.SADWindowSize;
	sgbm.minDisparity = 0;
	sgbm.numberOfDisparities = numberOfDisparities;
	sgbm.uniquenessRatio = 10;
	sgbm.speckleWindowSize = 100;
	sgbm.speckleRange = 10;
	sgbm.disp12MaxDiff = 1;
	Mat disp;
	sgbm(img1, img2, disp);//disp经过处理输出的是short类型
	Mat disp8, color(disp.size(), CV_8UC3);
	disp.convertTo(disp8, CV_8U, 255 / (numberOfDisparities*16.));//转化成uchar显示

	sgbm.GenerateFalseMap(disp8, color);
	// imshow("color", color);
	imwrite("im234.png", disp8);
	// imshow("disp8", disp8);
	
	// waitKey(10);
	return 0;
}