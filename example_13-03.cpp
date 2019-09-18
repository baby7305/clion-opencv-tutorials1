// Example 13-3. Template matching

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

// Display the results of the matches
//
int main() {

    cv::Mat src, templ, ftmp[6];   // ftmp is what to display on

    // Read in the template to be used for matching:
    //
    if ((templ = cv::imread("../BlueCup.jpg")).empty()) {
        cout << "Error on reading template " << "../BlueCup.jpg" << endl;
        return -1;
    }

    // Read in the source image to be searched:
    //
    if ((src = cv::imread("../adrian.jpg")).empty()) {
        cout << "Error on reading src image " << "../adrian.jpg" << endl;
        return -1;
    }

    // Do the matching of the template with the image
    for (int i = 0; i < 6; ++i) {
        cv::matchTemplate(src, templ, ftmp[i], i);
        cv::normalize(ftmp[i], ftmp[i], 1, 0, cv::NORM_MINMAX);
    }

    // Display
    //
    cv::imshow("Template", templ);
    cv::imshow("Image", src);
    cv::imshow("SQDIFF", ftmp[0]);
    cv::imshow("SQDIFF_NORMED", ftmp[1]);
    cv::imshow("CCORR", ftmp[2]);
    cv::imshow("CCORR_NORMED", ftmp[3]);
    cv::imshow("CCOEFF", ftmp[4]);
    cv::imshow("CCOEFF_NORMED", ftmp[5]);

    // Let user view results:
    //
    cv::waitKey(0);
}

