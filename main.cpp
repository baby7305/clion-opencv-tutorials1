#include <QCoreApplication>
#include <QTemporaryDir>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    QTemporaryDir tempDir;
    const QString tempFile = tempDir.path() + "lianggongchunri_de_youyv-009.jpg";
    QFile::copy(":/lianggongchunri_de_youyv-009.jpg", tempFile);
    Mat srcImage = imread(tempFile.toStdString());
    if (!srcImage.data) {
        std::cout << "Image not loaded";
        return -1;
    }
    imshow("[img]", srcImage);
    waitKey(0);
    return 0;
}