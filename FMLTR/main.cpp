#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Bouncing DVD Logo", sf::Style::Fullscreen);
    std::string filePath = "download.png"; // put the path in a separate variable

    sf::Texture texture;
    if (!texture.loadFromFile(filePath))// load the texture using the file path
    {
        std::cout << "Failed to load image \"" << filePath << "\"." << std::endl;
        return 1;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);

    float dx = 200.0f;
    float dy = 200.0f;

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