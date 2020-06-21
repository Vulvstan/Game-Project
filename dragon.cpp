#include "dragon.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "orb.h"
Dragon::Dragon(std::vector<Animated_Sprite *> *sprity, std::vector<Orb *> *orby)
{
    spriteFile = "./resources/dragon.png";
    textureRect = sf::IntRect(192, 227, 96, 60);
    x = 0;
    y = 30;
    width = 96;
    height = 62;
    zrob_sprite();
    addAnimation();
    velocity_x *= 1.2;
    this->sprity = sprity;
    this->orby = orby;
    generate_orb();
}

void Dragon::animate(sf::Time &elapsed)

{
    this->sprite.move(velocity_x * elapsed.asSeconds(), 0);
    if (this->sprite.getPosition().x + width >= bounds_right)
    {
        velocity_x = -1 * abs((int)velocity_x);
        direction = 0;
    }
    if (this->sprite.getPosition().x <= bounds_left)
    {
        velocity_x = abs((int)velocity_x);
        direction = 4;
    }
    passed += elapsed.asSeconds();
    this->set_animation((int)(passed * 5) % 4 + direction);
    timeSinceLastOrb += elapsed.asSeconds();
    if (timeSinceLastOrb >= timer)
        generate_orb();
};

std::vector<float> Dragon::dimensions()
{
    std::vector<float> dim;
    dim.emplace_back(this->sprite.getPosition().x);
    dim.emplace_back(this->sprite.getPosition().y);
    dim.emplace_back(this->sprite.getLocalBounds().width);
    dim.emplace_back(this->sprite.getLocalBounds().height);
    return dim;
}
void Dragon::generate_orb()
{
    Orb *orb = new Orb(this->dimensions(), orb_speed);
    orby->emplace_back(orb);
    timeSinceLastOrb = 0;
}
void Dragon::increase_speed(int combo)
{
    if (combo % 3 == 0)
    {
        orb_speed += 30;
        velocity_x *= 1.05;
    }
}
void Dragon::decrease_speed()
{
    if (orb_speed > 200)
        orb_speed -= 30;
    if(std::abs(velocity_x) > 240)
        velocity_x *= (100./105);
}
void Dragon::addAnimation()
{
    for (int i = 0; i < 4; i++)
    {
        this->add_animation_frame(sf::IntRect(i * 96, 129, 96, 62));
    }
    for (int i = 0; i < 4; i++)
    {
        this->add_animation_frame(sf::IntRect(i * 96, 225, 96, 62));
    }
}
