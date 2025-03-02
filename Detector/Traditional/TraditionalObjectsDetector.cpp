//
// Created by 李磊 on 2025/2/27.
//
#include "TraditionalObjectsDetector.h"
#include "../../Preprocessing/ImagePreprocessingHandler.h"
#include "../../Util/DisplayHandler.h"
#include "../../FileAssistant/FileAssistant.h"
#include "../../ProjectRootPath.h"
#include "../../Util/PlatformSupporter.h"

using namespace cv;

void TraditionalObjectsDetector::detect(const DetectConfiguration &configuration) const {
    std::string detectResultDir(PROJECT_ROOT_PATH);
    std::string fileSeparator(1, PlatformSupporter::getFilePathSeparator());
    detectResultDir.append(fileSeparator).append("detect_result");
    FileAssistant::instance().createDirectory(detectResultDir);
    const std::vector<SingleDetectConfiguration> &configurations = configuration.getConfigurations();
    for (const auto &c: configurations) {
        cv::Mat preprocessingResultImage;
        cv::Mat originImage;
        ImagePreprocessingHandler::instance().attachDetectConfiguration(c);
        if (!ImagePreprocessingHandler::instance().preprocess(preprocessingResultImage, originImage)) {
            continue;
        }

        std::vector<std::string> objectInfos;
        std::vector<std::vector<cv::Point>> contours;
        std::vector<cv::Vec4i> hierarchy;
        findContours(preprocessingResultImage, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

        bool isDot = true;
        for (const auto &contour: contours) {
            if (cv::contourArea(contour) > 20) {
                isDot = false;
                break;
            }
        }

        std::vector<cv::Point> approxPoints;
        size_t id = 1;
        for (const auto &contour: contours) {
            approxPoints.clear();
            cv::Rect rect;
            cv::RotatedRect rotatedRect;
            if (isFilterContour(contour, isDot, c.getFeatureExtractFilterThreshold(), approxPoints, rect,
                                rotatedRect)) {
                continue;
            }

            processContour(id, rect, rotatedRect, approxPoints.size(), c.isIdLabel(), originImage, objectInfos);
            ++id;
        }

        approxPoints.clear();
        approxPoints.shrink_to_fit();
        DisplayHandler::instance().showImage(c.getImageName().append("_result_image"), originImage, true);
        if (objectInfos.empty()) {
            FileAssistant::instance().writeContent(detectResultDir + fileSeparator + c.getImageName() + ".txt",
                                                   "no object.");
        } else {
            FileAssistant::instance().writeContent(detectResultDir + fileSeparator + c.getImageName() + ".txt",
                                                   objectInfos);
        }
    }

    cv::waitKey(0);
}

bool TraditionalObjectsDetector::isFilterContour(const std::vector<cv::Point> &contour, const bool isDot,
                                                 const FeatureExtractFilterThreshold &thresholds,
                                                 std::vector<cv::Point> &approxPoints, cv::Rect &rect,
                                                 cv::RotatedRect &rotatedRect) const {
    approxPoints.clear();
    approxPolyDP(contour, approxPoints, cv::arcLength(contour, true) * 0.01, true);
    rect = cv::boundingRect(approxPoints);
    rotatedRect = minAreaRect(approxPoints);
    const int areaSize = rect.width * rect.height;
    return !isDot && (areaSize < thresholds.minArea || areaSize > thresholds.maxArea
                      || rect.height < thresholds.minHeight || rect.width < thresholds.minWidth
                      || rect.x < thresholds.minX || rect.y < thresholds.minY) ? true : false;
}

void
TraditionalObjectsDetector::processContour(const size_t id, const cv::Rect &rect, const cv::RotatedRect &rotatedRect,
                                           const size_t pointCount, const bool isIdLabel, cv::Mat &resultImage,
                                           std::vector<std::string> &objectInfos) const {
    draw(id, rect, rotatedRect, isIdLabel, resultImage);
    saveObjectInfo(id, rect, pointCount, objectInfos);
}

void TraditionalObjectsDetector::draw(const size_t id, const cv::Rect &rect, const cv::RotatedRect &rotatedRect,
                                      const bool isIdLabel, cv::Mat &resultImage) const {
    Rect r(rotatedRect.boundingRect());
    rectangle(resultImage, rect, cv::Scalar(255, 0, 255), 1);
    rectangle(resultImage, r, cv::Scalar(0, 255, 255), 1);
    Point p1(static_cast<int>(rotatedRect.center.x), static_cast<int>(rotatedRect.center.y));
    Point p2(rect.x + (rect.width >> 1), rect.y + (rect.height >> 1));
    //std::cout << "x1=" << p1.x << " y1=" << p1.y << " x2=" << p2.x << " y2=" << p2.y << std::endl;
    circle(resultImage, p1, 2, cv::Scalar(255, 0, 0), -1, 8, 0);
    circle(resultImage, p2, 2, cv::Scalar(255, 255, 255), -1, 8, 0);
    if (isIdLabel) {
        putText(resultImage, std::to_string(id), Point(p1.x - 10, p1.y + 2), FONT_HERSHEY_SIMPLEX, 0.2,
                Scalar(0, 0, 255));
    }
}

void TraditionalObjectsDetector::saveObjectInfo(const size_t id, const cv::Rect &rect, const size_t pointCount,
                                                std::vector<std::string> &objectInfos) const {
    ObjectInfo info{id};
    if (pointCount == 3) {
        info.setShapeType(ShapeType::TRIANGLE);
    } else if (pointCount == 4) {
        float factor = rect.width / static_cast<float>(rect.height);
        info.setShapeType(factor > 0.95 ? ShapeType::SQUARE : ShapeType::RECTANGLE);
    } else if (pointCount > 5) {
        info.setShapeType(ShapeType::CIRCLE);
    }
    info.setCenterPoint(0, 0, 0)
//        .setSize(rect.width, rect.height, 0)
            .setSize(static_cast<float>(rect.width), static_cast<float>(rect.height), 0)
            .setCorner(0, CornerType::ANGLE);
    objectInfos.emplace_back(info.getInfo());
}
