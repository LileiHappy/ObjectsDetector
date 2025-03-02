//
// Created by 李磊 on 2025/2/27.
//

#pragma once

#include <opencv2/opencv.hpp>
#include <string>

#include "../../Singleton.h"
#include "../IObjectsDetector.h"
#include "../../Entity/ObjectInfo.h"

class TraditionalObjectsDetector final : public Singleton<TraditionalObjectsDetector>, public IObjectsDetector {
public:
    TraditionalObjectsDetector() = default;

    ~TraditionalObjectsDetector() override = default;

    void detect(const DetectConfiguration &configuration) const override;

private:
    inline bool isFilterContour(const std::vector<cv::Point> &contour, const bool isDot,
                                const FeatureExtractFilterThreshold &thresholds,
                                std::vector<cv::Point> &approxPoints, cv::Rect &rect,
                                cv::RotatedRect &rotatedRect) const;

    inline void
    processContour(const size_t id, const cv::Rect &rect, const cv::RotatedRect &rotatedRect, const size_t pointCount,
                   const bool isIdLabel, cv::Mat &resultImage, std::vector<std::string> &objects) const;

    inline void
    draw(const size_t id, const cv::Rect &rect, const cv::RotatedRect &rotatedRect, const bool isIdLabel,
         cv::Mat &resultImage) const;

    inline void saveObjectInfo(const size_t id, const cv::Rect &rect, const size_t pointCount,
                               std::vector<std::string> &objects) const;
};