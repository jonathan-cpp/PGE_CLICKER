#pragma once

//////////////////////////////////////////////////////////
// Standard Library Headers
//////////////////////////////////////////////////////////

#include <iostream>
#include <random>

//////////////////////////////////////////////////////////
// External Library Headers
//////////////////////////////////////////////////////////

#include "olcPixelGameEngine.h"

//////////////////////////////////////////////////////////
// Project Headers
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
// Forward Declarations
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
// Constants and Enums
//////////////////////////////////////////////////////////

namespace Utility 
{
    static constexpr float PI = 3.14159265359f;
    static constexpr float ONE_DEGREE = PI / 180.f;
    static constexpr float ONE_RADIAN = 180.f / PI;

    static std::random_device g_random_device;
    static std::mt19937 g_random_generator(g_random_device());
}

//////////////////////////////////////////////////////////
// Class Declaration
//////////////////////////////////////////////////////////

namespace Utility 
{
    template <typename T>
    inline auto Lerp(const T& current, const T& target, float lerpFactor) {
        return current + (target - current) * lerpFactor;
    };

    template <typename T>
    inline auto Ease(const T& t) {
        return ((6 * t - 15) * t + 10) * t * t * t;
    };

    inline olc::vf2d Normalize(const olc::vf2d& vector) {
        float length = std::hypot(vector.x, vector.y);
        if (length != 0.0f) {
            return olc::vf2d(vector.x / length, vector.y / length);
        }
        return vector; // Avoid division by zero
    }

    inline float Dot(const olc::vf2d& right, const olc::vf2d& left) {
        return right.x * left.x + right.y * left.y;
    }

    inline olc::vf2d Rotate(const olc::vf2d& vec, float angle) {
        return olc::vf2d(std::cos(angle) * vec.x - std::sin(angle) * vec.y, std::sin(angle) * vec.x + std::cos(angle) * vec.y);
    }

    inline float Distance(const olc::vf2d& p1, const olc::vf2d& p2) {
        float dx = p2.x - p1.x;
        float dy = p2.y - p1.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    inline float Length(const olc::vf2d& vec) {
        return std::sqrt(vec.x * vec.x + vec.y * vec.y);
    }

    inline float Radians(float degrees) {
        return degrees * ONE_DEGREE;
    }

    inline float Degrees(float radians) {
        return radians * ONE_RADIAN;
    }

    inline int Random(int a, int b) {
        std::uniform_int_distribution<int> dist(a, b);
        return dist(g_random_generator);
    }

    inline float Random(float a, float b) {
        std::uniform_real_distribution<float> dist(a, b);
        return dist(g_random_generator);
    }

    inline double Random() {
        std::uniform_real_distribution<double> dist(0.0, 1.0);
        return dist(g_random_generator);
    }

    inline olc::Pixel RandomColor() {
        return olc::Pixel(
            static_cast<uint8_t>(Random() * 255.f),
            static_cast<uint8_t>(Random() * 255.f),
            static_cast<uint8_t>(Random() * 255.f), 
            255U
        );
    }
}
