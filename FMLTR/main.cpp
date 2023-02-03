#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Bouncing Square", sf::Style::Fullscreen);
    window.setVerticalSyncEnabled(true);

    sf::RectangleShape square(sf::Vector2f(50.0f, 50.0f));
    square.setFillColor(sf::Color::Red);
    square.setOrigin(25.0f, 25.0f);

    sf::Vector2f velocity(100.0f, 100.0f);
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && event.key.repeat == 1))
                window.close();
        }

        sf::Time deltaTime = clock.restart();
        square.move(velocity * deltaTime.asSeconds());

        sf::Vector2u windowSize = window.getSize();
        if (square.getPosition().x + square.getSize().x / 2 > windowSize.x || square.getPosition().x - square.getSize().x / 2 < 0)
            velocity.x = -velocity.x;
        if (square.getPosition().y + square.getSize().y / 2 > windowSize.y || square.getPosition().y - square.getSize().y / 2 < 0)
            velocity.y = -velocity.y;

        window.clear();
        window.draw(square);
        window.display();
    }

    std::cout << "Program terminated." << std::endl;
    return 0;
}
