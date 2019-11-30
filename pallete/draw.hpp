#ifndef DRAW_HPP
#define DRAW_HPP

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void draw(Mat image, Scalar color = Scalar(200, 200, 200)) {
    if(draw_mode == DRAW_RECTANGLE) {
        rectangle(image, pt1, pt2, color, thickness);
    }
    else if(draw_mode == DRAW_LINE) {
        line(image, pt1, pt2, color, thickness);
    }
    else if(draw_mode == DRAW_BRUSH) {
        line(image, pt1, pt2, color, thickness * 3);
        pt1 = pt2;
    }
    else if(draw_mode == ERASE) {
        line(image, pt1, pt2, Scalar(255, 255, 255), thickness * 5);
        pt1 = pt2;
    }
    else if(draw_mode == DRAW_CIRCLE) {
        Point2d pt3 = pt1 - pt2;
        int radius = (int)sqrt(pt3.x * pt3.x + pt3.y * pt3.y);
        circle(image, pt1, radius, color, thickness);
    }
    else if(draw_mode == DRAW_ELLIPSE) {
        Point2d center = (pt1 + pt2) / 2.0;
        Size size = (pt1 - pt2) / 2.0;
        size.width = abs(size.width);
        size.height = abs(size.height);
        ellipse(image, center, size, 0, 0, 360, color, thickness);
    }
    imshow("canvas", image);
}


void command(int mode) {
    if(mode == PALETTE) {
        float ratio1 = 256.0f / icons[PALETTE].width;
        float ratio2 = 256.0f / icons[PALETTE].height;

        Point pt = pt2 - icons[PALETTE].tl();
        int saturation = cvRound(pt.x * ratio1);
        int value = cvRound((icons[PALETTE].height - pt.y - 1) *ratio2);
        Scalar hsv(hue, saturation, value);

        Mat m_color = image(icons[COLOR]);
        m_color.setTo(hsv);
        cvtColor(m_color, m_color, COLOR_HSV2BGR);
        rectangle(image, icons[COLOR], Scalar(0, 0, 0), 1);

        Color = Scalar(m_color.at<Vec3b>(10, 10));
    }
    else if(mode == HUE_IDX) {
        create_palette(pt2.y, icons[PALETTE]);
    }
    else if(mode == CLEAR) {
        canvas = image(r1, r2);
        canvas.setTo(Scalar(255, 255, 255));
        mouse_mode = 0;
    }
    else if(mode == OPEN) {
        Mat tmp = imread("./lena_std.tif", 1);
        CV_Assert(tmp.data);
        canvas = image(r1, r2);
        resize(tmp, tmp, canvas.size());
        tmp.copyTo(canvas);
    }
    else if(mode == SAVE) {
        canvas = image(r1, r2);
        imwrite("./lena_std_save.tif", canvas);
    }
    else if(mode == PLUS) {
        canvas = image(r1, r2);
        canvas += Scalar(10, 10, 10);
    }
    else if(mode == MINUS) {
        canvas = image(r1, r2);
        canvas -= Scalar(10, 10, 10);
    }
    imshow("canvas", image);
}



#endif // DRAW_HPP
