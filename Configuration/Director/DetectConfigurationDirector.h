//
// Created by 李磊 on 2025/2/27.
//

#pragma once

#include "../Builder/DetectConfigurationBuilder.h"

class DetectConfigurationDirector final {
public:
    DetectConfigurationDirector(const DetectConfigurationBuilder& builder);

    ~DetectConfigurationDirector() = default;

    DetectConfiguration createDetectConfiguration() const;

private:
    DetectConfigurationBuilder m_builder;
};
