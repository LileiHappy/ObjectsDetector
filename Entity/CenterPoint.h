//
// Created by 李磊 on 2025/2/26.
//

#pragma once

#include "InfoShower.h"

// 物体的中心点坐标表示，只有3维空间表示
class CenterPoint : public InfoShower {
public:
    CenterPoint();
    CenterPoint(const float x, const float y, const float z);
    CenterPoint(const CenterPoint& other);
    CenterPoint& operator= (const CenterPoint& other);

    ~CenterPoint() override = default;

    float getX() const;

    CenterPoint& setX(const float x);

    float getY() const;

    CenterPoint& setY(const float y);

    float getZ() const;

    CenterPoint& setZ(const float z);

    void showInfo() const override;

    std::string getInfo() const override;

private:
    void assign(const CenterPoint& other);

private:
    float m_x;
    float m_y;
    float m_z;
};
