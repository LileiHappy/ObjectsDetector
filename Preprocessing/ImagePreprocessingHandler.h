//
// Created by 李磊 on 2025/2/27.
//

#pragma once

#include <unordered_map>
#include <functional>
#include <opencv2/opencv.hpp>

#include "IImagePreprocessingHandler.h"
#include "../Singleton.h"
#include "../Configuration/SingleDetectConfiguration.h"

class ImagePreprocessingHandler : public Singleton<ImagePreprocessingHandler>, public IImagePreprocessingHandler {
public:
    void attachDetectConfiguration(const SingleDetectConfiguration &configuration) override;

    bool preprocess(cv::Mat &resultImage, cv::Mat& originImage) const override;

private:
    ImagePreprocessingHandler();

private:
    friend Singleton;

private:
    SingleDetectConfiguration m_configuration;
    std::unordered_map<char, std::function<void(const std::vector<float>&, const cv::Mat&, cv::Mat&)>> m_preprocessingFuncsMap;
};
