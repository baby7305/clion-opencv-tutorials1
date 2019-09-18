// EXTRA Example 15-6, using OpenCV's background subtractor class.  Modified by Gary Bradski, 6/4/2017
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>

//C
#include <stdio.h>
//C++
#include <iostream>
#include <sstream>

using namespace cv;
using namespace std;
// Global variables
Mat frame; //current frame
Mat fgMaskMOG2; //fg mask fg mask generated by MOG2 method
Mat theBackground; //Will hold the current background image as seen from the model

Ptr<BackgroundSubtractor> pMOG2; //MOG2 Background subtractor
int keyboard; //input from keyboard
void help();

void processVideo(int train);

void processImages(int train);

void help() {
    cout
            << "\n-----------Taken from tutorial_background_subtraction.html---------------\n" << endl
            << "This program shows how to use background subtraction methods provided by " << endl
            << " OpenCV (BackgroundSubtractor class). " << endl
            << "You can process both videos (-vid) and images (-img)." << endl
            << "   We pass it #framesTraining which is the number of frames or images to train on before starting background subtraction\n"
            << endl
            << "Usage:" << endl
            << "./example_15-BackgroundSubtractor {<#framesTraining> -vid <video filename>|-img <image filename>}\n"
            << endl
            << "for example: ./example_15-BackgroundSubtractor 50 -vid ../tree.avi" << endl
            << "or: ./example_15-BackgroundSubtractor 20 -img /data/images/1.png" << endl
            << "\n" << endl
            << "This file demonstrates the MOG2 class, you can go to opencv docs to see" << endl
            << "other techniques. Each technique has it's own way of setting thresholds etc." << endl
            << "We keep it generic here, so the results are mediocre. You must go in and" << endl
            << "look up how to set the particular thresholds etc to get good results!" << endl
            << "--------------------------------------------------------------------------" << endl
            << endl;
}

int main() {
    //print help information
    help();
    //check for the input parameter correctness

    //create GUI windows
    namedWindow("Frame");
    namedWindow("theBackground");
    namedWindow("FG Mask MOG 2");

    int number_to_train_on = 20; //Read the number of frames to train on

    //create Background Subtractor objects
    pMOG2 = createBackgroundSubtractorMOG2(); //MOG2 approach
    if (strcmp("-img", "-img") == 0) {
        //input data coming from a sequence of images
        processImages(number_to_train_on);
    } else {
        //error in reading input parameters
        cerr << "Please, check the input parameters." << endl;
        cerr << "Exiting..." << endl;
        return EXIT_FAILURE;
    }

    //destroy GUI windows
    destroyAllWindows();
    return EXIT_SUCCESS;
}

void processVideo(int train) {
    //create the capture object
    VideoCapture capture("C:\\opencv\\Learning-OpenCV-3_examples-master//tree.avi");
    if (!capture.isOpened()) {
        //error in opening the video input
        cerr << "Unable to open video file: " << "C:\\opencv\\Learning-OpenCV-3_examples-master//tree.avi" << endl;
        exit(EXIT_FAILURE);
    }
    //read input data. ESC or 'q' for quitting
    double learning_rate = 0.1;
    int frame_count = 0;
    while ((char) keyboard != 'q' && (char) keyboard != 27) {
        //read the current frame
        if (!capture.read(frame)) {
            cerr << "Unable to read next frame." << endl;
            cerr << "Exiting..." << endl;
            exit(EXIT_FAILURE);
        }
        frame_count = int(capture.get(CAP_PROP_POS_FRAMES)); //get frame#
        //update the background model
        //
        //NOTE: This file just demonstrates the generic methods, each class
        //      Has specific ways of setting thresholds etc to make it work well.
        //      You must go into the documentation (for MOG2, see classcv_1_1BackgroundSubtractorMOG2
        //      if you want to get good results!
        //
        if (frame_count == train) { learning_rate = 0; } //stop learning after training
        pMOG2->apply(frame, fgMaskMOG2, learning_rate);
        //get the frame number and write it on the current frame
        stringstream ss;
        rectangle(frame, cv::Point(10, 2), cv::Point(100, 20),
                  cv::Scalar(255, 255, 255), -1);
        ss << capture.get(CAP_PROP_POS_FRAMES);
        string frameNumberString = ss.str();
        putText(frame, frameNumberString.c_str(), cv::Point(15, 15),
                FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));
        //show the current frame and the fg masks
        imshow("Frame", frame);
        imshow("FG Mask MOG 2", fgMaskMOG2);
        pMOG2->getBackgroundImage(theBackground); //Get an image of the model's background
        imshow("theBackground", theBackground);

/* By uncommenting this, you can write out the mask images        
		string imageToSave = "output_MOG_" + frameNumberString + ".png";
		bool saved = imwrite(imageToSave, fgMaskMOG);
		if(!saved) {
		  cerr << "Unable to save " << imageToSave << endl;
		}        
*/
        //get the input from the keyboard
        if (frame_count >= train) {
            cout << "\nHit any key to continue\n" << endl;
            keyboard = waitKey(); //single step with keyboard press in run mode
        } else {
            keyboard = waitKey(10); //run automatically in train mode
        }
    }
    //delete capture object
    capture.release();
}

void processImages(int train) {
    //read the first file of the sequence
    frame = imread("C:\\opencv\\Learning-OpenCV-3_examples-master//shape_sample//1.png");
    if (frame.empty()) {
        //error in opening the first image
        cerr << "Unable to open first image frame: "
             << "C:\\opencv\\Learning-OpenCV-3_examples-master//shape_sample//1.png"
             << endl;
        exit(EXIT_FAILURE);
    }
    //current image filename
    string fn("C:\\opencv\\Learning-OpenCV-3_examples-master//shape_sample//1.png");
    //read input data. ESC or 'q' for quitting
    double learning_rate = 0.1;
    int frame_count = 0;
    while ((char) keyboard != 'q' && (char) keyboard != 27) {

        //update the background model
        //
        //NOTE: This file just demonstrates the generic methods, each class
        //      Has specific ways of setting thresholds etc to make it work well.
        //      You must go into the documentation (for MOG2, see classcv_1_1BackgroundSubtractorMOG2
        //      if you want to get good results!
        //
        if (frame_count == train) { learning_rate = 0; } //stop learning after training
        pMOG2->apply(frame, fgMaskMOG2, learning_rate);
        //get the frame number and write it on the current frame
        size_t index = fn.find_last_of("/");
        if (index == string::npos) {
            index = fn.find_last_of("\\");
        }
        size_t index2 = fn.find_last_of(".");
        string prefix = fn.substr(0, index + 1);
        string suffix = fn.substr(index2);
        string frameNumberString = fn.substr(index + 1, index2 - index - 1);
        istringstream iss(frameNumberString);
        int frameNumber = 0;
        iss >> frameNumber;
        rectangle(frame, cv::Point(10, 2), cv::Point(100, 20),
                  cv::Scalar(255, 255, 255), -1);
        putText(frame, frameNumberString.c_str(), cv::Point(15, 15),
                FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));
        //show the current frame and the fg masks
        imshow("Frame", frame);
        imshow("FG Mask MOG 2", fgMaskMOG2);
        pMOG2->getBackgroundImage(theBackground); //Get an image of the model's background
        imshow("theBackground", theBackground);

/* By uncommenting this, you can write out the mask images        
		string imageToSave = "output_MOG_" + frameNumberString + ".png";
		bool saved = imwrite(imageToSave, fgMaskMOG);
		if(!saved) {
		  cerr << "Unable to save " << imageToSave << endl;
		}        
*/

        //get the input from the keyboard
        if (frame_count >= train) {
            cout << "\nHit any key to continue\n" << endl;
            keyboard = waitKey(); //Single step with keyboard press in test mode
        } else {
            keyboard = waitKey(10); //Run automatically in train mode
        }
        frame_count += 1;
        //search for the next image in the sequence
        ostringstream oss;
        oss << (frameNumber + 1);
        string nextFrameNumberString = oss.str();
        string nextFrameFilename = prefix + nextFrameNumberString + suffix;
        //read the next frame
        frame = imread(nextFrameFilename);
        if (frame.empty()) {
            //error in opening the next image in the sequence
            cerr << "Unable to open image frame: " << nextFrameFilename << endl;
            exit(EXIT_FAILURE);
        }
        //update the path of the current frame
        fn.assign(nextFrameFilename);
    }
}
