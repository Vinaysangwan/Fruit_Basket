#include "utils.h"

namespace MathHelper
{
    float get_Center(float position, float size)
    {
        return position - size / 2;
    }

    Vector2 get_CenterV(Vector2 position, Vector2 size)
    {
        return Vector2(get_Center(position.x, size.x), get_Center(position.y, size.y));
    }
}

namespace Conversion
{
    Color hex_RGB(const std::string &hex_value)
    {
        int r = std::stoi(hex_value.substr(1, 2), nullptr, 16);
        int g = std::stoi(hex_value.substr(3, 2), nullptr, 16);
        int b = std::stoi(hex_value.substr(5, 2), nullptr, 16);
        int a = 255;

        return Color(r, g, b, a);
    }

    Color hexa_RGBA(const std::string &hexa_value)
    {
        int r = std::stoi(hexa_value.substr(1, 2), nullptr, 16);
        int g = std::stoi(hexa_value.substr(3, 2), nullptr, 16);
        int b = std::stoi(hexa_value.substr(5, 2), nullptr, 16);
        int a = std::stoi(hexa_value.substr(7, 2), nullptr, 16);

        return Color(r, g, b, a);
    }
}