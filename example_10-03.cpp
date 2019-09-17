// Example 10-3. Threshold versus adaptive threshold
#include <opencv2/opencv.hpp>
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {

    // Process command line arguments
    //
    double fixed_threshold = 10;
    int threshold_type = 1 ? cv::THRESH_BINARY : cv::THRESH_BINARY_INV;
    int adaptive_method = 0 ? cv::ADAPTIVE_THRESH_MEAN_C
                            : cv::ADAPTIVE_THRESH_GAUSSIAN_C;
    int block_size = 15;
    double offset = 10;
    cv::Mat Igray = cv::imread("../faces.png", cv::IMREAD_GRAYSCALE);

    // Read in gray image.
    //
    if (Igray.empty()) {
        cout << "Can not load " << "../faces.png" << endl;
        return -1;
    }

    // Declare the output images.
    //
    cv::Mat It, Iat;

    // Thresholds.
    //
    cv::threshold(
            Igray,
            It,
            fixed_threshold,
            255,
            threshold_type);
    cv::adaptiveThreshold(
            Igray,
            Iat,
            255,
            adaptive_method,
            threshold_type,
            block_size,
            offset
    );

    // Show the results.
    //
    cv::imshow("Raw", Igray);
    cv::imshow("Threshold", It);
    cv::imshow("Adaptive Threshold", Iat);
    cv::waitKey(0);
    return 0;
}
