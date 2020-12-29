// Example 5-1. Complete program to alpha-blend the ROI starting at (0,0) in src2 with the ROI starting at (x,y) in src1
// alphablend <imageA> <image B> <x> <y> <<alpha> <beta>
//
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

    // Using the first two arguments, open up the image to be copied onto
    // (src1), and the image that will be copied from (src2).
    //
    cv::Mat src1 = cv::imread("faceTemplate.jpg");
    cv::Mat src2 = cv::imread("faces.png");

    int from_w = src1.size().width;
    int from_h = src1.size().height;
    int to_w = src2.size().width;
    int to_h = src2.size().height;


    if (!src1.empty() && !src2.empty()) {

        // Four more arguments tell where in src1 to paste the chunk taken from
        // src2. Note that the width and height also specify what portion of
        // src2 to actually use.
        //
        int x = 230;
        int y = 155;

        // Make sure we don't exceed bounds:
        if ((x < 0) || (y < 0) || (x > to_w - 1) || (y > to_h - 1) || (x + from_w > to_w - 1) || (y + from_h > to_h)) {
            cout << "\nError, at (x,y) (" << x << ", " << y << "), your input image [w,h] [" << from_w << ", "
                 << from_h << "] doesn't fit within the blend to image [w,h] [" << to_w << ", " << to_h << "]\n"
                 << endl;
            return -1;
        }

        // Two more arguments set the blending coefficients.
        //
        double alpha = 0.8;
        double beta = 0.2;

        cv::Mat roi1(src1, cv::Rect(0, 0, from_w - 1, from_h - 1)); //Just take the whole thing
        cv::Mat roi2(src2, cv::Rect(x, y, from_w - 1, from_h - 1));

        // Blend together the image src2 onto the image src1
        // at the specified location.
        //
        cv::addWeighted(roi1, alpha, roi2, beta, 0.0, roi2);

        // Create a window to shoow the result and show it.
        //
        cv::namedWindow("Alpha Blend", 1);
        cv::imshow("Alpha Blend", src2);

        // Leave the window up and runnnig until the user hits a key
        //
        cv::waitKey(0);

    }

    return 0;

}
