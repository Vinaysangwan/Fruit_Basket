#pragma once

#include "../common.h"
#include "../components/Button.h"
#include "../GameManager.h"

class Home
{
private:
    // Private Functions
    void init_Buttons();

    void change_Screen();

public:
    // Public Functions

    // Constructor & Destructor
    Home();
    ~Home();

    // Main Home Functions
    void update_Home();
    void draw_Home();

private:
    // Private Members

    // Buttons
    Button *play_button;
    Button *quit_button;
};