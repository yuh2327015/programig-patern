#pragma once
#include <cmath>

const float M_PI = 3.14159265358979323846f;

namespace Transform
{
    struct Vertex
    {
        float x;
        float y;
    };

    struct Vector
    {
        float x_meter;
        float y_meter;
    };

    Vertex MoveVertex(Vertex point, Vector meter) {
        point.x += meter.x_meter;
        point.y += meter.y_meter;
        return point;
    }

    Vertex RotateVertex(Vertex point, float angle_degree) {
        float angle_rad = angle_degree * (M_PI / 180.0f);
        float cos_theta = cos(angle_rad);
        float sin_theta = sin(angle_rad);
        return {
            point.x * cos_theta + point.y * sin_theta,
            -point.x * sin_theta + point.y * cos_theta
        };
    }

    Vertex ScaleVertex(Vertex point, Vector meter) {
        point.x *= meter.x_meter;
        point.y *= meter.y_meter;
        return point;
    }
};
