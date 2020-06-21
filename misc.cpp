#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "util.h"
#include "heroine.h"
std::unique_ptr<sf::Sprite> cloudsF()
{
    return generate_sprite("./resources/clouds.png", sf::IntRect(0, 0, 700, 900), 0, 0, 1, 1);
}
std::unique_ptr<sf::Sprite> floorF()
{
    return generate_sprite("./resources/floor.png", sf::IntRect(0, 0, 700, 50), 0, 850, 1, 1);
}
std::unique_ptr<sf::Sprite> skyF()
{
    return generate_sprite("./resources/sky.png", sf::IntRect(0, 0, 700, 850), 0, 0, 1, 3);
}
std::unique_ptr<sf::Sprite> background1()
{
    return generate_sprite("./resources/far-grounds.png", sf::IntRect(0, 0, 700, 110), 0, 750, 1.136, 1);
}
std::vector<std::unique_ptr<sf::Text>> generate_end_text(sf::Font &font, Heroine hero){
    std::vector<std::unique_ptr<sf::Text>> end_text;
    end_text.emplace_back(generateText("You had to flee from the island", 25, 350, 450, sf::Color::White, &font, true));
    end_text.emplace_back(generateText("yet you managed to collect " + std::to_string(hero.get_points()) + " mana", 25, 350, 480, sf::Color::White, &font, true));
    end_text.emplace_back(generateText(" - Press Esc to close - ", 25, 350, 510, sf::Color::White, &font, true));
    return end_text;
}
std::vector<std::unique_ptr<sf::Sprite>> generate_icons(){
    std::vector<std::unique_ptr<sf::Sprite>> icons;
    icons.emplace_back(generate_sprite("./resources/normal.png", sf::IntRect(0, 0, 60, 60), 320, 0, 25./60., 25./60.));
    icons.emplace_back(generate_sprite("./resources/confused.png", sf::IntRect(0, 0, 60, 60), 320, 0, 25./60., 25./60.));
    icons.emplace_back(generate_sprite("./resources/blessed.png", sf::IntRect(0, 0, 60, 60), 320, 0, 25./60., 25./60.));
    icons.emplace_back(generate_sprite("./resources/swift.png", sf::IntRect(0, 0, 60, 60), 320, 0, 25./60., 25./60.));
    return icons;
}
std::vector<std::unique_ptr<sf::Sprite>> lives(int number_of_lives)
{
    std::vector<std::unique_ptr<sf::Sprite>> hearts;
    for (int i = 0; i < number_of_lives; i++)
    {
        auto heart = std::make_unique<sf::Sprite>();
        heart->setTexture(*wczytaj_texture("./resources/heart.png"));
        heart->setScale(0.055, 0.055);
        heart->setTextureRect(sf::IntRect(0, 0, 511, 511));
        heart->setPosition(100 + i * 40, 0);
        hearts.emplace_back(std::move(heart));
    }
    return hearts;
}
