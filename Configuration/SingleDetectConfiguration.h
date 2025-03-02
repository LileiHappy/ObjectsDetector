//
// Created by 李磊 on 2025/2/27.
//

#pragma once

#include <string>

#include "FeatureExtractFilterThreshold.h"
#include "ImagePreprocessingConfiguration.h"

class SingleDetectConfiguration {
public:
    SingleDetectConfiguration();

    SingleDetectConfiguration(const SingleDetectConfiguration& other);

    SingleDetectConfiguration& operator= (const SingleDetectConfiguration& other);

    ~SingleDetectConfiguration() = default;

    SingleDetectConfiguration& setImagePath(const std::string& path);

    std::string getImagePath() const;

    std::string getImageName() const;

    SingleDetectConfiguration& setImagePreprocessingStore(const bool isEnable);

    bool isImagePreprocessingStore() const;

    SingleDetectConfiguration& setPreprocessingImageShow(const bool isEnable);

    bool isPreprocessingImageShow() const;

    SingleDetectConfiguration& setIdLabel(const bool isEnable);

    bool isIdLabel() const;

    SingleDetectConfiguration& setFeatureExtractFilterThreshold(const FeatureExtractFilterThreshold& threshold);

    const FeatureExtractFilterThreshold& getFeatureExtractFilterThreshold() const;

    SingleDetectConfiguration& addResize(const int priority, const float scaleFactor);

    SingleDetectConfiguration& addGaussBlur(const int priority, const int kernelSize);

    SingleDetectConfiguration& addGray(const int priority);

    SingleDetectConfiguration& addDilate(const int priority, const int kernelSize);

    SingleDetectConfiguration& addErode(const int priority, const int kernelSize);

    SingleDetectConfiguration& addBinary(const int priority, const int threshold);

    SingleDetectConfiguration& addEnhance(const int priority);

    SingleDetectConfiguration& addCanny(const int priority, const int thresholdLower, const int thresholdUpper);

    std::vector<std::pair<char, const std::vector<float>>> getPreprocessingSteps() const;

private:
    void assign(const SingleDetectConfiguration& other);

private:
    std::string m_path;
    bool m_isImagePreprocessingStore;
    bool m_isPreprocessingImageShow;
    bool m_isIdLabel;
    FeatureExtractFilterThreshold m_featureExtractFilterThreshold;
    ImagePreprocessingConfiguration m_preprocessingConfiguration;
};
