#ifndef MENU_HPP
#define MENU_HPP

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


int hue;

void place_icons(Size size) {
    vector<string> icon_name = {
        "rect", "circle", "eclipe", "line", "brush", "eraser",
        "open", "save", "plus", "minus", "clear", "color"
    };
    int btn_rows = (int)cvCeil(icon_name.size() / 2.0);

    for(int i = 0, k = 0;i < btn_rows; i++) {
        for(int j = 0; j < 2; j++, k++) {
            Point pt(j * size.width, i * size.height);
            icons.push_back(Rect(pt, size));
            Mat icon = imread("./icon/" + icon_name[k] + ".jpg", 1);
            if(icon.empty()) continue;

            resize(icon, icon, size);
            icon.copyTo(image(icons[k]));
        }
    }
}


void create_hueIndex(Rect rect) {
    Mat m_hueIdx = image(rect);
    float ratio = 180.0f / rect.height;

    for(int i = 0; i < rect.height; i++) {
        Scalar hue_color(i * ratio, 255, 255);
        m_hueIdx.row(i).setTo(hue_color);
    }
    cvtColor(m_hueIdx, m_hueIdx, COLOR_HSV2BGR);
}


void create_palette(int pos_y, Rect rect_pale) {
    Mat m_palette = image(rect_pale);
    float ratio1 = 180.0f / rect_pale.height;
    float ratio2 = 256.0f / rect_pale.width;
    float ratio3 = 256.0f / rect_pale.height;

    hue = cvRound((pos_y - rect_pale.y) * ratio1);

    for(int i = 0; i < m_palette.rows; i++) {
        for(int j = 0; j < m_palette.cols; j++) {
            int saturation = cvRound(j * ratio2);
            int intensity = cvRound((m_palette.rows - i - 1) * ratio3);
            m_palette.at<Vec3b>(i, j) = Vec3b(hue, saturation, intensity);
        }
    }
    cvtColor(m_palette, m_palette, COLOR_HSV2BGR);
}


#endif // MENU_HPP
