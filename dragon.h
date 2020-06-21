#ifndef DRAGON_H
#define DRAGON_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "animatedSprite.h"
#include "orb.h"
class Dragon : public Animated_Sprite
{
public:
    Dragon(std::vector<Animated_Sprite *> *sprity, std::vector<Orb *> *orby);
    std::vector<float> dimensions();
    
    void animate(sf::Time &elapsed);
    void generate_orb();
    void increase_speed(int points);
    void decrease_speed();
    void addAnimation();
    ~Dragon(){};

private:
    std::vector<Animated_Sprite *> *sprity;
    std::vector<Orb *> *orby;
    float timeSinceLastOrb = 0;
    float timer = 1;
    float orb_speed = 200;
    std::vector<sf::IntRect> animations;
    int direction = 4;
};

#endif