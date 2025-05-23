#pragma once

#include "../common.h"
#include "../GameManager.h"
#include "../screens/Home.h"
#include "../screens/Play.h"

class Game
{
private:
    // Private Functions
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

    // Screens
    Home *home;
    Play *play;
};