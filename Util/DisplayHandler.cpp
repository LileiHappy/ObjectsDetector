//
// Created by 李磊 on 2025/2/26.
//

#include <iostream>

#include "DisplayHandler.h"
#include "../Preprocessing/PreprocessingStep.h"

void DisplayHandler::setEnable(const bool isEnable) {
    m_isEnable = isEnable;
}

void DisplayHandler::showImageInfo(const cv::Mat &image) const {
    if (!m_isEnable) {
        return;
    }
    std::cout << "sizeof(image) is: " << sizeof(image) << ", image size is: " << image.size << "\n"
              << "rows x cols: (" << image.rows << " x " << image.cols << ")" << "\n"
              << "dims: " << image.dims << "\n"
              << "channels: " << image.channels() << "\n"
              << "type: " << image.type() << "\n"
              << "depth:" << image.depth() << "\n"
              << "elemSize:" << image.elemSize() << " (Bytes per element)" << "\n"
              << "elemSize1:" << image.elemSize1() << "(Bytes per channel)" << "\n"
              << "step[0]: " << image.step[0] << " (Bytes per cows only when 2 dims)" << "\n"
              << "step[1]: " << image.step[1] << " (Bytes per element only when 2 dims)" << "\n"
              << "step1(0): " << image.step1(0) << ", step1(1): " << image.step1(1) << " (step / elemSize1)"
              << std::endl;
}

void DisplayHandler::showImage(const std::string &title, const cv::Mat &image, const bool isResultEnable) const {
    if (image.empty() || (!m_isEnable && !isResultEnable)) {
        return;
    }

    cv::imshow(title, image);
}

void DisplayHandler::showImage(const char titleFlag, const cv::Mat &image, const bool isResultEnable) const {
    std::string title;
    switch (titleFlag) {
        case PREPROCESSING_FUNC_GAUSS_BLUR:
            title = "gauss_blur_image";
            break;
        case PREPROCESSING_FUNC_GRAY:
            title = "gray_image";
            break;
        case PREPROCESSING_FUNC_DILATE:
            title = "dilate_image";
            break;
        case PREPROCESSING_FUNC_ERODE:
            title = "erode_image";
            break;
        case PREPROCESSING_FUNC_BINARY:
            title = "binary_image";
            break;
        case PREPROCESSING_FUNC_ENHANCE_CONTRAST:
            title = "enhance_image";
            break;
        case PREPROCESSING_FUNC_CANNY:
            title = "canny_image";
            break;
        default:
            title = "";
            break;
    }

    showImage(title, image);
}

void DisplayHandler::showImage(const char titleFlag, const std::string &prefix, const cv::Mat &image,
                               const bool isResultEnable) const {
    std::string title(prefix);
    switch (titleFlag) {
        case PREPROCESSING_FUNC_GAUSS_BLUR:
            title.append("gauss_blur_image");
            break;
        case PREPROCESSING_FUNC_GRAY:
            title.append("gray_image");
            break;
        case PREPROCESSING_FUNC_DILATE:
            title.append("dilate_image");
            break;
        case PREPROCESSING_FUNC_ERODE:
            title.append("erode_image");
            break;
        case PREPROCESSING_FUNC_BINARY:
            title.append("binary_image");
            break;
        case PREPROCESSING_FUNC_ENHANCE_CONTRAST:
            title.append("enhance_image");
            break;
        case PREPROCESSING_FUNC_CANNY:
            title.append("canny_image");
            break;
        default:
            break;
    }

    showImage(title, image);
}
