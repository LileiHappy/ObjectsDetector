//
// Created by 李磊 on 2025/2/26.
//

#pragma once

#include "IImageStorage.h"
#include "../Singleton.h"

class ImageStorage : public Singleton<ImageStorage>, public IImageStorage {
public:
    ~ImageStorage() override = default;

    void enableStorage(const bool isEnable) override;

    void store(const cv::Mat &image, const std::string &fileName) const override;

    void remove(const std::string &fileName) const override;

    void removeAll() const override;

private:
    ImageStorage();

private:
    bool m_isEnable;
};
