//
// Created by 李磊 on 2025/2/26.
//

#include <iostream>

#include "Corner.h"


using std::cout;

Corner::Corner() : Corner(0, CornerType::UNKNOWN) {}

Corner::Corner(const float value, const CornerType type) {
    m_type = type;
    if (m_type == CornerType::ANGLE) {
        m_angle = value;
    } else if (m_type == CornerType::AMPLITUDE) {
        m_amplitude = value;
    }
}

Corner::Corner(const Corner &other) {
    assign(other);
}

Corner &Corner::operator=(const Corner &other) {
    assign(other);
    return *this;
}

void Corner::assign(const Corner &other) {
    m_type = other.m_type;
    if (m_type == CornerType::ANGLE) {
        m_angle = other.m_angle;
    } else if (m_type == CornerType::AMPLITUDE) {
        m_amplitude = other.m_amplitude;
    }
}

float Corner::getAngle() const {
    return m_angle;
}

Corner &Corner::setAngle(const float angle) {
    m_angle = angle;
    m_type = CornerType::ANGLE;
    return *this;
}

float Corner::getAmplitude() const {
    return m_amplitude;
}

Corner &Corner::setAmplitude(const float amplitude) {
    m_amplitude = amplitude;
    m_type = CornerType::AMPLITUDE;
    return *this;
}

CornerType Corner::isAngle() const {
    return m_type;
}

void Corner::showInfo() const {
    if (m_type == CornerType::UNKNOWN) {
        cout << "\tCorner{\n"
             << "no info\n\t}\n";
    } else {
        std::string cornerInfo(m_type == CornerType::ANGLE ? "angle = " : "amplitude = ");
        cornerInfo.append(std::to_string(m_type == CornerType::ANGLE ? m_angle : m_amplitude));
        cout << "\tCorner{\n"
             << "\t\t" << cornerInfo << ",\n"
             << "\t}\n";
    }
}

std::string Corner::getInfo() const {
    std::string info;
    if (m_type == CornerType::UNKNOWN) {
        info.append(("\tCorner{\nno info\n\t}\n"));
    } else {
        std::string cornerInfo(m_type == CornerType::ANGLE ? "angle = " : "amplitude = ");
        cornerInfo.append(std::to_string(m_type == CornerType::ANGLE ? m_angle : m_amplitude));
        info.append("\tCorner{\n")
                .append("\t\t").append(cornerInfo).append(",\n")
                .append("\t}\n");
    }
    return info;
}
