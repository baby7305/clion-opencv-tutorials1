//Example 2-1. A simple OpenCV program that loads an image from disk and displays it
//on the screen
#include <opencv2/opencv.hpp>

using namespace cv;

int main() {

    Mat srcImage = cv::imread("fruits.jpg");

    if (!srcImage.data) {
        std::cout << "Image not loaded";
        return -1;
    }

    namedWindow("Example 2-1", cv::WINDOW_AUTOSIZE);
    imshow("Example 2-1", srcImage);
    waitKey(0);
    destroyWindow("Example 2-1");

    return 0;
}
