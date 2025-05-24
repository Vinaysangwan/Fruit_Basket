#include "Basket.h"

void Basket::init_Variables(Vector2 basket_size, Vector2 basket_position)
{
    this->basket_size = basket_size;
    this->basket_position = Vector2(basket_position.x - basket_size.x / 2, basket_position.y - basket_size.y / 2);
    this->basket_scale = Vector2(1, 1);
    this->basket_speed = entity_speed;

    this->texture_path = "assets/fruit_basket.png";
}

void Basket::init_Basket()
{
    basket = LoadTexture(texture_path.c_str());
    basket.width = basket_size.x * basket_scale.x;
    basket.height = basket_size.y * basket_scale.y;
}

void Basket::move_Basket(float delta_time)
{
    Vector2 movement(0, 0);

    if (IsKeyDown(KEY_A))
    {
        movement.x = 1;
    }
    else if (IsKeyDown(KEY_D))
    {
        movement.y = 1;
    }

    basket_position.x = MathHelper::clamp_Value(basket_position.x + (movement.y - movement.x) * delta_time * basket_speed, 0.0f, window_width - basket_size.x);
}

Basket::Basket(Vector2 basket_size, Vector2 basket_position)
{
    init_Variables(basket_size, basket_position);
    init_Basket();
}

Basket::~Basket()
{
}

void Basket::update_Basket(float delta_time)
{
    move_Basket(delta_time);
}

void Basket::draw_Basket()
{
    DrawTexture(basket, basket_position.x, basket_position.y, WHITE);
}
