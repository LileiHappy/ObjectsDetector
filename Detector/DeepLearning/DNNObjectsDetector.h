//
// Created by 李磊 on 2025/2/27.
//

#pragma once

#include "../IObjectsDetector.h"

class DNNObjectsDetector final : public IObjectsDetector {
public:
    DNNObjectsDetector() = default;

    ~DNNObjectsDetector() override = default;

    void detect(const DetectConfiguration &configuration) const override;
};
