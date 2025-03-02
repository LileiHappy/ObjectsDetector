//
// Created by 李磊 on 2025/2/26.
//

#pragma once

#include <string>

#include "opencv2/opencv.hpp"

class IDisplayHandler {
public:
    virtual ~IDisplayHandler() = default;

    virtual void setEnable(const bool isEnable) = 0;

    virtual void showImageInfo(const cv::Mat& image) const = 0;

    virtual void showImage(const std::string& title, const cv::Mat& image, const bool isResultEnable = false) const = 0;

    virtual void showImage(const char titleFlag, const cv::Mat& image, const bool isResultEnable = false) const = 0;

    virtual void showImage(const char titleFlag, const std::string& prefix, const cv::Mat& image, const bool isResultEnable = false) const = 0;
};