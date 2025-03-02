//
// Created by 李磊 on 2025/2/26.
//
#include <algorithm>

#include "ImagePreprocessingConfiguration.h"
#include "../Preprocessing/PreprocessingStep.h"

using namespace std;

ImagePreprocessingConfiguration::ImagePreprocessingConfiguration() : m_isSorted(false), m_preprocessingStepPairs() {}

ImagePreprocessingConfiguration::ImagePreprocessingConfiguration(const ImagePreprocessingConfiguration &other) :
        m_isSorted(other.m_isSorted), m_preprocessingStepPairs() {
    m_preprocessingStepPairs.clear();
//    std::copy(other.m_preprocessingStepPairs.cbegin(), other.m_preprocessingStepPairs.cend(), m_preprocessingStepPairs);
    m_preprocessingStepPairs = other.m_preprocessingStepPairs;
}

ImagePreprocessingConfiguration &
ImagePreprocessingConfiguration::operator=(const ImagePreprocessingConfiguration &other) {
    m_isSorted = other.m_isSorted;
    m_preprocessingStepPairs.clear();
    m_preprocessingStepPairs.shrink_to_fit();
    m_preprocessingStepPairs = other.m_preprocessingStepPairs;
    return *this;
}

ImagePreprocessingConfiguration &
ImagePreprocessingConfiguration::addResize(const int priority, const float scaleFactor) {
    ParamPair param{priority, PREPROCESSING_FUNC_RESIZE, vector<float>{scaleFactor}};
//    std::pair<char, const std::vector<float>> funcAndValuePair(PREPROCESSING_FUNC_RESIZE, scaleFactor);
//    std::pair<int, std::pair<char, const std::vector<float>>> preprocessingStep(priority, funcAndValuePair);
//    m_preprocessingStepPairs.emplace_back(std::move(preprocessingStep));
    m_preprocessingStepPairs.emplace_back(std::move(param));
    return *this;
}

ImagePreprocessingConfiguration &
ImagePreprocessingConfiguration::addGaussBlur(const int priority, const int kernelSize) {
//    std::pair<char, const std::vector<float>> funcAndValuePair(PREPROCESSING_FUNC_GAUSS_BLUR, kernelSize);
//    std::pair<int, std::pair<char, const std::vector<float>>> preprocessingStep(priority, funcAndValuePair);
//    m_preprocessingStepPairs.emplace_back(std::move(preprocessingStep));
    ParamPair param{priority, PREPROCESSING_FUNC_GAUSS_BLUR, vector<float>{static_cast<float>(kernelSize)}};
    m_preprocessingStepPairs.emplace_back(std::move(param));
    return *this;
}

ImagePreprocessingConfiguration &ImagePreprocessingConfiguration::addGray(const int priority) {
//    std::pair<char, const std::vector<float>> funcAndValuePair(PREPROCESSING_FUNC_GRAY, 0);
//    std::pair<int, std::pair<char, const std::vector<float>>> preprocessingStep(priority, funcAndValuePair);
//    m_preprocessingStepPairs.emplace_back(std::move(preprocessingStep));
    ParamPair param{priority, PREPROCESSING_FUNC_GRAY, vector<float>()};
    m_preprocessingStepPairs.emplace_back(std::move(param));
    return *this;
}

ImagePreprocessingConfiguration &ImagePreprocessingConfiguration::addDilate(const int priority, const int kernelSize) {
//    std::pair<char, const std::vector<float>> funcAndValuePair(PREPROCESSING_FUNC_DILATE, kernelSize);
//    std::pair<int, std::pair<char, const std::vector<float>>> preprocessingStep(priority, funcAndValuePair);
//    m_preprocessingStepPairs.emplace_back(std::move(preprocessingStep));
    ParamPair param{priority, PREPROCESSING_FUNC_DILATE, vector<float>{static_cast<float>(kernelSize)}};
    m_preprocessingStepPairs.emplace_back(std::move(param));
    return *this;
}

ImagePreprocessingConfiguration &ImagePreprocessingConfiguration::addErode(const int priority, const int kernelSize) {
//    std::pair<char, const std::vector<float>> funcAndValuePair(PREPROCESSING_FUNC_ERODE, kernelSize);
//    std::pair<int, std::pair<char, const std::vector<float>>> preprocessingStep(priority, funcAndValuePair);
//    m_preprocessingStepPairs.emplace_back(std::move(preprocessingStep));
    ParamPair param{priority, PREPROCESSING_FUNC_ERODE, vector<float>{static_cast<float>(kernelSize)}};
    m_preprocessingStepPairs.emplace_back(std::move(param));
    return *this;
}

ImagePreprocessingConfiguration &ImagePreprocessingConfiguration::addBinary(const int priority, const int threshold) {
//    std::pair<char, const std::vector<float>> funcAndValuePair(PREPROCESSING_FUNC_BINARY, threshold);
//    std::pair<int, std::pair<char, const std::vector<float>>> preprocessingStep(priority, funcAndValuePair);
//    m_preprocessingStepPairs.emplace_back(std::move(preprocessingStep));
    ParamPair param{priority, PREPROCESSING_FUNC_BINARY, vector<float>{static_cast<float>(threshold)}};
    m_preprocessingStepPairs.emplace_back(std::move(param));
    return *this;
}

ImagePreprocessingConfiguration &ImagePreprocessingConfiguration::addEnhance(const int priority) {
    return *this;
}

ImagePreprocessingConfiguration &
ImagePreprocessingConfiguration::addCanny(const int priority, const int thresholdLower, const int thresholdUpper) {
    std::vector<float> thresholds{static_cast<float>(thresholdLower), static_cast<float>(thresholdUpper)};
//    std::pair<char, const std::vector<float>> funcAndValuePair(PREPROCESSING_FUNC_BINARY,
//                                                               std::move(thresholds));
//    std::pair<int, std::pair<char, const std::vector<float>>> preprocessingStep(priority, funcAndValuePair);
//    m_preprocessingStepPairs.emplace_back(std::move(preprocessingStep));
    ParamPair param{priority, PREPROCESSING_FUNC_CANNY, thresholds};
    m_preprocessingStepPairs.emplace_back(std::move(param));
    return *this;
}

std::vector<pair<char, const vector<float>>> ImagePreprocessingConfiguration::getPreprocessingSteps() const {
    maySortPreprocessingSteps();
    vector<pair<char, const vector<float>>> preprocessingSteps;
    preprocessingSteps.reserve(m_preprocessingStepPairs.size());

    for (const auto &preprocessingStep: m_preprocessingStepPairs) {
        pair<char, const vector<float>> step{preprocessingStep.getFuncFlag(), preprocessingStep.getData()};
        preprocessingSteps.emplace_back(step);
//        preprocessingSteps.emplace_back(preprocessingStep.second);
    }
    return preprocessingSteps;
}

void ImagePreprocessingConfiguration::maySortPreprocessingSteps() const {
    if (m_isSorted) {
        return;
    }
    std::sort(
            m_preprocessingStepPairs.begin(), m_preprocessingStepPairs.end(),
            [](const auto &a, const auto &b) -> bool {
                return a.getPriority() < b.getPriority();
            }
//            [](const auto& a, const auto& b) -> bool {
//                return a.first < b.first;
//            }
    );
}
