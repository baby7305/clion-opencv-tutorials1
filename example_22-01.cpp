// Example 22-1. Detecting and drawing faces

#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <opencv2/opencv.hpp>
#include "opencv2/objdetect.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using std::cout;
using std::cerr;
using std::vector;
using std::string;

// Detect and draw detected object boxes on image
//
void detectAndDraw(
        cv::Mat &img,                               // input image
        cv::Ptr<cv::CascadeClassifier> classifier,  // preloaded classifier
        double scale = 1.3) {                       // resize image by ...
    // Just some pretty colors to draw with
    //
    enum {
        BLUE, AQUA, CYAN, GREEN
    };
    static cv::Scalar colors[] = {
            cv::Scalar(0, 0, 255),
            cv::Scalar(0, 128, 255),
            cv::Scalar(0, 255, 255),
            cv::Scalar(0, 255, 0)
    };
    // Image preparation:
    //
    cv::Mat gray(img.size(), CV_8UC1);
    cv::Mat small_img(cvSize(cvRound(img.cols / scale),
                             cvRound(img.rows / scale)), CV_8UC1);
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    cv::resize(gray, small_img, small_img.size(), 0.0, 0.0, cv::INTER_LINEAR);
    cv::equalizeHist(small_img, small_img);
    // Detect objects if any
    //
    vector<cv::Rect> objects;
    classifier->detectMultiScale(
            small_img,                  // input image
            objects,                    // place for the results
            1.1,                        // scale factor
            3,                          // minimum number of neighbors
            CV_HAAR_DO_CANNY_PRUNING,   // (old format cascades only)
            cv::Size(30, 30));          // throw away detections smaller than this

    // Loop through to found objects and draw boxes around them
    //
    int i = 0;
    for (vector<cv::Rect>::iterator r = objects.begin();
         r != objects.end(); r++, ++i) {
        cv::Rect r_ = (*r);
        r_.x *= scale;
        r_.y *= scale;
        r_.width *= scale;
        r_.height *= scale;
        cv::rectangle(img, r_, colors[i % 4]);
    }
}

int main() {
    // Program expects at least two arguments:
    //   - path to image file
    //   - path to .xml classifier file
    //
    string image_file_name = string("C:\\opencv\\Learning-OpenCV-3_examples-master//faces.png");
    cv::Mat img = cv::imread(image_file_name, CV_LOAD_IMAGE_COLOR);
    string cascade_file_name = string("C:\\opencv\\Learning-OpenCV-3_examples-master//haarcascade_frontalface_alt.xml");
    cv::Ptr<cv::CascadeClassifier> cascade(new cv::CascadeClassifier(cascade_file_name));
    detectAndDraw(img, cascade);
    cv::imshow("Result", img);
    cv::waitKey(0);

    return 0;
}
