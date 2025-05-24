#pragma once

#include "../entities/Basket.h"

class Play
{
private:
    // Private Functions
    void init_Variables();
    void init_Entities();

    void reset_Game();

    void change_Sceen();

public:
    // Public Functions

    // Constructor & Destructor
    Play();
    ~Play();

    // Main Play Functions
    void update_Play(float delta_time);
    void draw_Play();

private:
    // Private Members

    // Entities
    Basket *basket;
};