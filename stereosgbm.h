#include"opencv2/opencv.hpp"
#include<iostream>
using namespace cv;
using namespace std;
namespace cv
{
	class myStereoSGBM
	{
	public:
		myStereoSGBM(int _minDisparity = 0, int _numDisparities = 0, int _SADWindowSize = 0,
			int _P1 = 0, int _P2 = 0, int _disp12MaxDiff = 0, int _preFilterCap = 0,
			int _uniquenessRatio = 0, int _speckleWindowSize = 0, int _speckleRange = 0,
			bool _fullDP = false);
		//	myStereoSGBM();
		virtual void operator()(cv::InputArray _left, InputArray _right, OutputArray _disp);
		void GenerateFalseMap(cv::Mat &src, cv::Mat &disp);
		~myStereoSGBM();

		enum { DISP_SHIFT = 4, DISP_SCALE = (1 << DISP_SHIFT) };
		int minDisparity;
		int numberOfDisparities;
		int SADWindowSize;
		int P1; int P2;
		int disp12MaxDiff;
		int preFilterCap;
		int uniquenessRatio;
		int speckleWindowSize;
		int speckleRange;
		bool fullDP;
	protected:
		Mat buffer;
	};
	void filterSpeckles(InputOutputArray _img, double _newval, int maxSpeckleSize, double _maxDiff, InputOutputArray __buf);
	void validateDisparity(InputOutputArray _disp, InputArray _cost, int minDisparity, int numberOfDisparities, int disp12MaxDiff);
	CvRect cvGetValidDisparityROI(CvRect roi1, CvRect roi2, int minDisparity, int numberOfDisparities, int SADWindowSize);
	//void cvValidateDisparity( CvArr* _disp, const CvArr* _cost, int minDisparity, int numberOfDisparities, int disp12MaxDiff ) ;
}