//
// Created by 李磊 on 2025/2/27.
//
#include <algorithm>

#include "SingleDetectConfiguration.h"
#include "../Util/PlatformSupporter.h"

SingleDetectConfiguration::SingleDetectConfiguration() :
        m_path(),
        m_isImagePreprocessingStore(false),
        m_isPreprocessingImageShow(false),
        m_isIdLabel(false),
        m_featureExtractFilterThreshold(),
        m_preprocessingConfiguration() {}

SingleDetectConfiguration::SingleDetectConfiguration(const SingleDetectConfiguration &other) :
        m_path(other.m_path),
        m_isImagePreprocessingStore(other.m_isImagePreprocessingStore),
        m_isPreprocessingImageShow(other.m_isPreprocessingImageShow),
        m_isIdLabel(other.m_isIdLabel),
        m_featureExtractFilterThreshold(other.m_featureExtractFilterThreshold),
        m_preprocessingConfiguration(other.m_preprocessingConfiguration) {
}

void SingleDetectConfiguration::assign(const SingleDetectConfiguration &other) {
    m_path = other.m_path;
    m_isImagePreprocessingStore = other.m_isImagePreprocessingStore;
    m_isPreprocessingImageShow = other.m_isPreprocessingImageShow;
    m_isIdLabel = other.m_isIdLabel;
    m_featureExtractFilterThreshold = other.m_featureExtractFilterThreshold;
    m_preprocessingConfiguration = other.m_preprocessingConfiguration;
}

SingleDetectConfiguration &SingleDetectConfiguration::operator=(const SingleDetectConfiguration &other) {
    assign(other);
    return *this;
}

SingleDetectConfiguration &SingleDetectConfiguration::setImagePath(const std::string &path) {
    m_path = path;
    return *this;
}

std::string SingleDetectConfiguration::getImagePath() const {
    return m_path;
}

std::string SingleDetectConfiguration::getImageName() const {
    std::string fileName;
    if (m_path.empty()) {
        fileName.append("result_image");
    } else {
        std::string::size_type separatorIndex = m_path.find_last_of(PlatformSupporter::getFilePathSeparator());
        separatorIndex = separatorIndex == std::string::npos ? 0 : separatorIndex;
        std::string::size_type dotIndex = m_path.find_last_of('.');
        dotIndex = dotIndex == std::string::npos ? m_path.size() : dotIndex;
        fileName = m_path.substr(separatorIndex + 1, dotIndex - separatorIndex - 1);
    }
    return fileName;
}

SingleDetectConfiguration &SingleDetectConfiguration::setImagePreprocessingStore(const bool isEnable) {
    m_isImagePreprocessingStore = isEnable;
    return *this;
}

bool SingleDetectConfiguration::isImagePreprocessingStore() const {
    return m_isImagePreprocessingStore;
}

SingleDetectConfiguration &SingleDetectConfiguration::setPreprocessingImageShow(const bool isEnable) {
    m_isPreprocessingImageShow = isEnable;
    return *this;
}

bool SingleDetectConfiguration::isPreprocessingImageShow() const {
    return m_isPreprocessingImageShow;
}

SingleDetectConfiguration &SingleDetectConfiguration::setIdLabel(const bool isEnable) {
    m_isIdLabel = isEnable;
    return *this;
}

bool SingleDetectConfiguration::isIdLabel() const {
    return m_isIdLabel;
}

SingleDetectConfiguration &SingleDetectConfiguration::setFeatureExtractFilterThreshold(
        const FeatureExtractFilterThreshold &threshold) {
    m_featureExtractFilterThreshold = threshold;
    return *this;
}

const FeatureExtractFilterThreshold &SingleDetectConfiguration::getFeatureExtractFilterThreshold() const {
    return m_featureExtractFilterThreshold;
}

SingleDetectConfiguration &SingleDetectConfiguration::addResize(const int priority, const float scaleFactor) {
    m_preprocessingConfiguration.addResize(priority, scaleFactor);
    return *this;
}

SingleDetectConfiguration &SingleDetectConfiguration::addGaussBlur(const int priority, const int kernelSize) {
    m_preprocessingConfiguration.addGaussBlur(priority, kernelSize);
    return *this;
}

SingleDetectConfiguration &SingleDetectConfiguration::addGray(const int priority) {
    m_preprocessingConfiguration.addGray(priority);
    return *this;
}

SingleDetectConfiguration &SingleDetectConfiguration::addDilate(const int priority, const int kernelSize) {
    m_preprocessingConfiguration.addDilate(priority, kernelSize);
    return *this;
}

SingleDetectConfiguration &SingleDetectConfiguration::addErode(const int priority, const int kernelSize) {
    m_preprocessingConfiguration.addErode(priority, kernelSize);
    return *this;
}

SingleDetectConfiguration &SingleDetectConfiguration::addBinary(const int priority, const int threshold) {
    m_preprocessingConfiguration.addBinary(priority, threshold);
    return *this;
}

SingleDetectConfiguration &SingleDetectConfiguration::addEnhance(const int priority) {
    m_preprocessingConfiguration.addEnhance(priority);
    return *this;
}

SingleDetectConfiguration &
SingleDetectConfiguration::addCanny(const int priority, const int thresholdLower, const int thresholdUpper) {
    m_preprocessingConfiguration.addCanny(priority, thresholdLower, thresholdUpper);
    return *this;
}

std::vector<std::pair<char, const std::vector<float>>> SingleDetectConfiguration::getPreprocessingSteps() const {
    return m_preprocessingConfiguration.getPreprocessingSteps();
}
