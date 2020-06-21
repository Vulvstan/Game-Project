#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <cmath>
#include <string>
#include "animatedSprite.h"
#include "util.h"
#include "dragon.h"
#include "orb.h"
#include "heroine.h"
#include "misc.h"

#define MENU 0
#define GAME 1
#define END_STATE 2
void display_menu(sf::Font font, sf::RenderWindow *window)
{
    window->draw(*generateText("Mana Catcher", 75, 350, 225, sf::Color::Blue, &font, true));
    window->draw(*generateText(" - Press Enter to start the game - ", 25, 350, 450, sf::Color::White, &font, true));
}
void endState(sf::RenderWindow *window, std::vector<Animated_Sprite *> sprity)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        window->close();
    }

    for (std::vector<Animated_Sprite *>::iterator it = sprity.begin(); it != sprity.end(); ++it)
    {
        (*it)->draw_sprite(window);
    }

}
void alwaysDone(sf::RenderWindow &window, sf::Event event, std::vector<std::unique_ptr<sf::Sprite>> &alwaysDrawn, float &passed, sf::Time elapsed)
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
    for (auto &pointer : alwaysDrawn)
    {
        window.draw(*pointer);
    }
    passed += elapsed.asSeconds();
}

void menuState(int &state, sf::RenderWindow *window, sf::Font font)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        state = 1;
    }
    display_menu(font, window);
}

int main()
{
    srand(time(NULL));
    int state = MENU;
    sf::RenderWindow window(sf::VideoMode(700, 900), "Mana Catcher");
    window.setFramerateLimit(60);
    sf::Clock clock;
    sf::Font font;
    font.loadFromFile("./resources/Middleearth.ttf");
    auto napis_lives = generateText("Lives: ", 24, 20, 0, sf::Color::White, &font, false);

    float passed = 0;
    std::vector<std::unique_ptr<sf::Sprite>> alwaysDrawn;
    alwaysDrawn.emplace_back(skyF());
    alwaysDrawn.emplace_back(cloudsF());
    alwaysDrawn.emplace_back(background1());
    alwaysDrawn.emplace_back(floorF());


    auto icons = generate_icons();

    std::vector<Animated_Sprite *> sprity;
    std::vector<Orb *> orby;
    Dragon dragon(&sprity, &orby);
    Heroine hero;
    sf::Event event;
    auto hearts = lives(hero.get_lives());
    std::vector<std::unique_ptr<sf::Text>> end_text;
    sprity.emplace_back(&hero);
    sprity.emplace_back(&dragon);

    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        alwaysDone(window, event, alwaysDrawn, passed, elapsed);
        switch (state)

        {
        case MENU:
        {
            menuState(state, &window, font);
            break;
        }
        case GAME:
        {

            for (std::vector<Animated_Sprite *>::iterator it = sprity.begin(); it != sprity.end(); ++it)
            {
                (*it)->draw_sprite(&window);
                (*it)->animate(elapsed);
            }
            std::vector<int> to_delete;
            int i = 0;
            for (std::vector<Orb *>::iterator it = orby.begin(); it != orby.end(); ++it)
            {
                if ((*it)->ground_hit())
                {
                    to_delete.emplace_back(i);
                    hero.lose_life();
                    hero.reset_combo();
                    hearts.erase(hearts.end());
                    dragon.decrease_speed();
                }
                if (hero.intersect((*it)->Get_bounds()))
                {
                    hero.add_points(hero.get_multiplier() * 10);
                    to_delete.emplace_back(i);
                    hero.combo_plus();
                    dragon.increase_speed(hero.get_combo());
                    hero.get_combo();
                }
                (*it)->draw_sprite(&window);
                (*it)->animate(elapsed);
                i++;
            }
            i = 0;
            for (auto &pointer : orby)
            {
                if (std::find(to_delete.begin(), to_delete.end(), i) != to_delete.end())
                {
                    delete pointer;
                    pointer = nullptr;
                }
                i++;
            }
            orby.erase(std::remove(orby.begin(), orby.end(), nullptr), orby.end());
            auto napis_points = generateText("X " + std::to_string(hero.get_multiplier()) + "      Points : " + std::to_string(hero.get_points()), 24, 400, 0, sf::Color::White, &font, false);
            window.draw(*napis_points);
            window.draw(*napis_lives);
            for (unsigned int i = 0; i < hearts.size(); i++)
            {
                window.draw(*hearts[i]);
            }
            window.draw(*icons[hero.get_effect_index()]);
            if (hero.dead())
            {
                end_text = generate_end_text(font, hero);
                state = 2;
            }

            break;
        }
        case END_STATE:
        {
            endState(&window, sprity);
            for (auto &pointer : end_text)
            {
                window.draw(*pointer);
            }
            break;
        }
        }
        window.display();
    }
    return 0;
}
