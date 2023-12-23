#include <iostream>                        // std::cout
#include <opencv2/core/core.hpp>           // cv::Mat
#include <opencv2/imgcodecs/imgcodecs.hpp>     // cv::imread()
#include <opencv2/imgproc/imgproc.hpp>     // cv::Canny()
#include <opencv2/highgui/highgui.hpp>


using namespace std;
using namespace cv;

int main() {

	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDilate, imgErod;

	cvtColor(img,imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlur, Size(3,3), 4, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	
	Mat kennel = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(imgCanny, imgDilate, kennel);
	erode(imgDilate, imgErod, kennel);

	imshow("Image", img);
	imshow("Gray", imgGray);
	imshow("Blur", imgBlur);
	imshow("Canny", imgCanny);
	imshow("Dilation", imgDilate);
	imshow("Erod", imgErod);

	waitKey(0);

	return 0;
}