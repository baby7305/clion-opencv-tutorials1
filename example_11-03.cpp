// Example 11-3. Log-polar transform example
// Log-polar transform example.
// This demonstrates the forward and backward (inverse) log-polar
// transform.

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main() {

    cv::Mat src = cv::imread("../fruits.jpg");

    if (src.empty()) {
        cout << "Can not load " << "../fruits.jpg" << endl;
        return -1;
    }

    double M = 10;
    cv::Mat dst(src.size(), src.type()), src2(src.size(), src.type());

    cv::logPolar(
            src,
            dst,
            cv::Point2f(src.cols * 0.5f, src.rows * 0.5f),
            M,
            cv::INTER_LINEAR | cv::WARP_FILL_OUTLIERS
    );
    cv::logPolar(
            dst,
            src2,
            cv::Point2f(src.cols * 0.5f, src.rows * 0.5f),
            M,
            cv::INTER_LINEAR | cv::WARP_INVERSE_MAP
    );
    cv::imshow("log-polar", dst);
    cv::imshow("inverse log-polar", src2);

    cv::waitKey();

    return 0;
}
