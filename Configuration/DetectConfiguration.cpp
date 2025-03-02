//
// Created by 李磊 on 2025/2/27.
//

#include "DetectConfiguration.h"

DetectConfiguration::DetectConfiguration() : m_detectConfigurations() {}

DetectConfiguration::DetectConfiguration(const DetectConfiguration &other) :
m_detectConfigurations(other.m_detectConfigurations) {}

DetectConfiguration &DetectConfiguration::operator=(const DetectConfiguration &other) {
    m_detectConfigurations.clear();
    m_detectConfigurations.shrink_to_fit();
    m_detectConfigurations = other.m_detectConfigurations;
    return *this;
}

DetectConfiguration::~DetectConfiguration() {
    clear();
}

DetectConfiguration &DetectConfiguration::addDetectConfiguration(const SingleDetectConfiguration &configuration) {
    m_detectConfigurations.emplace_back(std::move(configuration));
    return *this;
}

const SingleDetectConfiguration &DetectConfiguration::getDetectConfiguration(const size_t index) const {
    return m_detectConfigurations[index];
}

const std::vector<SingleDetectConfiguration> DetectConfiguration::getConfigurations() const {
    return m_detectConfigurations;
}