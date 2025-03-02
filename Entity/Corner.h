//
// Created by 李磊 on 2025/2/26.
//

#pragma once

#include "InfoShower.h"

enum class CornerType {
    UNKNOWN,
    ANGLE,
    AMPLITUDE
};

class Corner : InfoShower {
public:
    Corner();
    Corner(const float value, const CornerType type);
    Corner(const Corner& other);
    Corner& operator= (const Corner& other);

    ~Corner() override = default;

    float getAngle() const;

    Corner& setAngle(const float angle);

    float getAmplitude() const;

    Corner& setAmplitude(const float amplitude);

    CornerType isAngle() const;

    void showInfo() const override;

    std::string getInfo() const override;

private:
    void assign(const Corner& other);

private:
    float m_angle;
    float m_amplitude;
    CornerType m_type;
};
