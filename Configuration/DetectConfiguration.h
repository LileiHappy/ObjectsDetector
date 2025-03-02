//
// Created by 李磊 on 2025/2/27.
//

#pragma once

#include <vector>

#include "SingleDetectConfiguration.h"

class DetectConfiguration final {
public:
    DetectConfiguration();

    DetectConfiguration(const DetectConfiguration& other);

    DetectConfiguration& operator= (const DetectConfiguration& other);

    ~DetectConfiguration();

    DetectConfiguration& addDetectConfiguration(const SingleDetectConfiguration& configuration);

    const SingleDetectConfiguration& getDetectConfiguration(const size_t index) const;

    const std::vector<SingleDetectConfiguration> getConfigurations() const;

    inline void clear();

private:
    std::vector<SingleDetectConfiguration> m_detectConfigurations;
};
#include "DetectConfiguration.inl"
