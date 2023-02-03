#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Bouncing DVD logo", 
        sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    sf::Texture texture;
    texture.loadFromFile("dvd.png");
    sf::Sprite sprite(texture);
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);

    sf::Vector2f direction(5.0f, 5.0f);
    sf::Color color(255, 0, 0);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            {
                if (window.hasFocus())
                    window.close();
            }
        }

        sprite.move(direction);
        if (sprite.getPosition().x + sprite.getLocalBounds().width / 2 >= window.getSize().x || sprite.getPosition().x - sprite.getLocalBounds().width / 2 <= 0)
        {
            direction.x = -direction.x;
            color.r = rand() % 255;
            color.g = rand() % 255;
            color.b = rand() % 255;
            sprite.setColor(color);
        }
        if (sprite.getPosition().y + sprite.getLocalBounds().height / 2 >= window.getSize().y || sprite.getPosition().y - sprite.getLocalBounds().height / 2 <= 0)
        {
            direction.y = -direction.y;
            color.r = rand() % 255;
            color.g = rand() % 255;
            color.b = rand() % 255;
            sprite.setColor(color);
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    std::cout << "Program terminated." << std::endl;

    return 0;
}
