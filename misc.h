#ifndef MISC_H
#define MISC_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "heroine.h"
std::unique_ptr<sf::Sprite> cloudsF();
std::unique_ptr<sf::Sprite> floorF();
std::unique_ptr<sf::Sprite> skyF();
std::unique_ptr<sf::Sprite> background1();
std::vector<std::unique_ptr<sf::Text>> generate_end_text(sf::Font &font, Heroine hero);
std::vector<std::unique_ptr<sf::Sprite>> lives(int number_of_lives);
std::vector<std::unique_ptr<sf::Sprite>> generate_icons();
#endif
