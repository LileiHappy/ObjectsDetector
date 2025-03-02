//
// Created by 李磊 on 2025/2/27.
//
#include <iostream>

#include "ImagePreprocessingHandler.h"
#include "ImagePreprocessing.h"
#include "PreprocessingStep.h"
#include "../Util/DisplayHandler.h"

using namespace std::placeholders;

ImagePreprocessingHandler::ImagePreprocessingHandler() : m_configuration(), m_preprocessingFuncsMap() {
    auto resizeFunc = std::bind(&ImagePreprocessing::resize, &ImagePreprocessing::instance(), _1, _2, _3);
    m_preprocessingFuncsMap[PREPROCESSING_FUNC_RESIZE] = resizeFunc;
    auto gaussBlurFunc = std::bind(&ImagePreprocessing::gaussBlur, &ImagePreprocessing::instance(), _1, _2, _3);
    m_preprocessingFuncsMap[PREPROCESSING_FUNC_GAUSS_BLUR] = gaussBlurFunc;
    auto grayFunc = std::bind(&ImagePreprocessing::gray, &ImagePreprocessing::instance(), _1, _2, _3);
    m_preprocessingFuncsMap[PREPROCESSING_FUNC_GRAY] = grayFunc;
    auto dilateFunc = std::bind(&ImagePreprocessing::dilation, &ImagePreprocessing::instance(), _1, _2, _3);
    m_preprocessingFuncsMap[PREPROCESSING_FUNC_DILATE] = dilateFunc;
    auto erodeFunc = std::bind(&ImagePreprocessing::erode, &ImagePreprocessing::instance(), _1, _2, _3);
    m_preprocessingFuncsMap[PREPROCESSING_FUNC_ERODE] = erodeFunc;
    auto binaryFunc = std::bind(&ImagePreprocessing::binary, &ImagePreprocessing::instance(), _1, _2, _3);
    m_preprocessingFuncsMap[PREPROCESSING_FUNC_BINARY] = binaryFunc;
    auto enhanceFunc = std::bind(&ImagePreprocessing::enhanceContrast, &ImagePreprocessing::instance(), _1, _2, _3);
    m_preprocessingFuncsMap[PREPROCESSING_FUNC_ENHANCE_CONTRAST] = enhanceFunc;
    auto cannyFunc = std::bind(&ImagePreprocessing::canny, &ImagePreprocessing::instance(), _1, _2, _3);
    m_preprocessingFuncsMap[PREPROCESSING_FUNC_CANNY] = cannyFunc;
}

void ImagePreprocessingHandler::attachDetectConfiguration(const SingleDetectConfiguration &configuration) {
    m_configuration = configuration;
}

bool ImagePreprocessingHandler::preprocess(cv::Mat &resultImage, cv::Mat& originImage) const {
    const std::string path = m_configuration.getImagePath();
    originImage = cv::imread(path);
    if (originImage.empty()) {
        std::cout << "load pending detect image failed!" << std::endl;
        return false;
    }

    DisplayHandler::instance().setEnable(m_configuration.isPreprocessingImageShow());
    DisplayHandler::instance().showImageInfo(originImage);
    DisplayHandler::instance().showImage("originImage", originImage);

    const std::vector<std::pair<char, const std::vector<float>>> preprocessingSteps = m_configuration.getPreprocessingSteps();
    bool isResizeSkip = false;
    if (originImage.rows < 1000 || originImage.cols < 600) {
        isResizeSkip = true;
    }

    cv::Mat srcImage;
    originImage.copyTo(srcImage);
    int index = 1;
    for (const auto& step : preprocessingSteps) {
        if (isResizeSkip && step.first == PREPROCESSING_FUNC_RESIZE) {
            continue;
        }
        cv::Mat processingResultImage;
        m_preprocessingFuncsMap.at(step.first)(step.second, srcImage, processingResultImage);
        if (!isResizeSkip && step.first == PREPROCESSING_FUNC_RESIZE) {
            processingResultImage.copyTo(originImage);
        }
        DisplayHandler::instance().showImage(step.first,
                                             m_configuration.getImageName().append("_").append(std::to_string(index)).append("_"),
                                             processingResultImage);
        processingResultImage.copyTo(srcImage);
        ++index;
    }

    cv::Mat image;
    srcImage.copyTo(resultImage);
    return true;
}
