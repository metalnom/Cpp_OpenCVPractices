// Mat 

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat mat1 = Mat::zeros(3, 4, CV_8UC1);

	for(int j = 0; j < mat1.rows; j++) {
		for(int i = 0; i < mat1.cols; i++) {
			mat1.at<uchar>(j, i)++;
		}
	}

	for(int j = 0; j < mat1.rows; j++) {
		uchar* p = mat1.ptr<uchar>(j);
		for(int i = 0; i < mat1.cols; i++) {
			p[i]++;
		}
	}

	for(MatIterator_<uchar> it = mat1.begin<uchar>(); it != mat1.end<uchar>(); ++it) {
		(*it)++;
	}

	cout << "mat1: \n" << mat1 << endl;

	return 0;

}
