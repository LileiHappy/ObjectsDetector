//
// Created by 李磊 on 2025/2/27.
//

#pragma once

#include <opencv2/opencv.hpp>

#include "../Configuration/SingleDetectConfiguration.h"

class IImagePreprocessingHandler {
public:
    ~IImagePreprocessingHandler() = default;

    virtual void attachDetectConfiguration(const SingleDetectConfiguration& configuration) = 0;

    virtual bool preprocess(cv::Mat& resultImage, cv::Mat& originImage) const = 0;
};