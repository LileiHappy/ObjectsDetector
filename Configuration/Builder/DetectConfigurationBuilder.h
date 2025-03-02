//
// Created by 李磊 on 2025/2/27.
//

#pragma once

#include <string>

#include "../DetectConfiguration.h"

class DetectConfigurationBuilder final {
public:
    DetectConfigurationBuilder();

    DetectConfigurationBuilder(const DetectConfigurationBuilder& other);

    DetectConfigurationBuilder& operator= (const DetectConfigurationBuilder& other);

    ~DetectConfigurationBuilder();

    DetectConfigurationBuilder& addDetectImagePath(const std::string& path);

    DetectConfigurationBuilder& addImagePreprocessingStore(const bool isEnable);

    DetectConfigurationBuilder& addPreprocessingImageShow(const bool isEnable);

    DetectConfigurationBuilder& addIdLabel(const bool isEnable);

    DetectConfigurationBuilder& addFeatureExtractFilterThreshold(const FeatureExtractFilterThreshold& threshold);

    DetectConfigurationBuilder& addResize(const int priority, const float scaleFactor);

    DetectConfigurationBuilder& addGaussBlur(const int priority, const int kernelSize);

    DetectConfigurationBuilder& addGray(const int priority);

    DetectConfigurationBuilder& addDilate(const int priority, const int kernelSize);

    DetectConfigurationBuilder& addErode(const int priority, const int kernelSize);

    DetectConfigurationBuilder& addBinary(const int priority, const int threshold);

    DetectConfigurationBuilder& addEnhance(const int priority);

    DetectConfigurationBuilder& addCanny(const int priority, const int thresholdLower, const int thresholdUpper);

    DetectConfigurationBuilder& finishDetectConfiguration();

    DetectConfiguration build() const;

private:
    void mayNewSingleDetectConfiguration();

private:
    DetectConfiguration m_detectConfigurations;
    SingleDetectConfiguration m_currentDetectConfiguration;
    bool m_isNewConfiguration;
};
