#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
class Animated_Sprite : public sf::Sprite
{
public:
    void zrob_sprite();
    void draw_sprite(sf::RenderWindow *window);
    void add_animation_frame(sf::IntRect new_animation);
    void set_animation(int number);
    void set_animation_still();
    sf::FloatRect Get_bounds();
    virtual void animate(sf::Time &elapsed) = 0;
    ~Animated_Sprite(){};

protected:
    sf::Sprite sprite;
    float velocity_x = 200;
    float velocity_y = 0;
    int bounds_left = 0;
    int bounds_right = 700;
    float width, height;
    std::string spriteFile;
    sf::IntRect textureRect;
    float x, y, scale = 1;
    std::vector<sf::IntRect> animations;
    bool smooth = false;
    float passed = 0;
private:
};

#endif
