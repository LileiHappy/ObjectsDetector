//
// Created by 李磊 on 2025/2/26.
//
#include <opencv2/opencv.hpp>

using namespace cv;

void ImagePreprocessing::resize(const std::vector<float>& scaleFactor, const cv::Mat &originImage, cv::Mat &image) const {
    const float factor = scaleFactor[0];
    cv::resize(originImage, image, Size(0, 0), factor, factor);
}

void ImagePreprocessing::gaussBlur(const std::vector<float>& kernelSize, const cv::Mat &originImage, cv::Mat &image) const {
    const int size = mayAdjustKernelSize(kernelSize);
    GaussianBlur(originImage, image, Size(size, size), 0);
}

void ImagePreprocessing::gray(const std::vector<float>&, const cv::Mat &originImage, cv::Mat &image) const {
    cvtColor(originImage, image, COLOR_BGR2GRAY);
}

void ImagePreprocessing::dilation(const std::vector<float>& kernelSize, const cv::Mat &originImage, cv::Mat &image) const {
    const int size = mayAdjustKernelSize(kernelSize);
    Mat kernel = cv::getStructuringElement(MORPH_RECT, Size(size, size), Point(-1, -1));
    dilate(originImage, image, kernel);
}

void ImagePreprocessing::erode(const std::vector<float>& kernelSize, const cv::Mat &originImage, cv::Mat &image) const {
    const int size = mayAdjustKernelSize(kernelSize);
    Mat kernel = cv::getStructuringElement(MORPH_RECT, Size(size, size), Point(-1, -1));
    cv::erode(originImage, image, kernel);
}

void ImagePreprocessing::binary(const std::vector<float>& threshold, const cv::Mat &originImage, cv::Mat &image) const {
    const int compareThreshold = static_cast<const int>(threshold[0]);
    cv::threshold(originImage, image, compareThreshold, 255, THRESH_BINARY);
}

void ImagePreprocessing::enhanceContrast(const std::vector<float>&, const cv::Mat &originImage, cv::Mat &image) const {
}

void ImagePreprocessing::canny(const std::vector<float>& thresholds, const Mat &originImage, Mat &image) const {
    const int thresholdLower = static_cast<int>(thresholds[0]);
    const int thresholdUpper = static_cast<int>(thresholds[1]);
    Canny(originImage, image, thresholdLower, thresholdUpper);
}

int ImagePreprocessing::mayAdjustKernelSize(const std::vector<float>& kernelSize) const {
    const int size = static_cast<const int>(kernelSize[0]);
    return size < MIN_KERNEL_SIZE ? MIN_KERNEL_SIZE : size;
}