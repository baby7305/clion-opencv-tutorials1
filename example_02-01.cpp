//Example 2-1. A simple OpenCV program that loads an image from disk and displays it
//on the screen
#include <opencv2/opencv.hpp>

int main() {

    cv::Mat srcImage = cv::imread("fruits.jpg");

    if (!srcImage.data) {
        std::cout << "Image not loaded";
        return -1;
    }

    cv::namedWindow("Example 2-1", cv::WINDOW_AUTOSIZE);
    cv::imshow("Example 2-1", srcImage);
    cv::waitKey(0);
    cv::destroyWindow("Example 2-1");

    return 0;
}
