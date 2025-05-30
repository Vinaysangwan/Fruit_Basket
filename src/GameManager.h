#pragma once

#include "common.h"

enum Mode
{
    home_screen,
    play_screen,
    quit_screen
};

extern Mode e_Screen;
extern Mode e_Previous_Screen;

extern bool screen_change;

extern const int window_width;
extern const int window_height;

extern const int entity_speed;

extern int score;