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