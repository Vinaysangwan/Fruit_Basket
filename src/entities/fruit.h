#pragma once

#include <string.h>
#include <cstdlib>

#include "../common.h"
#include "../GameManager.h"

class Fruit
{
private:
    // Private Functions
    void init_Variables(Sound &score_loss_sound);
    void init_Texture(Texture2D &fruit_texture);

    void random_Fruit();
    void random_Position();

    void move_Fruit(float delta_time);

public:
    // Public Functions

    // Constructor & Destructor
    Fruit(Texture2D &fruit_texture, Sound &score_loss_sound);
    ~Fruit();

    // Main Fruit Functions
    void ready();
    void update_Fruit(float delta_time);
    void draw_Fruit();
    void respawn_Fruit();

    // Return Functions
    Rectangle get_Collision_Rect();

private:
    // Private Members

    // Fruit
    Texture2D fruit_texture;
    std::string texture_path;

    // Fruit Stats
    Vector2 fruit_position;
    Vector2 fruit_scale;
    Vector2 fruit_size;
    int fruit_speed;
    Rectangle fruit_texture_rect;

    // Grid
    int total_grid_x;
    int total_grid_y;

    // Sound
    Sound score_loss_sound;
};