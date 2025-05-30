#include "Play.h"

void Play::init_Variables()
{
    // Score Text
    score_text = "SCORE: 0";

    // Collection Sound
    collection_sound = LoadSound("assets/sounds/fruit_collection.mp3");
}

void Play::init_Entities()
{
    // Basket
    basket = new Basket();

    // Fruit
    fruit_texture = LoadTexture("assets/fruits.png");
    score_loss_sound = LoadSound("assets/sounds/point_loss.mp3");

    // Fruits
    fruit_count = 5;
    fruits = std::make_unique<std::vector<Fruit>>();
    spawn_Fruits();
}

void Play::spawn_Fruits()
{
    for (int i = 0; i < 5; i++)
    {
        Fruit *fruit = new Fruit(fruit_texture, score_loss_sound);
        fruits->push_back(*fruit);
    }
}

void Play::change_Sceen()
{
    if (IsKeyPressed(KEY_ESCAPE))
    {

        e_Screen = home_screen;
    }
}

void Play::basket_Collect_Fruit()
{
    for (auto &fruit : *fruits)
    {
        if (CheckCollisionRecs(basket->get_Collision_Rect(), fruit.get_Collision_Rect()))
        {
            PlaySound(collection_sound);
            score++;
            fruit.respawn_Fruit();
        }
    }
}

Play::Play()
{
    init_Variables();
    init_Entities();
}

Play::~Play()
{
    UnloadTexture(fruit_texture);
    UnloadSound(score_loss_sound);
    UnloadSound(collection_sound);

    delete basket;
}

void Play::ready()
{
    score = 0;

    basket->ready();

    for (auto &fruit : *fruits)
    {
        fruit.ready();
    }
}

void Play::update_Play(float delta_time)
{
    change_Sceen();

    basket->update_Basket(delta_time);

    for (auto &fruit : *fruits)
    {
        fruit.update_Fruit(delta_time);
    }

    basket_Collect_Fruit();

    score_text = "SCORE: " + std::to_string(score);
}

void Play::draw_Play()
{
    for (auto &fruit : *fruits)
    {
        fruit.draw_Fruit();
    }

    basket->draw_Basket();

    DrawText(score_text.c_str(), 10, 10, 24, WHITE);
}