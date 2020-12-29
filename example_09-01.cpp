// Example 9-1. Creating a window and displaying an image in that window
//
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main() {

    // Create a named window with the name of the file
    //
    cv::namedWindow("Example 9-1", cv::WINDOW_AUTOSIZE);

    // Load the image from the given filename
    //
    cv::Mat img = cv::imread("fruits.jpg");

    // Show the image in the named window
    //
    cv::imshow("Example 9-1", img);

    // Idle until the user hits the Esc key
    //
    cv::waitKey(); //Any key will end the program

    // Clean up and don't be piggies
    //
    cv::destroyWindow("Example 9-1");
    exit(0);
}
