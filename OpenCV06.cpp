// 이미지 부분 추출
// 이미지 얕은 복사, 반전

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(void) {

	Mat img1 = imread("lenna.tif", IMREAD_COLOR);

	if(img1.empty()) {
		cerr << "Image load failed!" << endl;
		return -1;
	}

	Mat img2 = img1(Rect(200, 180, 180, 220));
	Mat img3 = img2.clone();
	img2 = ~img2;

	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);

	waitKey();
	destroyAllWindows();

	return 0;
}
