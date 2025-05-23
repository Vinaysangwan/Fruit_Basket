#include "Play.h"

void Play::change_Sceen()
{
    if (IsKeyPressed(KEY_ESCAPE))
    {
        e_Screen = home_screen;
    }
}

Play::Play()
{
}

Play::~Play()
{
}

void Play::update_Play()
{
    change_Sceen();
}

void Play::draw_Play()
{
}