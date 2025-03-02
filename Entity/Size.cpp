//
// Created by 李磊 on 2025/2/26.
//

#include <iostream>

#include "Size.h"


using std::cout;

Size::Size() : Size(0, 0, 0) {}

Size::Size(float width, float height, float depth) : m_width(width), m_height(height), m_depth(depth) {}

Size::Size(const Size &other) {
    assign(other);
}

Size &Size::operator=(const Size &other) {
    assign(other);
    return *this;
}

void Size::assign(const Size &other) {
    m_width = other.m_width;
    m_height = other.m_height;
    m_depth = other.m_depth;
}

float Size::getWidth() const {
    return m_width;
}

Size &Size::setWidth(const float width) {
    m_width = width;
    return *this;
}

float Size::getHeight() const {
    return m_height;
}

Size &Size::setHeight(const float height) {
    m_height = height;
    return *this;
}

float Size::getDepth() const {
    return m_depth;
}

Size &Size::setDepth(const float depth) {
    m_depth = depth;
    return *this;
}

void Size::showInfo() const {
    cout << "\tSize{\n"
         << "\t\twidth = " << m_width << ",\n"
         << "\t\theight = " << m_height << ",\n"
         << "\t\tdepth = " << m_depth << "\n"
         << "\t},\n";
}

std::string Size::getInfo() const {
    std::string info;
    info.append("\tSize{\n")
            .append("\t\twidth = ").append(std::to_string(m_width)).append(",\n")
            .append("\t\theight = ").append(std::to_string(m_height)).append(",\n")
            .append("\t\tdepth = ").append(std::to_string(m_depth)).append("\n")
            .append("\t},\n");
    return info;
}
