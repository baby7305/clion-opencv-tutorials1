// Example 2-6. Using cv::pyrDown() to create a new image that is half the width and
// height of the input image
#include <opencv2/opencv.hpp>

int main() {

    cv::Mat img1, img2;

    cv::namedWindow("Example 2-6-in", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("Example 2-6-out", cv::WINDOW_AUTOSIZE);

    img1 = cv::imread("faces.png");

    cv::imshow("Example 2-6-in", img1);
    cv::pyrDown(img1, img2);

    cv::imshow("Example 2-6-out", img2);
    cv::waitKey(0);

    return 0;

};
