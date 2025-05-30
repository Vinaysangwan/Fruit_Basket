#include "fruit.h"

void Fruit::init_Variables(Sound &score_loss_sound)
{
    // Texture Path of the Fruit Texture
    texture_path = "assets/fruits.png";

    // Fruit Scale
    fruit_scale = Vector2(2.0f, 2.0f);

    // Fruit Size
    fruit_size = Vector2(16.0f * fruit_scale.x, 16.0f * fruit_scale.y);

    // Grid
    if (fruit_size.x != 0 && fruit_size.y != 0)
    {
        total_grid_x = window_width / static_cast<int>(fruit_size.x);
        total_grid_y = window_height / static_cast<int>(fruit_size.y);
    }
    else
    {
        std::cerr << "ERROR: fruit_size is zero!\n";
    }

    // Fruit Texture Rectangle
    random_Fruit();

    // Fruit Position
    random_Position();

    // Fruit Speed
    fruit_speed = 100.0f;

    // Score Loss Sound
    this->score_loss_sound = score_loss_sound;
}

void Fruit::init_Texture(Texture2D &fruit_texture)
{
    this->fruit_texture = fruit_texture;
    this->fruit_texture.width = fruit_size.x * 3;
    this->fruit_texture.height = fruit_size.y * 4;
}

void Fruit::random_Fruit()
{
    fruit_texture_rect = Rectangle(std::rand() % 4 * fruit_size.x, std::rand() % 3 * fruit_size.y, fruit_size.x, fruit_size.y);
}

void Fruit::random_Position()
{
    fruit_position.x = (std::rand() % total_grid_x) * fruit_size.x;
    fruit_position.y = -(std::rand() % 5) * fruit_size.y;
}

void Fruit::move_Fruit(float delta_time)
{
    fruit_position.y += fruit_speed * delta_time;

    if (fruit_position.y >= window_height)
    {
        PlaySound(score_loss_sound);
        score--;
        respawn_Fruit();
    }
}

Fruit::Fruit(Texture2D &fruit_texture, Sound &score_loss_sound)
{
    init_Variables(score_loss_sound);
    init_Texture(fruit_texture);
}

Fruit::~Fruit()
{
}

void Fruit::ready()
{
    respawn_Fruit();
}

void Fruit::update_Fruit(float delta_time)
{
    move_Fruit(delta_time);
}

void Fruit::draw_Fruit()
{
    DrawTextureRec(fruit_texture, fruit_texture_rect, fruit_position, WHITE);
}

void Fruit::respawn_Fruit()
{
    random_Fruit();
    random_Position();
}

Rectangle Fruit::get_Collision_Rect()
{
    return Rectangle(fruit_position.x, fruit_position.y, fruit_size.x, fruit_size.y);
}
