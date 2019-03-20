#include <iostream>
#include "stereosgbm.h"
#include <time.h>
using namespace cv;

int main()
{
	clock_t start, end;
	Mat img1 = imread("im06l.png", 0);
	Mat img2 = imread("im06r.png", 0);
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
	start = clock();
	sgbm(img1, img2, disp);//disp经过处理输出的是short类型
	end = clock();  //total time: 101.7762126638s(im06l.png)
	Mat disp8;
	disp.convertTo(disp8, CV_8U, 255 / (numberOfDisparities*16.));//转化成uchar显示

	//sgbm.GenerateFalseMap(disp8, color);
	// imshow("color", color);
	imwrite("./result/disp_mid_06.png", disp8);
	cout << "Total time: " << (double)(end-start)/CLOCKS_PER_SEC << ' s.' << endl;
	// imshow("disp8", disp8);
	system("pause");
	// waitKey(10);
	return 0;
}