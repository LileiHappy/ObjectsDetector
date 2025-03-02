//
// Created by 李磊 on 2025/2/26.
//
#pragma once

//#include <utility>
#include <vector>

#include "../Entity/ParamPair.h"

class ImagePreprocessingConfiguration {
public:
    ImagePreprocessingConfiguration();

    ImagePreprocessingConfiguration(const ImagePreprocessingConfiguration& other);

    ImagePreprocessingConfiguration& operator= (const ImagePreprocessingConfiguration& other);

    ~ImagePreprocessingConfiguration() = default;

    ImagePreprocessingConfiguration& addResize(const int priority, const float scaleFactor);

    ImagePreprocessingConfiguration& addGaussBlur(const int priority, const int kernelSize);

    ImagePreprocessingConfiguration& addGray(const int priority);

    ImagePreprocessingConfiguration& addDilate(const int priority, const int kernelSize);

    ImagePreprocessingConfiguration& addErode(const int priority, const int kernelSize);

    ImagePreprocessingConfiguration& addBinary(const int priority, const int threshold);

    ImagePreprocessingConfiguration& addEnhance(const int priority);

    ImagePreprocessingConfiguration& addCanny(const int priority, const int thresholdLower, const int thresholdUpper);

    std::vector<std::pair<char, const std::vector<float>>> getPreprocessingSteps() const;

private:
    inline void maySortPreprocessingSteps() const;

private:
    bool m_isSorted;
//    std::vector<std::pair<int, std::pair<char, const std::vector<float>>>> m_preprocessingStepPairs;
    mutable std::vector<ParamPair> m_preprocessingStepPairs;
};
