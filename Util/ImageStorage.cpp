//
// Created by 李磊 on 2025/2/26.
//

#include "ImageStorage.h"
#include "../FileAssistant/FileAssistant.h"
#include "../ProjectRootPath.h"
#include "PlatformSupporter.h"

ImageStorage::ImageStorage() : m_isEnable(false) {}

void ImageStorage::enableStorage(const bool isEnable) {
    m_isEnable = isEnable;
}

void ImageStorage::store(const cv::Mat &image, const std::string &fileName) const {
    if (!m_isEnable) {
        return;
    }
    cv::imwrite(fileName, image);
}

void ImageStorage::remove(const std::string &fileName) const {
    if (!m_isEnable) {
        return;
    }
    std::string projectRootPath(PROJECT_ROOT_PATH);
    projectRootPath.append(std::string(1, PlatformSupporter::getFilePathSeparator())).append("preprocessing");
    FileAssistant::instance().remove(projectRootPath.append(fileName));
}

void ImageStorage::removeAll() const {
    if (!m_isEnable) {
        return;
    }
    std::string projectRootPath(PROJECT_ROOT_PATH);
    projectRootPath.append(std::string(1, PlatformSupporter::getFilePathSeparator())).append("preprocessing");
    FileAssistant::instance().remove(projectRootPath);
}
