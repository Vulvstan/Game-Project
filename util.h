#ifndef UTIL_H
#define UTIL_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
sf::Texture *wczytaj_texture(std::string spriteFile);
std::unique_ptr<sf::Sprite> generate_sprite(std::string file_name, sf::IntRect tex_rect, float pos_x, float pos_y, float scaleX, float scaleY);
std::unique_ptr<sf::Text> generateText(std::string napis, int char_size, int pos_x, int pos_y, sf::Color color, sf::Font *font, bool centered);
int random_int (int mini, int maxi);
#endif
