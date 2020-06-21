#include "heroine.h"
#include "util.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
Heroine::Heroine()
{
    spriteFile = "./resources/hero.png";
    textureRect = sf::IntRect(4, 2, 25, 43);
    scale = 1.5;
    width = 37.5;
    height = 64.5;
    x = (bounds_right - width) / 2;
    y = 785.5;
    velocity_x = 350;
    zrob_sprite();
    addAnimation();
}

void Heroine::animate(sf::Time &elapsed)
{   bool right = (sf::Mouse::isButtonPressed(sf::Mouse::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D));
    bool left = (sf::Mouse::isButtonPressed(sf::Mouse::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A));
    if(reverted){
        auto tmp = right;
        right = left;
        left = tmp;

    }
    velocity_y += acceleration * elapsed.asSeconds();
    if (this->sprite.getPosition().y + height >= 850)
    {
        velocity_y = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->sprite.getPosition().y + height >= 850)
    {
        velocity_y = -400;
    }
    this->sprite.move(0, velocity_y * elapsed.asSeconds());
    if ( left && this->sprite.getPosition().x > bounds_left)
    {
        this->sprite.move(-std::abs(velocity_x * elapsed.asSeconds()), 0);
        passed += elapsed.asSeconds();
        this->set_animation((int)(passed * 5) % 4 + 4);
    }
    else if ( right && this->sprite.getPosition().x + width < bounds_right)
    {
        this->sprite.move(std::abs(velocity_x * elapsed.asSeconds()), 0);
        passed += elapsed.asSeconds();
        this->set_animation((int)(passed * 5) % 4);
    }
    else
    {
        set_animation_still();
    }
    effects(elapsed);

}
void Heroine::effects(sf::Time &elapsed){
    timer += elapsed.asSeconds();
    if(timer >= 5){
        timer = 0;
        if(reverted || acceleration != 1000 || velocity_x != 350){
            reverted = false;
            acceleration = 1000;
            velocity_x = 350;
            effect_index = 0;
        }
        else {
            effect_index = random_int(1,3);
            switch (effect_index) {
            case 1:
                reverted = true;
                break;
            case 2:
                acceleration = 600;
                break;
            case 3:
                velocity_x = 525;
                break;
            }
        }

    }
}
void Heroine::addAnimation(){
        for (int i = 0; i < 4; i++)
    {
        this->add_animation_frame(sf::IntRect(3 + i * 32, 99, 25, 43));
    }
    for (int i = 0; i < 4; i++)
    {
        this->add_animation_frame(sf::IntRect(6 + i * 32, 51, 25, 43));
    }
}
