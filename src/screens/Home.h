#pragma once

#include "../components/Button.h"
#include "../GameManager.h"

class Home
{
private:
    // Private Functions
    void init_Variables();
    void init_Buttons();

    void change_Screen();

public:
    // Public Functions

    // Constructor & Destructor
    Home();
    ~Home();

    // Main Home Functions
    void ready();
    void update_Home();
    void draw_Home();

private:
    // Private Members

    // Background Image
    Texture2D home_background;

    // Buttons
    Button *play_button;
    Button *quit_button;
};