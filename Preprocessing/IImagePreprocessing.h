//
// Created by 李磊 on 2025/2/26.
//

#pragma once

#include <opencv2/opencv.hpp>

enum class PreprocessStepPriority {
    P_1,
    P_2,
    P_3,
    P_4,
    P_5,
    P_6,
    P_7,
    P_8
};

class IImagePreprocessing {
public:
    virtual ~IImagePreprocessing() = default;

    virtual void resize(const std::vector<float>& scaleFactor, const cv::Mat& originImage, cv::Mat& image) const = 0;

    virtual void gaussBlur(const std::vector<float>& kernelSize, const cv::Mat& originImage, cv::Mat& image) const = 0;

    virtual void gray(const std::vector<float>&, const cv::Mat& originImage, cv::Mat& image) const = 0;

    virtual void dilation(const std::vector<float>& kernelSize, const cv::Mat& originImage, cv::Mat& image) const = 0;

    virtual void erode(const std::vector<float>& kernelSize, const cv::Mat& originImage, cv::Mat& image) const = 0;

    virtual void binary(const std::vector<float>& threshold, const cv::Mat& originImage, cv::Mat& image) const = 0;

    virtual void enhanceContrast(const std::vector<float>&, const cv::Mat& originImage, cv::Mat& image) const = 0;
    
    virtual void canny(const std::vector<float>& thresholds, const cv::Mat& originImage, cv::Mat& image) const = 0;
};
