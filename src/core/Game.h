#pragma once

#include "../screens/Home.h"
#include "../screens/Play.h"

class Game
{
private:
    // Private Functions
    void init_Variables();
    void init_Window();
    void init_Screens();

public:
    // Public Functions

    // Constructor & Destructor
    Game();
    ~Game();

    // Main Game Functions
    void update_Game();
    void draw_Game();

    // Return Functions
    bool is_Running();

private:
    // Private Members

    // Time
    float delta_time;

    // Window Icon
    Image window_icon;

    // Background Music
    Music bg_music;

    // Screens
    Home *home;
    Play *play;
};