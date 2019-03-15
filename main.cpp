#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{

	Mat img1 = imread("D:/wh/GraduateFiles/dataset/data_stereo_flow/training/colored_0/000000_10.png", -1);
	Mat img2 = imread("D:/wh/GraduateFiles/dataset/data_stereo_flow/training/colored_1/000000_10.png", -1);
	imshow("left", img1);
	//waitKey(1000);
	imshow("right", img2);
	//waitKey(9000);
	system("pause");
	return 0;
}