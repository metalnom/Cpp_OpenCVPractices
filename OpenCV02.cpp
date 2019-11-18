// 윈도우 창 크기 변경



#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(void) {
	cout << "Hello OpenCV" << CV_VERSION << endl;
	int x, y;
	Mat img;
	img = imread("lenna.tif", IMREAD_GRAYSCALE);

	if(img.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	namedWindow("image", WINDOW_NORMAL);
	imshow("image", img);

	for(x=100, y=100;x<400;x++, y++) {
		moveWindow("image", x, y);
		waitKey(10);
	}
	for(;x<600;x++, y--) {
		moveWindow("image", x, y);
		waitKey(10);
	}
	for(;x<1000;x++, y++) {
		resizeWindow("image", x, y);
		waitKey(10);
	}

	waitKey(50);
	destroyAllWindows();

	return 0;
}
