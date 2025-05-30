#pragma once

#include <vector>
#include <memory>

#include "../entities/Basket.h"
#include "../entities/fruit.h"

class Play
{
private:
    // Private Functions
    void init_Variables();
    void init_Entities();

    void spawn_Fruits();

    void reset_Game();

    void change_Sceen();

    void basket_Collect_Fruit();

public:
    // Public Functions

    // Constructor & Destructor
    Play();
    ~Play();

    // Main Play Functions
    void ready();
    void update_Play(float delta_time);
    void draw_Play();

private:
    // Private Members

    // Score
    std::string score_text;

    // Sound
    Sound collection_sound;
    Sound score_loss_sound;

    // Basket
    Basket *basket;

    // Fruit
    Texture2D fruit_texture;
    int fruit_count;
    std::unique_ptr<std::vector<Fruit>> fruits;
};