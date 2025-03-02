//
// Created by 李磊 on 2025/2/26.
//

#include <iostream>

#include "CenterPoint.h"


using std::cout;

CenterPoint::CenterPoint() : CenterPoint(0, 0, 0) {}

CenterPoint::CenterPoint(const float x, const float y, const float z) : m_x(x), m_y(y), m_z(z) {}

CenterPoint::CenterPoint(const CenterPoint &other) {
    assign(other);
}

CenterPoint &CenterPoint::operator=(const CenterPoint &other) {
    assign(other);
    return *this;
}

void CenterPoint::assign(const CenterPoint &other) {
    m_x = other.m_x;
    m_y = other.m_y;
    m_z = other.m_z;
}

float CenterPoint::getX() const {
    return m_x;
}

CenterPoint &CenterPoint::setX(const float x) {
    m_x = x;
    return *this;
}

float CenterPoint::getY() const {
    return m_y;
}

CenterPoint &CenterPoint::setY(const float y) {
    m_y = y;
    return *this;
}

float CenterPoint::getZ() const {
    return m_z;
}

CenterPoint &CenterPoint::setZ(float z) {
    m_z = z;
    return *this;
}

void CenterPoint::showInfo() const {
    cout << "\tCenter Point{\n"
         << "\t\tx = " << m_x << ",\n"
         << "\t\ty = " << m_y << ",\n"
         << "\t\tz = " << m_z << ",\n"
         << "\t},\n";
}

std::string CenterPoint::getInfo() const {
    std::string info("\tCenter Point{\n");
    info.append("\t\tx = ").append(std::to_string(m_x)).append(",\n")
            .append("\t\ty = ").append(std::to_string(m_y)).append(",\n")
            .append("\t\tz = ").append(std::to_string(m_z)).append(",\n")
            .append("\t},\n");
    return info;
}
