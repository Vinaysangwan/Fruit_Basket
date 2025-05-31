#pragma once

#include "../common.h"
#include "../GameManager.h"
#include "../utils/utils.h"

class Basket
{
private:
    // Private Functions
    void init_Variables();
    void init_Basket();

    void move_Basket(float delta_time);

public:
    // Public Functions

    // Constructor & Destructor
    Basket();
    ~Basket();

    // Main Basket Functions
    void ready();
    void update_Basket(float delta_time);
    void draw_Basket();

    // Return Functions
    Rectangle get_Collision_Rect();

private:
    // Private Members

    // Basket
    Texture2D basket;
    std::string texture_path;

    // Basket Stats
    Vector2 basket_position;
    Vector2 basket_size;
    int basket_speed;
    Vector2 basket_scale;
};