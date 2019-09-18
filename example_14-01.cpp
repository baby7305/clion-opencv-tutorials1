// Example 14-1. Finding contours based on a trackbar’s location; the contours are
// updated whenever the trackbar is moved

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

cv::Mat g_gray, g_binary;
int g_thresh = 100;

void on_trackbar(int, void *) {
    cv::threshold(g_gray, g_binary, g_thresh, 255, cv::THRESH_BINARY);
    vector<vector<cv::Point> > contours;
    cv::findContours(
            g_binary,
            contours,
            cv::noArray(),
            cv::RETR_LIST,
            cv::CHAIN_APPROX_SIMPLE
    );
    g_binary = cv::Scalar::all(0);

    cv::drawContours(g_binary, contours, -1, cv::Scalar::all(255));
    cv::imshow("Contours", g_binary);

}

int main() {
    if ((g_gray = cv::imread("../fruits.jpg", 0)).empty()) {
        cout << "\nExample 14-1: Find threshold dependent contours\nUsage:\n"
             << " ../fruits.jpg\n" << endl;
        return -1;
    }
    cv::namedWindow("Contours", 1);

    cv::createTrackbar(
            "Threshold",
            "Contours",
            &g_thresh,
            255,
            on_trackbar
    );
    on_trackbar(0, 0);

    cv::waitKey();

    return 0;
}
