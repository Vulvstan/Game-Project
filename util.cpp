#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
sf::Texture *wczytaj_texture(std::string spriteFile)
{
    auto texture = new sf::Texture();
    if (!texture->loadFromFile(spriteFile))
    {
        throw "Nie udalo sie wczytac textury z pliku " + spriteFile;
    }
    texture->setRepeated(true);
    return texture;
}
std::unique_ptr<sf::Sprite> generate_sprite(std::string file_name, sf::IntRect tex_rect, float pos_x, float pos_y, float scaleX, float scaleY)
{
//    auto texture = wczytaj_texture(file_name);
//    texture->setRepeated(true);
    auto sprite = std::make_unique<sf::Sprite>();
    sprite->setTexture(*wczytaj_texture(file_name));
    sprite->setScale(scaleX, scaleY);
    sprite->setTextureRect(tex_rect);
    sprite->setPosition(pos_x, pos_y);
    return sprite;
}
std::unique_ptr<sf::Text> generateText(std::string napis, int char_size, int pos_x, int pos_y, sf::Color color, sf::Font *font, bool centered)
{
    auto text = std::make_unique<sf::Text>();
    text->setFont(*font);
    text->setCharacterSize(char_size);
    text->setPosition(pos_x, pos_y);
    text->setFillColor(color);
    text->setString(napis);
    text->setOutlineColor(sf::Color::Black);
    text->setOutlineThickness(3);
    if (centered)
    {
        text->setOrigin(text->getLocalBounds().width / 2, text->getLocalBounds().height / 2);
    }
    return text;
}

int random_int (int mini, int maxi){
    return rand() % (maxi - mini + 1) + mini;

}
