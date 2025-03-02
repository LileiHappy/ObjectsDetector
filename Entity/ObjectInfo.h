//
// Created by 李磊 on 2025/2/26.
//

#pragma once

#include "InfoShower.h"
#include "Corner.h"
#include "CenterPoint.h"
#include "Size.h"

enum class ShapeType {
    UNKNOWN,
    TRIANGLE,
    RECTANGLE,
    SQUARE,
    PARALLELOGRAM,
    ELLIPSE,
    PENTAGON,
    CIRCLE,
    OVAL
};

class ObjectInfo : public InfoShower {
public:
    explicit ObjectInfo(const size_t id);

    ~ObjectInfo() override = default;

    ObjectInfo& setCenterPoint(const float x, const float y, const float z);

    CenterPoint& getCenterPoint();

    ObjectInfo& setSize(const float width, const float height, const float depth);

    Size& getSize();

    ObjectInfo& setCorner(const float value, const CornerType type);

    ObjectInfo& setShapeType(const ShapeType type);

    Corner& getCorner();

    size_t getId() const;

    float getX() const;

    float getY() const;

    float getZ() const;

    float getWidth() const;

    float getHeight() const;

    float getDepth() const;

    float getAngle() const;

    float getAmplitude() const;

    ShapeType getShapeType() const;

    void showInfo() const override;

    std::string getInfo() const override;

private:
    std::string getShapeTypeDescription() const;

private:
    size_t m_id;
    CenterPoint m_centerPoint;
    Size m_size;
    Corner m_corner;
    ShapeType  m_shapeType;
};
