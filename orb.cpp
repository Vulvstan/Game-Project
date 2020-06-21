#include "animatedSprite.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "orb.h"
Orb::Orb(std::vector<float> dim, float vy)
{
    spriteFile = "./resources/orb.png";
    textureRect = sf::IntRect(0, 0, 239, 239);
    x = dim[0] + (dim[2] / 2);
    y = dim[1] + dim[3];
    scale = 0.1;
    width = 10;
    height = 10;
    zrob_sprite();
    velocity_x *= 1.5;
    velocity_y = vy;
}

void Orb::animate(sf::Time &elapsed)
{
    this->sprite.move(0, velocity_y * elapsed.asSeconds());
}
bool Orb::ground_hit()
{
    return this->sprite.getGlobalBounds().top + this->sprite.getGlobalBounds().height >= 850;
}