//
// Created by 李磊 on 2025/2/27.
//

#include "DetectConfigurationDirector.h"

DetectConfigurationDirector::DetectConfigurationDirector(const DetectConfigurationBuilder &builder) :
    m_builder(builder) {}

DetectConfiguration DetectConfigurationDirector::createDetectConfiguration() const {
    return m_builder.build();
}
