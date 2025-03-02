//
// Created by 李磊 on 2025/2/27.
//

#pragma once

struct FeatureExtractFilterThreshold {
    int minArea;
    int maxArea;
    int minWidth;
    int minHeight;
    int minX;
    int minY;

    FeatureExtractFilterThreshold() = default;

    FeatureExtractFilterThreshold(int minArea,
    int maxArea,
    int minWidth,
    int minHeight,
    int minX,
    int minY);

    FeatureExtractFilterThreshold(const FeatureExtractFilterThreshold& other);

    FeatureExtractFilterThreshold& operator= (const FeatureExtractFilterThreshold& other);

    ~FeatureExtractFilterThreshold() = default;
};
