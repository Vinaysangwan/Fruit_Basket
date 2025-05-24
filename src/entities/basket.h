#pragma once

#include <string.h>

#include "../common.h"
#include "../GameManager.h"
#include "../utils/utils.h"

class Basket
{
private:
    // Private Functions
    void init_Variables(Vector2 basket_size, Vector2 basket_position);
    void init_Basket();

    void move_Basket(float delta_time);

public:
    // Public Functions

    // Constructor & Destructor
    Basket(Vector2 basket_size, Vector2 basket_position);
    ~Basket();

    // Main Basket Functions
    void update_Basket(float delta_time);
    void draw_Basket();

private:
    // Private Members

    // Basket
    Texture2D basket;
    std::string texture_path;

    // Basket Stats
    int basket_speed;
    Vector2 basket_size;
    Vector2 basket_scale;

public:
    // Public Members
    Vector2 basket_position;
};