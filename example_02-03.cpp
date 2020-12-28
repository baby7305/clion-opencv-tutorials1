// Example 2-3. A simple OpenCV program for playing a video file from disk

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;

int main(int argc, char **argv) {

    cv::namedWindow("Example 2-3", cv::WINDOW_AUTOSIZE);
    cv::VideoCapture cap;
    cap.open("tree.avi");
    cv::Mat frame;

    for (;;) {
        cap >> frame;
        if (frame.empty()) break; // Ran out of film
        cv::imshow("Example 2-3", frame);
        if ((char) cv::waitKey(33) >= 0) break;
    }

    return 0;

}
