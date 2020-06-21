#ifndef ORB_H
#define ORB_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "animatedSprite.h"
class Orb : public Animated_Sprite
{
public:
    Orb(std::vector<float> dim, float vy);
    void animate(sf::Time &elapsed);
    bool ground_hit();
    ~Orb(){};
};

#endif