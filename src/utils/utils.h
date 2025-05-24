#pragma once

#include "../common.h"

namespace MathHelper
{
    template <typename T>
    T max_Value(T value1, T value2)
    {
        return (value1 > value2) ? value1 : value2;
    }

    template <typename T>
    T min_Value(T value1, T value2)
    {
        return (value1 < value2) ? value1 : value2;
    }

    template <typename T>
    T clamp_Value(T value, T min, T max)
    {
        if (value < min)
        {
            return min;
        }
        else if (value > max)
        {
            return max;
        }
        else
        {
            return value;
        }
    }
}