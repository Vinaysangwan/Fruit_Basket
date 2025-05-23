#pragma once

#include "../common.h"
#include "../GameManager.h"

class Play
{
private:
    // Private Functions

    void change_Sceen();

public:
    // Public Functions

    // Constructor & Destructor
    Play();
    ~Play();

    // Main Play Functions
    void update_Play();
    void draw_Play();

private:
    // Private Members
};