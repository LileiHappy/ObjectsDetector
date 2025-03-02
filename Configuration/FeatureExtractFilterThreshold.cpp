//
// Created by 李磊 on 2025/2/27.
//

#include "FeatureExtractFilterThreshold.h"

FeatureExtractFilterThreshold::FeatureExtractFilterThreshold(int minArea, int maxArea, int minWidth, int minHeight,
                                                             int minX, int minY) {
    this->minArea = minArea;
    this->maxArea = maxArea;
    this->minWidth = minWidth;
    this->minHeight = minHeight;
    this->minX = minX;
    this->minY = minY;
}

FeatureExtractFilterThreshold::FeatureExtractFilterThreshold(const FeatureExtractFilterThreshold &other) :
    FeatureExtractFilterThreshold(other.minArea, other.maxArea, other.minWidth, other.minHeight, other.minX,
                                  other.minY) {}

FeatureExtractFilterThreshold &FeatureExtractFilterThreshold::operator= (const FeatureExtractFilterThreshold &other) {
    this->minArea = other.minArea;
    this->maxArea = other.maxArea;
    this->minWidth = other.minWidth;
    this->minHeight = other.minHeight;
    this->minX = other.minX;
    this->minY = other.minY;
    return *this;
}
