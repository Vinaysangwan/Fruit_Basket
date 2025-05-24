#include "Play.h"

void Play::init_Variables()
{
}

void Play::init_Entities()
{
    // Basket
    basket = new Basket(Vector2(64, 32), Vector2(window_width / 2, window_height - 50));
}

void Play::change_Sceen()
{
    if (IsKeyPressed(KEY_ESCAPE))
    {

        e_Screen = home_screen;
    }
}

Play::Play()
{
    init_Variables();
    init_Entities();
}

Play::~Play()
{
    delete basket;
}

void Play::update_Play(float delta_time)
{
    change_Sceen();

    basket->update_Basket(delta_time);
}

void Play::draw_Play()
{
    basket->draw_Basket();
}