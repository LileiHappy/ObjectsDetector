//
// Created by 李磊 on 2025/2/26.
//

#pragma once

#include <string>
#include <opencv2/opencv.hpp>

class IImageStorage {
public:
    virtual ~IImageStorage() = default;

    virtual void enableStorage(const bool isEnable) = 0;

    virtual void store(const cv::Mat& image, const std::string& fileName) const = 0;

    virtual void remove(const std::string& fileName) const = 0;

    virtual void removeAll() const = 0;
};