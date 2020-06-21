#ifndef HEROINE_H
#define HEROINE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "animatedSprite.h"
class Heroine : public Animated_Sprite
{
public:
    Heroine();
    void lose_life() { lives -= 1; }
    int get_lives(){ return lives;}
    bool dead(){return lives == 0;}

    void animate(sf::Time &elapsed);
    void addAnimation();
    void effects(sf::Time &elapsed);
    int get_effect_index() { return effect_index;}
    bool intersect(sf::FloatRect orb)
    {
        return this->Get_bounds().intersects(orb);
    }
    void add_points(int value)
    {
        points += value;
    }
    int get_points()
    {
        return points;
    }
    void combo_plus()
    {
        combo += 1;
        multiplier = (combo / 5) + 1;
    }
    void reset_combo()
    {
        combo = 0;
        multiplier = 1;
    }
    int get_combo()
    {
        return combo;
    }
    int get_multiplier()
    {
        return multiplier;
    }
    ~Heroine(){};

protected:
private:
    float acceleration = 1000;
    int points = 0;
    int lives = 5;
    std::vector<sf::IntRect> animations;
    int combo = 0;
    int multiplier = 1;
    float timer = 0;
    bool reverted = false;
    int effect_index = 0;
};

#endif
