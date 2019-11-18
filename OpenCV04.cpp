// Mat 객체 생성
// 초기값 설정


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(void) {

	Mat img1(480, 640, CV_8UC1, Scalar(128));
	Mat img2(480, 640, CV_8UC3, Scalar(100, 100, 150));

	Mat img3;
	img3 = Mat::eye(20, 20, CV_8UC1) * 255;

	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);

	waitKey();

	return 0;
}
