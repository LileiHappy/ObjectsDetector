//
// Created by 李磊 on 2025/2/27.
//

#pragma once

#include "../Configuration/DetectConfiguration.h"

class IObjectsDetector {
public:
    virtual ~IObjectsDetector() = default;

    virtual void detect(const DetectConfiguration& configuration) const = 0;
};