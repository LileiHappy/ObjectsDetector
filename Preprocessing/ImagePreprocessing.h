//
// Created by 李磊 on 2025/2/26.
//

#pragma once

#include "IImagePreprocessing.h"
#include "../Singleton.h"

class ImagePreprocessing final : public Singleton<ImagePreprocessing>, public IImagePreprocessing {
public:
    ~ImagePreprocessing() override = default;

    inline void resize(const std::vector<float>& scaleFactor, const cv::Mat &originImage, cv::Mat &image) const override;

    inline void gaussBlur(const std::vector<float>& kernelSize, const cv::Mat &originImage, cv::Mat &image) const override;

    inline void gray(const std::vector<float>&, const cv::Mat &originImage, cv::Mat &image) const override;

    inline void dilation(const std::vector<float>& kernelSize, const cv::Mat &originImage, cv::Mat &image) const override;

    inline void erode(const std::vector<float>& kernelSize, const cv::Mat &originImage, cv::Mat &image) const override;

    inline void binary(const std::vector<float>& threshold, const cv::Mat &originImage, cv::Mat &image) const override;

    inline void enhanceContrast(const std::vector<float>&, const cv::Mat &originImage, cv::Mat &image) const override;

    inline void canny(const std::vector<float>& thresholds, const cv::Mat &originImage, cv::Mat &image) const override;

private:
    ImagePreprocessing() = default;

    int mayAdjustKernelSize(const std::vector<float>& kernelSize) const;

private:
    friend Singleton;

private:
    static constexpr int MIN_KERNEL_SIZE = 3;
};
#include "ImagePreprocessing.inl"