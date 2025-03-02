//
// Created by 李磊 on 2025/2/26.
//

#pragma once

#include "IDisplayHandler.h"
#include "../Singleton.h"

class DisplayHandler : public Singleton<DisplayHandler>, public IDisplayHandler {
public:

    ~DisplayHandler() = default;

    void setEnable(const bool isEnable) override;

    void showImageInfo(const cv::Mat &image) const override;

    void showImage(const std::string &title, const cv::Mat &image, const bool isResultEnable = false) const override;

    void showImage(const char titleFlag, const cv::Mat &image, const bool isResultEnable = false) const override;

    void showImage(const char titleFlag, const std::string &prefix, const cv::Mat &image,
                   const bool isResultEnable = false) const override;

private:
    DisplayHandler() = default;

private:
    friend Singleton;

private:
    bool m_isEnable;
};
