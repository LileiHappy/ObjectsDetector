//
// Created by 李磊 on 2025/2/26.
//
#include <iostream>

#include "ObjectInfo.h"


using std::cout;
using std::endl;

ObjectInfo::ObjectInfo(const size_t id) : m_id(id), m_centerPoint(), m_size(), m_corner(),
                                          m_shapeType(ShapeType::UNKNOWN) {}

ObjectInfo &ObjectInfo::setCenterPoint(const float x, const float y, const float z) {
    m_centerPoint.setX(x)
            .setY(y)
            .setZ(z);
    return *this;
}

CenterPoint &ObjectInfo::getCenterPoint() {
    return m_centerPoint;
}

ObjectInfo &ObjectInfo::setSize(const float width, const float height, const float depth) {
    m_size.setWidth(width)
            .setHeight(height)
            .setDepth(depth);
    return *this;
}

size_t ObjectInfo::getId() const {
    return m_id;
}

Size &ObjectInfo::getSize() {
    return m_size;
}

ObjectInfo &ObjectInfo::setCorner(const float value, const CornerType type) {
    if (type == CornerType::ANGLE) {
        m_corner.setAngle(value);
    } else if (type == CornerType::AMPLITUDE) {
        m_corner.setAmplitude(value);
    }
    return *this;
}

ObjectInfo &ObjectInfo::setShapeType(const ShapeType type) {
    m_shapeType = type;
    return *this;
}

Corner &ObjectInfo::getCorner() {
    return m_corner;
}

float ObjectInfo::getX() const {
    return m_centerPoint.getX();
}

float ObjectInfo::getY() const {
    return m_centerPoint.getY();
}

float ObjectInfo::getZ() const {
    return m_centerPoint.getZ();
}

float ObjectInfo::getWidth() const {
    return m_size.getWidth();
}

float ObjectInfo::getHeight() const {
    return m_size.getHeight();
}

float ObjectInfo::getDepth() const {
    return m_size.getDepth();
}

float ObjectInfo::getAngle() const {
    return m_corner.getAngle();
}

float ObjectInfo::getAmplitude() const {
    return m_corner.getAmplitude();
}

ShapeType ObjectInfo::getShapeType() const {
    return m_shapeType;
}

void ObjectInfo::showInfo() const {
    cout << "Object Information{\n"
         << "\tid = " << std::to_string(m_id) << ",\n"
         << getShapeTypeDescription();
    m_centerPoint.showInfo();
    m_size.showInfo();
    m_corner.showInfo();
    cout << "}" << endl;
}

std::string ObjectInfo::getInfo() const {
    std::string info("Object Information{\n");
    info.append("\tid = ").append(std::to_string(m_id)).append(",\n")
            .append(getShapeTypeDescription())
            .append(m_centerPoint.getInfo())
            .append(m_size.getInfo())
            .append(m_corner.getInfo())
            .append("}\n");
    return info;
}

std::string ObjectInfo::getShapeTypeDescription() const {
    std::string shape("\tshape type = ");
    if (m_shapeType == ShapeType::RECTANGLE) {
        shape.append("rectangle,\n");
    } else if (m_shapeType == ShapeType::SQUARE) {
        shape.append("square,\n");
    } else if (m_shapeType == ShapeType::CIRCLE) {
        shape.append("circle,\n");
    } else {
        shape.append("other,\n");
    }
    return shape;
}
