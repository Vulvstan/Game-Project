#include "animatedSprite.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "util.h"
void Animated_Sprite::zrob_sprite(){
    auto texture_sprite = wczytaj_texture(this->spriteFile);
    texture_sprite->setSmooth(smooth);
    sprite.setTexture(*texture_sprite);
    sprite.setScale(scale, scale);
    sprite.setTextureRect(textureRect);
    sprite.setPosition(x, y);
};

void Animated_Sprite::draw_sprite(sf::RenderWindow *window)
{
    window->draw(sprite);
}
void Animated_Sprite::add_animation_frame(sf::IntRect new_animation)
{
    animations.emplace_back(new_animation);
}
void Animated_Sprite::set_animation(int number)
{
    this->sprite.setTextureRect(animations[number]);
}
void Animated_Sprite::set_animation_still()
{
    this->sprite.setTextureRect(textureRect);
}
sf::FloatRect Animated_Sprite::Get_bounds()
{
    return this->sprite.getGlobalBounds();
}
