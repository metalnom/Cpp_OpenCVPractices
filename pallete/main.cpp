#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


vector<Rect> icons;
Mat image, canvas;
int mouse_mode = 0, draw_mode = 0;
Point pt1, pt2;
Scalar Color(0, 0, 0);
int thickness = 3;
Range r1(0, 500), r2(120, 800);

#include "menu.hpp"
#include "icon_flag.hpp"
#include "draw.hpp"
#include "event.hpp"


void onTrackbar(int value, void*) {
    mouse_mode = 0;
}

int main() {
    image = Mat(500, 800, CV_8UC3, Scalar(255, 255, 255));
    place_icons(Size(60, 60));

    Rect last_icon = *(icons.end() - 1);
    Point start_pale = Point(0, last_icon.br().y + 5);

    icons.push_back(Rect(start_pale, Size(100, 100)));
    icons.push_back(Rect(start_pale + Point(105, 0), Size(15, 100)));

    create_hueIndex(icons[HUE_IDX]);
    create_palette(start_pale.y, icons[PALETTE]);

    imshow("canvas", image);
    setMouseCallback("canvas", onMouse);

    createTrackbar("thickness", "canvas", &thickness, 20, onTrackbar);

    while (1) {
        if(mouse_mode == 1) {
            draw(image, Color);
        }
        else if(mouse_mode == 3) {
            if(draw_mode == DRAW_BRUSH || draw_mode == ERASE) {
                draw(image, Color);
            }
            else {
                draw(image.clone(), Scalar(200, 200, 200));
            }
        }
        if(waitKey(30) == 27) break;
    }

    return 0;
}
