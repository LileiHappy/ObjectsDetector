//
// Created by 李磊 on 2025/2/27.
//

#include "DetectConfigurationBuilder.h"

DetectConfigurationBuilder::DetectConfigurationBuilder() : m_detectConfigurations(), m_currentDetectConfiguration(),
    m_isNewConfiguration(false) {}


DetectConfigurationBuilder::DetectConfigurationBuilder(const DetectConfigurationBuilder &other) :
    m_detectConfigurations(other.m_detectConfigurations),
    m_currentDetectConfiguration(other.m_currentDetectConfiguration),
    m_isNewConfiguration(other.m_isNewConfiguration) {}

DetectConfigurationBuilder &DetectConfigurationBuilder::operator=(const DetectConfigurationBuilder &other) {
    m_detectConfigurations = other.m_detectConfigurations;
    m_currentDetectConfiguration = other.m_currentDetectConfiguration;
    m_isNewConfiguration = other.m_isNewConfiguration;
    return *this;
}

DetectConfigurationBuilder::~DetectConfigurationBuilder() {
    m_detectConfigurations.clear();
}

DetectConfigurationBuilder &DetectConfigurationBuilder::addDetectImagePath(const std::string &path) {
    mayNewSingleDetectConfiguration();
    m_currentDetectConfiguration.setImagePath(path);
    return *this;
}

DetectConfigurationBuilder &DetectConfigurationBuilder::addImagePreprocessingStore(const bool isEnable) {
    mayNewSingleDetectConfiguration();
    m_currentDetectConfiguration.setImagePreprocessingStore(isEnable);
    return *this;;
}

DetectConfigurationBuilder &DetectConfigurationBuilder::addPreprocessingImageShow(const bool isEnable) {
    mayNewSingleDetectConfiguration();
    m_currentDetectConfiguration.setPreprocessingImageShow(isEnable);
    return *this;;
}

DetectConfigurationBuilder &DetectConfigurationBuilder::addIdLabel(const bool isEnable) {
    mayNewSingleDetectConfiguration();
    m_currentDetectConfiguration.setIdLabel(isEnable);
    return *this;
}

DetectConfigurationBuilder &
DetectConfigurationBuilder::addFeatureExtractFilterThreshold(const FeatureExtractFilterThreshold &threshold) {
    mayNewSingleDetectConfiguration();
    m_currentDetectConfiguration.setFeatureExtractFilterThreshold(threshold);
    return *this;;
}

DetectConfigurationBuilder &DetectConfigurationBuilder::addResize(const int priority, const float scaleFactor) {
    mayNewSingleDetectConfiguration();
    m_currentDetectConfiguration.addResize(priority, scaleFactor);
    return *this;;
}

DetectConfigurationBuilder &DetectConfigurationBuilder::addGaussBlur(const int priority, const int kernelSize) {
    mayNewSingleDetectConfiguration();
    m_currentDetectConfiguration.addGaussBlur(priority, kernelSize);
    return *this;;
}

DetectConfigurationBuilder &DetectConfigurationBuilder::addGray(const int priority) {
    mayNewSingleDetectConfiguration();
    m_currentDetectConfiguration.addGray(priority);
    return *this;;
}

DetectConfigurationBuilder &DetectConfigurationBuilder::addDilate(const int priority, const int kernelSize) {
    mayNewSingleDetectConfiguration();
    m_currentDetectConfiguration.addDilate(priority, kernelSize);
    return *this;;
}

DetectConfigurationBuilder &DetectConfigurationBuilder::addErode(const int priority, const int kernelSize) {
    mayNewSingleDetectConfiguration();
    m_currentDetectConfiguration.addErode(priority, kernelSize);
    return *this;;
}

DetectConfigurationBuilder &DetectConfigurationBuilder::addBinary(const int priority, const int threshold) {
    mayNewSingleDetectConfiguration();
    m_currentDetectConfiguration.addBinary(priority, threshold);
    return *this;;
}

DetectConfigurationBuilder &DetectConfigurationBuilder::addEnhance(const int priority) {
    return *this;;
}

DetectConfigurationBuilder &
DetectConfigurationBuilder::addCanny(const int priority, const int thresholdLower, const int thresholdUpper) {
    mayNewSingleDetectConfiguration();
    m_currentDetectConfiguration.addCanny(priority, thresholdLower, thresholdUpper);
    return *this;
}

DetectConfigurationBuilder &DetectConfigurationBuilder::finishDetectConfiguration() {
    m_isNewConfiguration = false;
    m_detectConfigurations.addDetectConfiguration(m_currentDetectConfiguration);
    return *this;;
}

DetectConfiguration DetectConfigurationBuilder::build() const {
    return m_detectConfigurations;
}

void DetectConfigurationBuilder::mayNewSingleDetectConfiguration() {
    if (!m_isNewConfiguration) {
        m_currentDetectConfiguration = SingleDetectConfiguration();
        m_isNewConfiguration = true;
    }
}
