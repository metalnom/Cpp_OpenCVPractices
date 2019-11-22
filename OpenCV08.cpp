// Mat 클래스
// 행렬 정보 참조하기 


#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	Mat img1 = imread("/home/metalnom/eclipse-workspace/OpenCV01/Debug/lenna.tif");

	cout << "Width : " << img1.cols << endl;
	cout << "Height : " << img1.rows << endl;
	cout << "Channel : " << img1.channels() << endl;

	if(img1.type() == CV_8UC1)
		cout << "the picture is a grayscale image." << endl;
	else if(img1.type() == CV_8UC3)
		cout << "the picture is a truecolor image." << endl;

	float data[] = {2.f, 1.414f, 3.f, 1.732f};
	Mat mat1(2, 2, CV_32FC1, data);
	cout << "mat1 : \n" << mat1 << endl;

	return 0;

}
