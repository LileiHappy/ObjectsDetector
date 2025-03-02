//
// Created by 李磊 on 2025/2/26.
//

#pragma once

#include "InfoShower.h"

class Size : public InfoShower {
public:
    Size();
    Size(const float width, const float height, const float depth);
    Size(const Size& other);
    Size& operator= (const Size& other);

    ~Size() override = default;

    float getWidth() const;

    Size& setWidth(const float width);

    float getHeight() const;

    Size& setHeight(const float height);

    float getDepth() const;

    Size& setDepth(const float depth);

    void showInfo() const override;

    std::string getInfo() const override;

private:
    void assign(const Size& other);

private:
    float m_width;
    float m_height;
    float m_depth;
};
